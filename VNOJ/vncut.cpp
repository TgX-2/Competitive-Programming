const int maxn = 5007;

unsigned short dp[maxn][maxn];
bitset<5002> vis[5007];
ll start=chrono::steady_clock::now().time_since_epoch().count();
int n, m;

int f(int n,int m){
    if (n < m) swap(n, m);
    if (n == m) 
        return 0;
    if (vis[n][m]) 
        return dp[n][m];
    vis[n][m] = 1;
    int g = __gcd(n,m);
    if (g != 1) return dp[n][m] = f(n/g, m/g);
    if (n >= m*3) return dp[n][m] = 1 + f(n-m, m);

    ll cur = chrono::steady_clock::now().time_since_epoch().count();
    if ((cur - start)/1e6 >= 50 and n >= m + 200) 
        return dp[n][m] = 1 + f(n-m, m);

    unsigned short r = 30000;
    int ca = max(1, n/4-6), cb = max(1, m/4-6);
    FORD(i, n / 2, ca)
        mini(r, 1 + f(i, m) + f(n-i, m));
    FORD(i, m / 2, cb)
        mini(r, 1 + f(n, i) + f(n, m-i));
    return dp[n][m] = r;
}

void process() {
    cin >> n >> m;
    if (n < m) swap(n, m);
    FOR(i, 1, 1000) {
        dp[i][1] = dp[1][i] = i-1;
        FOR(j, 2, i - 1) {
            unsigned short *a = dp[j];
            unsigned short *b = dp[i];
            unsigned short  c = 30000;
            FOR(k, 1, i / 2)
                c = min<unsigned short>(c, 1 + a[k] + a[i - k]);
            FOR(k, 1, j / 2) 
                c = min<unsigned short>(c, 1 + b[k] + b[j - k]);
            a[i] = b[j] = c;
        }
    }

    FOR(i, 1, 1000) FOR(j, 1, 1000)
        vis[i][j] = 1;

    cout << f(n, m) + 1;
}

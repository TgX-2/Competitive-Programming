const int maxn = 3007;
const int mod  = 1e9 + 7;
int n, m;

int f[maxn][maxn];
int dp(int i, int j) {
    if (i < 0 or j < 0) return 0;
    if (i == 0 or j == 0) return 1;

    int &ans = f[i][j];
    if (ans != -1) return ans;

    ans = 0;
    (ans += dp(i, j - 1)) %= mod;
    (ans += ((4 * i) % mod * dp(i - 1, j - 1)) % mod) %= mod;
    (ans += (i * (i - 1) / 2 % mod * dp(i - 2, j - 1)) % mod) %= mod;
    (ans += ((i * (j - 1)) % mod * dp(i - 1, j - 2)) % mod) %= mod;
    return ans;
}

void process() {
    cin >> n >> m;
    memo(f, -1);
    cout << (dp(n, m) - 1 + mod) % mod;
}

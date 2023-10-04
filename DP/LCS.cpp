#include<bits/stdc++.h>
using namespace std;
const int N = 1000+5;
int dp[N+5][N+5];

/*
int lcs(string &x, string &y, int n, int m) {
    if(n == 0 || m == 0)return 0;
    if(dp[n][m] != -1)return dp[n][m];
    if(x[n-1] == y[m-1]) return dp[n][m] = 1 + lcs(x, y, n-1, m-1);
    return dp[n][m] = max(lcs(x, y, n, m - 1),
                          lcs(x, y, n - 1, m));
}
*/
int lcs(string &x, string &y, int n, int m) {
    int L[m + 1][n + 1];
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            if(i == 0 || j == 0) L[i][j] = 0;
            else if (x[i - 1] == y[j - 1]) L[i][j] = L[i - 1][j - 1] + 1;
            else L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
    return L[n][m];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        string x, y;
        cin >> x >> y;
        int n, m;
        n = (int)x.size(), m = y.size();
        cout << lcs(x, y, n, m);
    }
    return 0;
}

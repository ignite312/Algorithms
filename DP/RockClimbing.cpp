#include<bits/stdc++.h>
using namespace std;
const int N = 1000+5;
int dp[N+5][N+5], grid[N+5][N+5];
int n, m;

bool inside(int i, int j) {
    if(i < 0 || j < 0 || i >= n || j >= m)return false;
    return true;
}
int solve(int i, int j) {
    if(i == n - 1) return grid[i][j];
    if(dp[i][j] != -1)return dp[i][j];
    int ans = INT_MAX;
    if(inside(i + 1, j)) ans = min(ans, solve(i+1, j) + grid[i][j]);
    if(inside(i + 1, j - 1)) ans = min(ans, solve(i+1, j-1) + grid[i][j]);
    if(inside(i + 1, j + 1)) ans = min(ans, solve(i+1, j+1) + grid[i][j]);

    return dp[i][j] = ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        cin >> n >> m;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> grid[i][j];
        int ans = INT_MAX;
        for(int i = 0; i < m; i++)
            ans = min(ans, solve(0, i));
        cout << ans << "\n";
    }
    return 0;
}

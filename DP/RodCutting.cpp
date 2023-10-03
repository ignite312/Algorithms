#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
const int N = 1000+5;
int dp[N+5][N+5];
int n;

int rodCutMemoization(vector<int> &price, int idx, int length) {
    if(idx == 0)return 0;
    int notCut = rodCutMemoization(price, idx-1, length);
    int cut = INT_MIN;
    if(idx <= length)cut = price[idx] + rodCutMemoization(price, idx, length - idx);
    return max(cut, notCut);
}
int rodCutDp(vector<int> &price, int idx, int length) {
    if(idx == 0)return 0;
    if (dp[idx][length] != -1)
        return dp[idx][length];
    int notCut = rodCutDp(price, idx-1, length);
    int cut = INT_MIN;
    if(idx <= length)cut = price[idx] + rodCutDp(price, idx, length - idx);
    return dp[idx][length] = max(cut, notCut);
}
int rodCutIterative(vector<int> &price, int length) {
    int dp2[N+5];
    dp2[0] = 0;
    for(int len = 1; len <= length; len++) {
        int maxCost = INT_MIN;
        for(int cut = 1; cut <= len; cut++)maxCost = max(maxCost, price[cut] + dp2[len - cut]);
        dp2[len] = maxCost;
    }
    return dp2[length];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        cin >> n;
        vector<int> price(n+1);
        for(int i = 1; i <= n; i++)cin >> price[i];

        // Normal Recursion
        cout << "Normal Recursion\n";
        auto start_time = high_resolution_clock::now();
        cout << rodCutMemoization(price, n, n) << "\n";
        auto end_time = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end_time - start_time);
        cout << "Total runtime: " << duration.count() << " microseconds\n\n";

        // Dp Memoization
        cout << "Dp Memoization\n";
        start_time = high_resolution_clock::now();
        cout << rodCutDp(price, n, n) << "\n";
        end_time = high_resolution_clock::now();
        duration = duration_cast<microseconds>(end_time - start_time);
        cout << "Total runtime: " << duration.count() << " microseconds\n\n";
        
        // Dp iterative
        cout << "Dp Iterative\n";
        start_time = high_resolution_clock::now();
        cout << rodCutIterative(price, n) << "\n";
        end_time = high_resolution_clock::now();
        duration = duration_cast<microseconds>(end_time - start_time);
        cout << "Total runtime: " << duration.count() << " microseconds\n\n";
    }
    return 0;
}

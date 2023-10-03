#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
const int N = 1000+5;
int dp[N+5][N+5];

/*
int knapSack(int n, int w, vector<int> &wt, vector<int> &pt) {
    if (n == 0 || w == 0)
        return 0;
    if (wt[n - 1] > w)
    	return knapSack(n-1, w, wt, pt);
    else return max(
        	knapSack(n-1, w, wt, pt), 
        	pt[n - 1] + knapSack(n-1, w - wt[n - 1], wt, pt));
}
*/
int knapSack(int idx, int W, vector<int> &wt, vector<int> &pt) {
    if(idx < 0) return 0;
    if(dp[idx][W] != -1) return dp[idx][W];

    if (wt[idx] > W) 
    	return dp[idx][W] = knapSack(idx-1, W, wt, pt);
    else
    	return dp[idx][W] = max(knapSack(idx-1, W, wt, pt), 
        	pt[idx] + knapSack(idx-1, W - wt[idx], wt, pt));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
    	int n, w;
        cin >> n >> w;
        vector<int> wt(n), pt(n);
        for(int i = 0; i < n; i++)cin >> wt[i];
        	for(int i = 0; i < n; i++)cin >> pt[i];
        cout << knapSack(n, w, wt, pt);
    }
    return 0;
}

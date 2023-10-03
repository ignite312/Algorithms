#include<bits/stdc++.h>
using namespace std;
const int N = 1000+5;
const int INF = INT_MAX;
int dp[N+5][N+5];

int lis(int n, vector<int> &arr) {
	vector<int> d(n+1, INF);
	d[0] = -INF;
	for(int i = 0; i < n; i++) {
		int idx = lower_bound(d.begin(), d.end(), arr[i]) - d.begin();
		d[idx] = arr[i];
	}
	int ans = 1;
	for(int i = 1; i <= n; i++)if(d[i] < INF)ans = i;
	return ans;
}
int lisBottomUp(int n, vector<int> &arr) {
	vector<int> d(n, 1);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < i; j++)
			if(arr[j] < arr[i])
				d[i] = max(d[i], d[j]+1);
	int ans = 1;
	for(int i = 0; i < n; i++) ans = max(ans, d[i]);
	return ans;
}
/*** Taken from cp-algo ***/
vector<int> lis(vector<int> const& a) {
    int n = a.size();
    vector<int> d(n, 1), p(n, -1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && d[i] < d[j] + 1) {
                d[i] = d[j] + 1;
                p[i] = j;
            }
        }
    }
    int ans = d[0], pos = 0;
    for (int i = 1; i < n; i++) {
        if (d[i] > ans) {
            ans = d[i];
            pos = i;
        }
    }
    vector<int> subseq;
    while (pos != -1) {
        subseq.push_back(a[pos]);
        pos = p[pos];
    }
    reverse(subseq.begin(), subseq.end());
    return subseq;
}
int lisTopDown(int idx, int last_idx, int n, vector<int> &arr) {
	if(idx == n)return 0;
	if(dp[idx][last_idx+1] != -1)return dp[idx][last_idx+1];

	int take = INT_MIN;
	if(last_idx == -1 || arr[last_idx] < arr[idx]) 
	take = 1 + lisTopDown(idx+1, idx, n, arr);
	int not_take = 0 + lisTopDown(idx+1, last_idx, n, arr);
	return dp[idx][last_idx+1] = max(take, not_take);
}
int lisRecursion(int n, vector<int> &arr) {
	memset(dp, -1, sizeof(dp));
    return lisTopDown(0, -1, n, arr);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	tt = 1;
	// cin >> tt;
	while(tt--) {
		int n;
		cin >> n;
		vector<int> arr(n);
		for(int i = 0; i < n; i++)cin >> arr[i];
		lisBottomUp(n, arr);
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ff first
#define ss second

bool comparex(pii a, pii b) {return a.first < b.first;}
bool comparey(pii a, pii b) {return a.second < b.second;}
int dist(pii x, pii y){return (x.ff-y.ff)*(x.ff-y.ff) + (x.ss-y.ss)*(x.ss-y.ss);}

pair<pii, pii> closestAmongThree(pii a, pii b, pii c) {
	int d1 = dist(a, b);
	int d2 = dist(b, c);
	int d3 = dist(a, c);
	int mn = min({d1, d2, d3});
	if(mn == d1)return {a, b};
	else if(mn == d2)return {b, c};
	else return {a, c};

}
pair<pii, pii> closest(vector<pii> &points, int st, int en) {
	if(st + 1 == en) return {points[st], points[en]};
	if(st + 2 == en) return closestAmongThree(points[st], points[st+1], points[en]);

	int mid = st + (en - st)/2;

	pair<pii, pii> left = closest(points, st, mid);
	pair<pii, pii> right = closest(points, mid+1, en);
	int left_d = dist(left.ff, left.ss);
	int right_d = dist(right.ff, right.ss);
	int d = min(left_d, right_d);
	pair<pii, pii> ans;
	ans = (d == left_d) ? left : right;

	vector<pii> middle;
    for(int i = st; i <= en; i++)
    	if(dist(points[i], points[mid]) < d)
    		middle.push_back(points[i]);
    sort(middle.begin(), middle.end(), comparey);

    for(int i = 0; i < middle.size(); i++){
        for(int j = i+1; j < middle.size() and j <= i + 7; j++){
            int dst = dist(points[i], points[j]);
            if(dst < d){
                ans = {points[i], points[j]};
                d = dst;
            }
        }
    }
    middle.clear();

    return ans;
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
        vector<pii> points(n);
        for(int i = 0; i < n; i++) {
        	cin >> points[i].first >> points[i].second;
        }
        sort(points.begin(), points.end(), comparex);
        pair<pii, pii> ans = closest(points, 0, n-1);
        cout << sqrt(dist(ans.ff, ans.ss));
    }
    return 0;
}

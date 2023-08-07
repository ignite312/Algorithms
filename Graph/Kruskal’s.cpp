#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
vector<tuple<int, int, int>> G;
int parent[N+5], Size[N+5];

void make_set(int v) {
    parent[v] = v;
    Size[v] = 1;
}
int find_set(int v) {
    if (v == parent[v])return v;
    return parent[v] = find_set(parent[v]);
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if(Size[a] < Size[b])swap(a, b);
        parent[b] = a;
        Size[a]+=Size[b];
    }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  tt = 1;
  while(tt--) {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int wt, u, v;
        cin >> wt >> u >> v;
        G.emplace_back(wt, u, v);
    }
    sort(G.begin(), G.end());
    for(int i = 0; i <= n; i++)make_set(i);
    vector<pair<int, int>> MST;
    int ans = 0;
    for(auto[wt, u, v] : G) {
        if(find_set(u) != find_set(v)) {
            union_sets(u, v);
            ans+=wt;
            MST.emplace_back(u, v);
        }
    }
    cout << ans << "\n";
  }
}
// 15 14
// 1 7	6
// 2 8	2
// 2 6	5
// 4 0	1
// 4 2	5
// 6 8	6
// 7 2	3
// 7 7	8
// 8 0	7
// 8 1	2
// 9 3	4
// 10 5 4
// 11 1 7
// 14 3 5
//ans = 37

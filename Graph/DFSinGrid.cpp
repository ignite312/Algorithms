#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 5;
char grid[N+5][N+5];
bool visited[N+5][N+5];
int n, m;

bool walkable(int i, int j) {
    if(i < 1 || j < 1 || i > n || j > m)return false;
    if(visited[i][j])return false;
    if(grid[i][j] == '#')return false;
    return true;
} 
void dfs(int i, int j) {
    visited[i][j] = true;
    if(walkable(i+1, j))dfs(i+1, j);
    if(walkable(i-1, j))dfs(i-1, j);
    if(walkable(i, j+1))dfs(i, j+1);
    if(walkable(i, j-1))dfs(i, j-1);
    return;
}
int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> grid[i][j];
        }
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(visited[i][j] || grid[i][j] == '#')continue;
            dfs(i, j);
            cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
} 

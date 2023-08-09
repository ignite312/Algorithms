#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    list<int>* adj;
public:
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }
    ~Graph() { delete[] adj; }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void rmvEdge(int u, int v);
    void EulerTour();
    void printEuler(int s);
    int dfsCount(int v, bool visited[]);
    bool isValidNextEdge(int u, int v);
};
void Graph::EulerTour() {
    int u = 0;
    for (int i = 0; i < V; i++)
        if (adj[i].size() & 1) {
            u = i;
            break;
        }
    printEuler(u);
    cout << endl;
}
void Graph::printEuler(int u) {
    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i) {
        int v = *i;

        if (v != -1 && isValidNextEdge(u, v)) {
            cout << u << "-" << v << " ";
            rmvEdge(u, v);
            printEuler(v);
        }
    }
}
bool Graph::isValidNextEdge(int u, int v) {
    int count = 0;
    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i)
        if (*i != -1)
            count++;
    if (count == 1)
        return true;

    bool visited[V];
    memset(visited, false, V);
    int count1 = dfsCount(u, visited);

    rmvEdge(u, v);
    memset(visited, false, V);
    int count2 = dfsCount(u, visited);

    addEdge(u, v);

    return (count1 > count2) ? false : true;
}
void Graph::rmvEdge(int u, int v) {
    list<int>::iterator iv
        = find(adj[u].begin(), adj[u].end(), v);
    *iv = -1;

    list<int>::iterator iu
        = find(adj[v].begin(), adj[v].end(), u);
    *iu = -1;
}
int Graph::dfsCount(int v, bool visited[]) {
    visited[v] = true;
    int count = 1;
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (*i != -1 && !visited[*i])
            count += dfsCount(*i, visited);

    return count;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    while(tt--) {
        int n, m;
        cin >> n >> m;
        Graph g(n);
        for(int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            g.addEdge(u, v);
        }
        g.EulerTour();
    }
    return 0;
}
// 5 8
// 1 0
// 0 2
// 2 1
// 0 3
// 3 4
// 3 2
// 3 1
// 2 4
// 0-1 1-2 2-0 0-3 3-4 4-2 2-3 3-1 ans
// https://www.geeksforgeeks.org/fleurys-algorithm-for-printing-eulerian-path/

#include <bits/stdc++.h>
using namespace std;
#define NIL -1
int Count = 0;
vector<vector<pair<int, int>>> components;

class Edge {
public:
    int u;
    int v;
    Edge(int u, int v);
};
Edge::Edge(int u, int v) {
    this->u = u;
    this->v = v;
}
class Graph {
    int V; 
    int E;
    list<int>* adj; 

    void BCCUtil(int u, int disc[], int low[],
        list<Edge>* st, int parent[]);

public:
    Graph(int V);
    void addEdge(int v, int w);
    void BCC();
};
Graph::Graph(int V) {
    this->V = V;
    this->E = 0;
    adj = new list<int>[V];
}
void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v);
    E++;
}
void Graph::BCCUtil(int u, int disc[], int low[], list<Edge>* st,
    int parent[]) {
    static int time = 0;

    disc[u] = low[u] = ++time;
    int children = 0;
    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i) {
        int v = *i;

        if (disc[v] == -1) {
            children++;
            parent[v] = u;
            st->push_back(Edge(u, v));
            BCCUtil(v, disc, low, st, parent);
            low[u] = min(low[u], low[v]);
            vector<pair<int, int>> component;
            if ((disc[u] == 1 && children > 1) || (disc[u] > 1 && low[v] >= disc[u])) {
                vector<pair<int, int>> ans;
                while (st->back().u != u || st->back().v != v) {
                    int a = st->back().u;
                    int b = st->back().v;
                    if(a > b)swap(a, b);
                    component.emplace_back(a, b);
                    st->pop_back();
                }
                int a = st->back().u;
                int b = st->back().v;
                if(a > b)swap(a, b);
                component.emplace_back(a, b);
                sort(component.begin(), component.end());
                components.push_back(component);
                st->pop_back();
                Count++;
            }
        }
        else if (v != parent[u]) {
            low[u] = min(low[u], disc[v]);
            if (disc[v] < disc[u]) {
                st->push_back(Edge(u, v));
            }
        }
    }
}
void Graph::BCC() {
    int* disc = new int[V];
    int* low = new int[V];
    int* parent = new int[V];
    list<Edge>* st = new list<Edge>[E];
    for (int i = 0; i < V; i++) {
        disc[i] = NIL;
        low[i] = NIL;
        parent[i] = NIL;
    }
    for (int i = 0; i < V; i++) {
        if (disc[i] == NIL)
            BCCUtil(i, disc, low, st, parent);

        int j = 0;
        vector<pair<int, int>> component;
        while (st->size() > 0) {
            j = 1;
            int a = st->back().u;
            int b = st->back().v;
            if(a > b)swap(a, b);
            component.emplace_back(a, b);
            st->pop_back();
        }
        if (j == 1) {
            sort(component.begin(), component.end());
            components.push_back(component);
            Count++;
        }
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
        Graph g(n);
        for(int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            g.addEdge(u, v);
        }
        g.BCC();
        sort(components.begin(), components.end());
        for(int i = 0; i < components.size(); i++) {
            for(int j = 0; j < components[i].size(); j++) {
                cout << components[i][j].first << " " << components[i][j].second << "\n";
            }
            if(i < components.size() - 1)cout << "-\n";
        }
    }
    return 0;
}
// 6
// 5
// 1 3
// 1 2
// 0 1
// 3 2
// 2 5
// https://www.geeksforgeeks.org/biconnected-components/

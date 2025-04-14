#include <bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int>> &graph, int node, vector<bool> &visited, vector<int> &dfs_result) {
    visited[node] = true;
    dfs_result.push_back(node);
    
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            DFS(graph, neighbor, visited, dfs_result);
        }
    }
}

vector<int> BFS(vector<vector<int>> &graph, int start) {
    vector<int> bfs_result;
    vector<bool> visited(graph.size(), false);
    queue<int> q;
    
    visited[start] = true;
    q.push(start);
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        bfs_result.push_back(node);
        
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    
    return bfs_result;
}

void addEdge(vector<vector<int>> &graph, int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> graph(n);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(graph, u, v);
    }
    
    vector<bool> visited(n, false);
    vector<int> dfs_result;
    DFS(graph, 0, visited, dfs_result);
    
    vector<int> bfs_result = BFS(graph, 0);
    
    cout << "DFS: ";
    for (int node : dfs_result) cout << node << " ";
    cout << "\n";
    
    cout << "BFS: ";
    for (int node : bfs_result) cout << node << " ";
    cout << "\n";
    
    return 0;
}

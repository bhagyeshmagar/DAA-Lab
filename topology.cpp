//Bhagyesh Magar RBT23CB021
#include <bits/stdc++.h>
using namespace std;

void DFS(int v, vector<bool> &visited, stack<int> &st, vector<vector<int>> &adj) {
    visited[v] = true;
    for (int i : adj[v]) {
        if (!visited[i]) {
            DFS(i, visited, st, adj);
        }    
    }
    st.push(v);
}

void topologicalSort(int V, vector<vector<int>> &adj) {
    stack<int> st;
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            DFS(i, visited, st, adj);
        }
    }
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << "\n";
}

int main() {
    if (!freopen("in.txt", "r", stdin)) {  // Ensure "in.txt" exists for input
        cerr << "Error: Input file 'in.txt' not found.\n";
        return 1;
    }

    int N, M;
    cin >> N >> M;
    if (N <= 0 || M < 0) {
        cerr << "Error: Invalid number of vertices or edges.\n";
        return 1;
    }

    vector<vector<int>> adj(N);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        if (a < 0 || a >= N || b < 0 || b >= N) {
            cerr << "Error: Invalid edge (" << a << ", " << b << ").\n";
            return 1;
        }
        if (a == b) {  // Prevent self-loops
            cerr << "Error: Self-loops are not allowed (" << a << ", " << b << ").\n";
            return 1;
        }
        adj[a].push_back(b);
    }

    cout << "Topological Sort of the given graph: ";
    topologicalSort(N, adj);
    
    return 0;
}

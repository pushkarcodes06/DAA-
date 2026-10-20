#include <bits/stdc++.h>
using namespace std;
 
// Can vertex v be placed at position pos of the path?
bool isSafe(int v, vector<vector<int>> &graph, vector<int> &path, int pos) {
    // 1. v must be adjacent to the previously placed vertex
    if (graph[path[pos - 1]][v] == 0) return false;
 
    // 2. v must not already be in the path
    for (int i = 0; i < pos; i++) {
        if (path[i] == v) return false;
    }
    return true;
}
 
bool hamiltonianCycle(int pos, vector<vector<int>> &graph, vector<int> &path,
                      int n) {
    if (pos == n) {
        // all vertices placed: last vertex must connect back to the first
        return graph[path[n - 1]][path[0]] == 1;
    }
 
    for (int v = 1; v < n; v++) {          // vertex 0 is already the start
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;                 // choose
            if (hamiltonianCycle(pos + 1, graph, path, n)) return true;
            path[pos] = -1;                // un-choose (backtrack)
        }
    }
    return false;
}
 
int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;
 
    vector<vector<int>> graph(n, vector<int>(n));
    cout << "Enter the " << n << "x" << n << " adjacency matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];
 
    vector<int> path(n, -1);
    path[0] = 0;                           // fix the start at vertex 0
 
    if (hamiltonianCycle(1, graph, path, n)) {
        cout << "Hamiltonian cycle: ";
        for (int i = 0; i < n; i++) cout << path[i] << " ";
        cout << path[0] << endl;           // return to the start
    } else {
        cout << "No Hamiltonian cycle exists." << endl;
    }
 
    return 0;
}

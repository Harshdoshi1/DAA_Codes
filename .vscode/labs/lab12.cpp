// #include <iostream>
// #include <vector>
// #include <queue>
// using namespace std;

// void BFS(int start, const vector<vector<int>>& graph) {
//     int n = graph.size();
//     vector<bool> visited(n, false);
//     queue<int> q;
//     visited[start] = true;
//     q.push(start);
//     cout << "BFS Traversal: ";
//     while (!q.empty()) {
//         int node = q.front();
//         q.pop();
//         cout << node << " ";
//         for (int neighbor : graph[node]) {
//             if (!visited[neighbor]) {
//                 visited[neighbor] = true;
//                 q.push(neighbor);
//             }
//         }
//     }
//     cout << endl;
// }

// int main() {
//     vector<vector<int>> graph = {
//         {1, 2},
//         {0, 3, 4},
//         {0, 4},
//         {1, 5},
//         {1, 2, 5},
//         {3, 4}
//     };
//     int startNode = 0;
//     BFS(startNode, graph);
//     return 0;
// }

#include <iostream>
#include <vector>
using namespace std;

void DFSUtil(int node, const vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            DFSUtil(neighbor, graph, visited);
        }
    }
}

void DFS(int start, const vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> visited(n, false);
    cout << "DFS Traversal: ";
    DFSUtil(start, graph, visited);
    cout << endl;
}

int main() {
    vector<vector<int>> graph = {
        {1, 2},
        {0, 3, 4},
        {0, 4},
        {1, 5},
        {1, 2, 5},
        {3, 4}
    };
    int startNode = 0;
    DFS(startNode, graph);
    return 0;
}


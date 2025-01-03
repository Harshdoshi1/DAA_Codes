#include <iostream>
#include <vector>
#include <queue>
#include <climits>

// taken reference code from lab 13 :)
using namespace std;

void dijkstra(int start, int end, int numNodes, const vector<vector<pair<int, int>>>& graph) {
    vector<int> dist(numNodes, INT_MAX);  
    vector<int> parent(numNodes, -1);    
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int currentDist = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();

        if (currentDist > dist[currentNode]) continue;

        for (const auto& edge : graph[currentNode]) {
            int newDist = currentDist + edge.second;
            if (newDist < dist[edge.first]) {
                dist[edge.first] = newDist;
                parent[edge.first] = currentNode;
                pq.push({newDist, edge.first});
            }
        }
    }

    if (dist[end] == INT_MAX) {
        cout << "No path from " << start << " to " << end << endl;
        return;
    }

    cout << "Shortest distance from " << start << " to " << end << " is " << dist[end] << endl;

    vector<int> path;
    for (int node = end; node != -1; node = parent[node]) {
        path.push_back(node);
    }

    cout << "Shortest path: ";
    for (int i = path.size() - 1; i >= 0; --i) {
        cout << path[i] << (i > 0 ? " -> " : "\n");
    }
}

int main() {
    int numNodes = 5; 
    vector<vector<pair<int, int>>> graph(numNodes);

    graph[0].push_back({1, 3});
    graph[0].push_back({3, 7});
    graph[0].push_back({4, 8});
    graph[1].push_back({3, 4});
    graph[1].push_back({2, 1});
    graph[3].push_back({2, 2});
    graph[4].push_back({3, 3});

    int start = 0, end = 2;
    dijkstra(start, end, numNodes, graph);

    return 0;
}

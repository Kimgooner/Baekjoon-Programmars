#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
using namespace std;

int T;
bool visited[105];

int getManhattan(pair<int,int> a, pair<int,int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

bool dfs(vector<int> edges[], vector<pair<int,int>> &graph, int target) {
    stack<int> nodes;
    nodes.push(1);
    visited[1] = true;

    while (!nodes.empty()) {
        int x = nodes.top();
        nodes.pop();

        if (x == target) {
            return true;
        }

        for (int v : edges[x]) {
            if (!visited[v] && getManhattan(graph[x], graph[v]) <= 1000) {
                visited[v] = true;
                nodes.push(v);
            }
        }
    }
    return false;
}

int main() {
    cin >> T;

    int cons;
    for (int i = 0; i < T; i++) {
        cin >> cons;

        fill(visited, visited+105, false);
        vector<pair<int,int>> graph;
        graph.emplace_back(0, 0);
        int x, y;
        for (int j = 0; j < 2+cons; j++) {
            cin >> x >> y;
            graph.emplace_back(x, y);
        }

        int n = graph.size();
        vector<int> edges[n];
        for (int i = 1; i <= n-1; i++) {
            for (int j = 1; j <= n-1; j++) {
                edges[i].push_back(j);
            }
        }
        if (dfs(edges, graph, 2+cons)) cout << "happy\n";
        else cout << "sad\n";
    }
}
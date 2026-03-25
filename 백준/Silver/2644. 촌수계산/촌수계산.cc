#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, E;
int a, b;

vector<int> edges[101];
bool visited[101];

int bfs(int start, int target) {
    queue<pair<int,int>> node;
    node.emplace(start, 0);
    visited[start] = true;

    while (!node.empty()) {
        int v = node.front().first;
        int dist = node.front().second;
        node.pop();

        if (v == target) {
            return dist;
        }

        for (int next : edges[v]) {
            if (!visited[next]) {
                visited[next] = true;
                node.emplace(next, dist + 1);
            }
        }
    }
    return -1;
}

int main() {
    cin >> N;
    cin >> a >> b;

    cin >> E;

    int s, e;
    for (int i = 0; i < E; i++) {
        cin >> s >> e;
        edges[s].push_back(e);
        edges[e].push_back(s);
    }

    cout << bfs(a, b);
}

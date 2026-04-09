#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    vector<int> e[n+1];
    for(vector<int> v : edge){
        e[v[0]].push_back(v[1]);
        e[v[1]].push_back(v[0]);
    }
    
    vector<int> dist(n+1, 1e9);
    vector<bool> visited(n+1, false);
    
    int start = 1;
    dist[start] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, start});
    
    while(!pq.empty()){
        int cur_dist = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();
        
        if(dist[cur_node] < cur_dist) continue;
        
        for(int n : e[cur_node]){
            if(visited[n]) continue;
            int next_dist = cur_dist + 1;
            int next_node = n;
            if(dist[next_node] < next_dist) continue;
            visited[n] = true;
            dist[next_node] = next_dist;
            pq.push({next_dist, next_node});
        }
    }
    
    int max_node = -1;
    for(int i = 1; i <= n; i++){
        max_node = max(max_node, dist[i]);
    }
    for(int i = 1; i <= n; i++){
        if(dist[i] == max_node) answer++;
    }
    
    return answer;
}
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int INF = 1e9;
int solution(int N, vector<vector<int>> road, int K) {
    vector<pair<int,int>> graph[N+1];
    for(auto &edge : road){
        int s = edge[0];
        int e = edge[1];
        int cost = edge[2];
        graph[s].emplace_back(e, cost);
        graph[e].emplace_back(s, cost);
    }
    
    vector<int> dist(N+1, INF);
    dist[1] = 0;
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push(make_pair(0, 1));
    
    while(!pq.empty()){
        int cur_dist = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        if(dist[cur] < cur_dist) continue;
        
        for(auto &next : graph[cur]){
            int next_node = next.first;
            int next_cost = cur_dist + next.second;
            
            if(next_cost < dist[next_node]){
                dist[next_node] = next_cost;
                pq.push(make_pair(next_cost, next_node));
            }
        }
    }
    
    int answer = 0;
    for(int i = 1; i <= N; i++){
        if(dist[i] <= K) answer++;
    }
    return answer;
}
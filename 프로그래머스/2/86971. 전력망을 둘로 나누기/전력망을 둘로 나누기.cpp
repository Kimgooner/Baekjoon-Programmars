#include <string>
#include <vector>
#include <cmath>
#include <stack>
#include <algorithm>

using namespace std;

bool visited[105];
vector<int> edges[105];
int checkTree(int p){
    int count = 0;
    stack<pair<int,int>> s;
    s.push(make_pair(p, 0));
    visited[p] = true;
    
    while(!s.empty()){
        int cur = s.top().first;
        int cur_depth = s.top().second;
        s.pop();
        count++;
        
        for(int i : edges[cur]){
            if(!visited[i]){
                visited[i] = true;
                s.push(make_pair(i, cur_depth+1));
            }
        }
    }
    return count;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 1e9;
    
    for(vector<int> v : wires){
        edges[v[0]].push_back(v[1]);
        edges[v[1]].push_back(v[0]);
    }
    
    for(int i = 0; i < wires.size(); i++){
        int a = wires[i][0];
        int b = wires[i][1];
        edges[a].erase(remove(edges[a].begin(), edges[a].end(), b), edges[a].end());
        edges[b].erase(remove(edges[b].begin(), edges[b].end(), a), edges[b].end());
        
        fill(visited, visited+100, false);
        int a_depth = checkTree(a);
        fill(visited, visited+100, false);
        int b_depth = checkTree(b);
        
        answer = min(answer, abs(a_depth - b_depth));
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    
    return answer;
}
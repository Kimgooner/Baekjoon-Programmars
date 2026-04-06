#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

bool isConnected(string s1, string s2){
    int diff = 0;
    for(int i = 0; i < s1.size(); i++){
        if(s1[i] != s2[i]) diff++;
        if(diff > 1) return false;
    }
    if(diff == 1) return true;
    return false;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    int n = words.size();
    vector<bool> visited(n+1, false);
    vector<int> edges[n+1];
    
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(isConnected(words[i], words[j])){
                edges[i].push_back(j);
                edges[j].push_back(i);
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        if(isConnected(begin, words[i])){
            edges[n].push_back(i);
            edges[i].push_back(n);
        }
    }
    
    queue<pair<int,int>> q;
    q.push({n, 0});
    visited[n] = true;
    
    while(!q.empty()){
        int cur = q.front().first;
        int cur_result = q.front().second;
        q.pop();
        
        if(cur != n && words[cur] == target) return cur_result;
        
        for(int next : edges[cur]){
            if(visited[next]) continue;
            visited[next] = true;
            q.push({next, cur_result+1});
        }
    }    
    
    return 0;
}
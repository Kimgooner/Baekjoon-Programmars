#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

//노드 방문 x 경로 방문 o

vector<string> answer;
map<string, vector<pair<string, int>>> conn;

void print(vector<string> v){
    for(string s : v){
        cout << s << " ";
    }
    cout << "\n";
}

void dfs(string start, int depth, int target, vector<bool> &visited, vector<string> &buffer){
    if(depth == target){
        answer = buffer;
    }
    for(auto p : conn[start]){
        string next = p.first;
        int edgeIdx = p.second;
        if(!visited[edgeIdx]){
            buffer.push_back(next);
            visited[edgeIdx] = true;
            dfs(next, depth+1, target, visited, buffer);
            buffer.pop_back();
            visited[edgeIdx] = false;
        }
    }
    return;
}

bool cmp(pair<string,int> p1, pair<string,int> p2){
    return p1.first > p2.first;
}

vector<string> solution(vector<vector<string>> tickets) {
    for(int i = 0 ; i < tickets.size(); i++){
        string start = tickets[i][0];
        string end = tickets[i][1];
        
        conn[start].push_back({end, i});
    }
    
    for(auto &p : conn){
        sort(p.second.begin(), p.second.end(), cmp);
    }
    
    int size = tickets.size();
    int target = size + 1; // 모든 티켓 사용 -> 티켓 수만큼 방문 + 초기값("ICN")
    vector<bool> visited(size, false);
    
    vector<string> buffer;
    buffer.push_back("ICN");
    dfs("ICN", 1, target, visited, buffer);
    
    return answer;
}
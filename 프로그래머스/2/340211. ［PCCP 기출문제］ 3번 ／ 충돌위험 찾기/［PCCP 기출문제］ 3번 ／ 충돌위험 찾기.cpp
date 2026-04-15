#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int map[101][101];
bool done[101];

int getCollide(){
    int result = 0;
    for(int i = 1; i <= 100; i++){
        for(int j = 1; j <= 100; j++){
            if(map[i][j] >= 2) result++;
        }
    }
    return result;
}

bool move(int i, vector<pair<int,int>> &loc, vector<queue<pair<int,int>>> &target){
    if(done[i]) return false;
    if(target[i].empty()) {
        map[loc[i].first][loc[i].second]--;
        done[i] = true;
        return false;
    }
    int x = loc[i].first;
    int y = loc[i].second;
    
    int nx = target[i].front().first;
    int ny = target[i].front().second;
    
    if(x != nx){
        if(x < nx){
            map[x][y]--;
            map[x+1][y]++;
            loc[i].first++;
        }
        else{
            map[x][y]--;
            map[x-1][y]++;
            loc[i].first--;
        }
    }
    else if(y != ny){
        if(y < ny){
            map[x][y]--;
            map[x][y+1]++;
            loc[i].second++;
        }
        else{
            map[x][y]--;
            map[x][y-1]++;
            loc[i].second--;
        }
    }
    
    if(loc[i].first == nx && loc[i].second == ny){
        target[i].pop();
    }
    
    return true;
}

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    
    vector<pair<int,int>> loc;
    vector<queue<pair<int,int>>> target;
    for(vector<int> v : routes){
        int cur = v[0]-1;
        map[points[cur][0]][points[cur][1]]++;
        loc.push_back({points[cur][0], points[cur][1]});
    }
    
    for(vector<int> v : routes){
        queue<pair<int,int>> move;
        for(int i : v){
            int cur = i-1;
            int x = points[i-1][0];
            int y = points[i-1][1];
            move.push({x, y});
        }
        target.push_back(move);
    }
    
    while(true){
        int move_count = 0;
        for(int i = 0; i < loc.size(); i++){
            if(!move(i, loc, target)) move_count++;
        }
        if(move_count == loc.size()) break;
        answer += getCollide();
        cout << getCollide() << "\n";
    }
    return answer;
}
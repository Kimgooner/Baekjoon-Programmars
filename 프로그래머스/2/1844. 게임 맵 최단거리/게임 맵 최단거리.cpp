#include<vector>
#include<queue>
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool isValid(int x, int y, int n, int m, vector<vector<bool>> &visited, vector<vector<int>> &maps){
    return x >= 1 && y >= 1 && x <= n && y <= m && !visited[x][y] && maps[x-1][y-1] == 1;
}

int solution(vector<vector<int> > maps)
{   
    int n = maps.size();
    int m = maps[0].size();
    
    vector<vector<bool>> visited(n+1, vector<bool>(m+1, false));
    queue<pair<pair<int,int>, int>> q;
    pair<int,int> start = {1, 1};
    pair<int,int> target = {n, m};
    
    q.push({start, 1});
    visited[1][1] = true;
    
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cur = q.front().second;
        q.pop();
        
        if(x == target.first && y == target.second){
            return cur;
        }
 
        
        for(int i = 0; i < 4; i++){
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            if(!isValid(next_x, next_y, n, m, visited, maps)) continue;
            visited[next_x][next_y] = true;
            q.push({{next_x, next_y}, cur+1});
        }
    }
    return -1;
}
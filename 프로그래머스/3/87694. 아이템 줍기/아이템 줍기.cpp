#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int map[102][102];
bool visited[102][102];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// 4, 3, 6, 9

//           (6, 9)
// (4, 3)
// x == 4 or 6인 경우, y가 3 or 9인 경우 

void makeRectangle(vector<vector<int>> &rec){
    for(vector<int> rectangle : rec){
        int lx = rectangle[0] * 2;
        int rx = rectangle[2] * 2;

        int ly = rectangle[1] * 2;
        int ry = rectangle[3] * 2;

        for(int i = lx; i <= rx; i++){
            for(int j = ly; j <= ry; j++){
                if(i == lx || i == rx || j == ly || j == ry){
                    if(map[i][j] == 1) continue;
                    map[i][j] = 2;
                }
                else{
                    map[i][j] = 1;
                }
            }
        }
    }
}

bool isValid(int x, int y){
    return x >= 1 && y >= 1 && x <= 100 && y <= 100 && !visited[x][y] && map[x][y] == 2;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    
    makeRectangle(rectangle);
    
    // for(int i = 1; i <= 10; i++){
    //     for(int j = 1; j <= 10; j++){
    //         cout << map[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    
    int sx = characterX * 2;
    int sy = characterY * 2;
    int tx = itemX * 2;
    int ty = itemY * 2;
    
    queue<pair<int, pair<int,int>>> q;
    q.push({0, {sx, sy}});
    visited[sx][sy] = true;
    
    while(!q.empty()){
        int cur_dist = q.front().first;
        int cur_x = q.front().second.first;
        int cur_y = q.front().second.second;
        q.pop();
        
        if(cur_x == tx && cur_y == ty) return cur_dist / 2;
        
        for(int i = 0; i < 4; i++){
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];
            if(!isValid(next_x, next_y)) continue;
            visited[next_x][next_y] = true;
            q.push({cur_dist+1, {next_x, next_y}});
        }
        
    }
    
    return -1;
}
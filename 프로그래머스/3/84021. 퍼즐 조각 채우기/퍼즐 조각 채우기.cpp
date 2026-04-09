#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

bool cmp(pair<int,int> p1, pair<int,int> p2){
    if(p1.first == p2.first) return p1.second < p2.second;
    else return p1.first < p2.first;
}

bool isValid(int x, int y, vector<vector<int>> &table, vector<vector<bool>> &visited, int val){
    int n = table.size();
    return x >= 0 && y >= 0 && x < n && y < n && !visited[x][y] &&table[x][y] == val;
}

void getBlock(int x, int y, vector<vector<int>> &table, vector<vector<bool>> &visited, vector<vector<pair<int,int>>> &blocks, int val){
    vector<pair<int,int>> result;
    queue<pair<int,int>> q;
    q.push({x, y});
    visited[x][y] = true;
    result.push_back({x, y});
    
    while(!q.empty()){
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];
            if(!isValid(next_x, next_y, table, visited, val)) continue;
            visited[next_x][next_y] = true;
            q.push({next_x, next_y});
            result.push_back({next_x, next_y});
        }
    }
    
    int min_x = 1e9;
    int min_y = 1e9;
    for(pair<int,int> p : result){
        min_x = min(min_x, p.first);
        min_y = min(min_y, p.second);
    }
    
    for(pair<int,int> &p : result){
        p.first -= min_x;
        p.second -= min_y;
    }
    sort(result.begin(), result.end(), cmp);
    blocks.push_back(result);
}

vector<pair<int,int>> blockRotate(vector<pair<int,int>> vec, int n){
    vector<pair<int,int>> rotated;
    for(pair<int,int> p : vec){
        rotated.push_back({p.second, (n-1)-p.first});
    } 
    
    int min_x = 1e9;
    int min_y = 1e9;
    for(pair<int,int> p : rotated){
        min_x = min(min_x, p.first);
        min_y = min(min_y, p.second);
    }
    
    for(pair<int,int> &p : rotated){
        p.first -= min_x;
        p.second -= min_y;
    }
    sort(rotated.begin(), rotated.end(), cmp);
    return rotated;
}

void print(vector<pair<int,int>> v){
    for(auto p : v){
        cout << "(" << p.first << ", " << p.second << ") "; 
    }
    cout << "\n";
}


int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    
    int n = game_board.size();
    vector<vector<bool>> visited_table(n, vector<bool>(n, false));
    vector<vector<bool>> visited_board(n, vector<bool>(n, false));
    vector<vector<pair<int,int>>> blocks;
    vector<vector<pair<int,int>>> blanks;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(isValid(i,j,table,visited_table, 1)){
                getBlock(i,j,table,visited_table,blocks, 1);
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(isValid(i,j,game_board,visited_board, 0)){
                getBlock(i,j,game_board,visited_board,blanks, 0);
            }
        }
    }
    
    int s1 = blocks.size();
    int s2 = blanks.size();
    
    vector<bool> block_used(s1, false);
    vector<bool> blank_used(s2, false);
    
    for(int j = 0; j < s2; j++){
        for(int i = 0; i < s1; i++){
            if(block_used[i] || blank_used[j]) continue;
            
            
            if(blocks[i].size() == blanks[j].size()){
                vector<pair<int,int>> temp = blocks[i];
                bool match = false;
                
                for(int r = 0; r < 4; r++){
                    if(temp == blanks[j]){
                        match = true;
                        break;
                    }
                    temp = blockRotate(temp, n);
                }
                
                if(match){
                    answer += temp.size();
                    block_used[i] = true;
                    blank_used[j] = true;
                    break;
                }
            }
        }
    }
    
    return answer;
}
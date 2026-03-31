#include <string>
#include <vector>

using namespace std;

int visited[8];
int max_clear;
void backtracking(int cur, int clear, vector<vector<int>> d){
    for(int i = 0; i < d.size(); i++){
        if(cur >= d[i][0] && !visited[i]){
            visited[i] = true;
            backtracking(cur - d[i][1], clear+1, d);
            visited[i] = false;
        }
    }
    max_clear = max(max_clear, clear);
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    
    backtracking(k, 0, dungeons);
    answer = max_clear;
    
    return answer;
}
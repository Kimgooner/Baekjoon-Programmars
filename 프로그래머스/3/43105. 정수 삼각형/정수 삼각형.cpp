#include <string>
#include <vector>

using namespace std;

// dp[1][1] = 7
// dp[2][1] = 10, dp[2][2] = 15
// dp[3][1] = 18, dp[3][2] = 11 | 16, dp[3][3] = 15

// dp[i][j] + tri[i+1][j] = dp[i+1][j]
// dp[i][j] + tri[i+1][j+1] = dp[i+1][j+1]

// dp[1][1]

// dp[2][1] = dp[1][1] + tri[1][0]
// dp[2][2] = dp[1][1] + tri[1][1]

// dp[2][2] = dp[1][2] + tri[1][1]
// dp[2][3] = dp[1][2] + tri[1][2]

int dp[501][501];
int solution(vector<vector<int>> triangle) {
    int n = triangle.size();
    dp[1][1] = triangle[0][0];
    
    for(int i = 1; i < triangle.size(); i++){
        for(int j = 1; j < triangle[i].size(); j++){
            dp[i+1][j] = max(dp[i][j] + triangle[i][j-1], dp[i+1][j]);
            dp[i+1][j+1] = max(dp[i][j] + triangle[i][j], dp[i+1][j+1]);
        }
    }
    int answer = 0;
    
    for(int i = 0; i < n; i++){
        answer = max(answer, dp[n][i]);
    }
    
    return answer;
}
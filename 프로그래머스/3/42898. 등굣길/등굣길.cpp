#include <string>
#include <vector>

using namespace std;
int mod = 1000000007;
int dp[105][105];

int solution(int m, int n, vector<vector<int>> puddles) {
    for(vector<int> p : puddles){
        dp[p[1]][p[0]] = -1;
    }
    
    dp[1][1] = 1;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(i == 1 && j == 1) continue;
            if(dp[i][j] == -1){
                dp[i][j] = 0;
            } else {
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % mod;
            }
        }
    }
    
    return dp[n][m];
}
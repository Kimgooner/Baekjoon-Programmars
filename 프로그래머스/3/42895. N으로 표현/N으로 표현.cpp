#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(int N, int number) {
    if(N == number) return 1;    
    vector<unordered_set<long long>> dp(9);
    
    for(int i = 1; i <= 8; i++){
        dp[i].insert(stoll(string(i, '0' + N)));
        
        for(int j = 1; j < i; j++){
            for(long long a : dp[j]){
                for(long long b : dp[i-j]){
                    dp[i].insert(a + b);
                    dp[i].insert(a * b);
                    if(a - b > 0) dp[i].insert(a-b);
                    if(b != 0) dp[i].insert(a / b);
                }
            }
        }
        if(dp[i].find(number) != dp[i].end()) return i;
    }
    return -1;
}
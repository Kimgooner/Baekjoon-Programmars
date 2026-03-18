#include <iostream>
using namespace std;

int N;
pair<int, int> counsel[17];
int dp[17];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 1; i<= N; i++) {
        cin >> counsel[i].first >> counsel[i].second;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = i + counsel[i].first; j <= N+1; j++) {
            if (dp[j] < dp[i] + counsel[i].second) dp[j] = dp[i] + counsel[i].second;
        }
    }

    // for (int i = 1; i <= N; i++) {
    //     cout << dp[i] << " ";
    // }
    // cout << endl;
    cout << dp[N+1] << endl;
   return 0;
}
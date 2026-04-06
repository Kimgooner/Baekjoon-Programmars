#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    stack<pair<int,int>> q; // target, index
    q.push({numbers[0], 0});
    q.push({-numbers[0], 0});
    
    while(!q.empty()){
        int cur_target = q.top().first;
        int cur_idx = q.top().second;
        q.pop();
        
        int next_idx = cur_idx + 1;
        int next_target_p = cur_target + numbers[next_idx];
        int next_target_m = cur_target - numbers[next_idx];
        
        if(next_idx == numbers.size()-1){
            if(next_target_p == target) answer++;
            if(next_target_m == target) answer++;
            continue;
        }
        q.push({next_target_p, next_idx});
        q.push({next_target_m, next_idx});
    }
    return answer;
}
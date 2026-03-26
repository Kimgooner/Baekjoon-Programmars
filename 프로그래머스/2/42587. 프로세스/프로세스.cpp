#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    queue<pair<int, int>> process;
    vector<int> sorted(priorities.begin(), priorities.end());
    
    int idx = 0;
    for(int p : priorities){
        process.push(make_pair(idx++, p));
    }
    
    sort(sorted.begin(), sorted.end(), greater<int>());
    for(int i = 0; i < sorted.size(); i++){
        cout << sorted[i] << "\n";
        while(process.front().second != sorted[i]){
            pair<int,int> temp = process.front();
            process.pop();
            process.push(temp);
        }
        int run = process.front().first;
        cout << run << " ";
        process.pop();
        if(run == location){
            answer = i+1;
            break;
        }
    }
    return answer;
}
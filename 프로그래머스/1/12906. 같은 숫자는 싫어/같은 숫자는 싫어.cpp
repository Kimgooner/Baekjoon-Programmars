#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    queue<int> eli;
    
    eli.push(arr[0]);
    for(int i : arr){
        if(eli.back() == i) continue;
        eli.push(i);
    }
    while(!eli.empty()) {
        answer.push_back(eli.front());
        eli.pop();
    }
    return answer;
}
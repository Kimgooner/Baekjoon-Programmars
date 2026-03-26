#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    stack<pair<int,int>> stock;
    
    for(int i = 0; i < prices.size(); i++){
        answer.push_back(0);
    }
    
    int time = -1;
    for(int p : prices){
        time++;
        while(!stock.empty()){
            if(stock.top().second > p){
                pair<int,int> out = stock.top();
                stock.pop();
                answer[out.first] = time - out.first;
            }
            else break;
        }
        stock.push(make_pair(time, p));
    }
    while(!stock.empty()){
        pair<int,int> out = stock.top();
        stock.pop();
        answer[out.first] = time - out.first;
    }
    
    return answer;
}
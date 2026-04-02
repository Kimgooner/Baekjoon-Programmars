#include <string>
#include <vector>
#include <stack>

using namespace std;

int getNum(char c){
    return c - '0';
}

char getChar(int n){
    return n + '0';
}

// k 4
// 4 1
// k 2
// 7 7 

string solution(string number, int k) {
    stack<int> val;
    int size = number.size();
    for(int i = 0; i < size; i++){
        int cur = getNum(number[i]);
        if(!val.empty()){
            if(val.top() < cur){
                while(val.top() < cur && k > 0){
                    val.pop();
                    k--;
                    if(val.empty()) break;
                }
            }
        }
        val.push(cur);
    }
    while(k > 0){
        val.pop();
        k--;
    }
    
    
    string answer = "";
    while(!val.empty()){
        answer = getChar(val.top()) + answer;
        val.pop();
    }
    
    return answer;
}
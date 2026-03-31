#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>
#include <cmath>

using namespace std;

set<int> values;
bool visited[7];
void getNumber(string s, string cur){
    if(cur[0] == '0') return;
    if(cur != "") {
        values.insert(stoi(cur));
    }
    for(int i = 0; i < s.size(); i++){
        if(!visited[i]){
            visited[i] = true;
            getNumber(s, cur + s[i]);
            visited[i] = false;
        }
    }
}

bool isPrime(int val){
    if(val == 1) return false;
    for(int i = 2; pow(i,2) <= val; i++){
        if(val % i == 0) return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    
    getNumber(numbers, "");
    for(int v : values){
        if(isPrime(v)) answer++;
    }

    return answer;
}
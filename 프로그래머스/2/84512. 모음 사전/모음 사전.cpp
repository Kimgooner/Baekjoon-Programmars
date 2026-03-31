#include <string>
#include <vector>
#include <map>

using namespace std;

int idx = 1;
map<string, int> dic;
string source = "AEIOU";

void makeDictionary(string cur, int n){
    if(n == 5) return;
    
    for(int i = 0; i < 5; i++){
        dic[cur + source[i]] = idx++;
        makeDictionary(cur + source[i], n+1);
    } 
}


int solution(string word) {
    makeDictionary("", 0);
    return dic[word];
}
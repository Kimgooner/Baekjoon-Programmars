#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> drawer;
    
    for(vector<string> vString : clothes) {
        drawer[vString[1]]++;
    }
    
    for(auto p = drawer.begin(); p != drawer.end(); ++p){
        answer *= p->second + 1;
    }
    return answer-1;
}
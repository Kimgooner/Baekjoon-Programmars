#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end(), greater<int>());
    //6 5 3 1 0
    //1 2 3
    
    
    int h = 0;
    for(int i = 0; i < citations.size(); i++){
        if(citations[i] >= i+1){
            h++;
        }       
        else break;
    }

    return h;
}
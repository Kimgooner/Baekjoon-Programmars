#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    vector<int> student(n+1, 1);
    for(int l : lost) { student[l]--; }
    for(int r : reserve) { student[r]++; }
    
    for(int l = 1; l <= n; l++) {
        if(student[l] == 0){
            if(l-1 >= 1 && student[l-1] >= 2){
                student[l]++;
                student[l-1]--;
                continue;
            }
            if(l+1 <= n && student[l+1] >= 2){
                student[l]++;
                student[l+1]--;
                continue;
            }
        }
    }
    
    for(int i = 1; i <= n; i++){
        if(student[i] >= 1) answer++;
    }
    
    return answer;
}
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    
    int size = money.size();
    vector<int> dp_1(size+1, 0);
    vector<int> dp_2(size+1, 0);
    
    dp_1[1] = money[0];
    for(int i = 2; i <= size-1; i++){
        dp_1[i] = max(dp_1[i-1], dp_1[i-2] + money[i-1]);
    }
    
    dp_2[1] = 0;
    for(int i = 2; i <= size; i++){
        dp_2[i] = max(dp_2[i-1], dp_2[i-2] + money[i-1]);
    }
    
    answer = max(dp_1[size-1], dp_2[size]);
    return answer;
}
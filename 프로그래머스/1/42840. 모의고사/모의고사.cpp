#include <string>
#include <vector>

using namespace std;

int t1[5] = {1, 2, 3, 4, 5};
int t2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
int t3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int t1_score = 0;
    int t2_score = 0;
    int t3_score = 0;
    
    for(int i = 0; i < answers.size(); i++){
        if(t1[i%5] == answers[i]) t1_score++;
        if(t2[i%8] == answers[i]) t2_score++;
        if(t3[i%10] == answers[i]) t3_score++;
        
    }
    
    int max_score = max(t1_score, max(t2_score, t3_score));
    
    if(t1_score == max_score) answer.push_back(1);
    if(t2_score == max_score) answer.push_back(2);
    if(t3_score == max_score) answer.push_back(3);

    return answer;
}
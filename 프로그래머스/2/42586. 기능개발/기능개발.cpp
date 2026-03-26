#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    map<int, int> current_progress;
    map<int, int> speedMap;
    queue<int> works;
    vector<int> answer;
    
    int work_size = speeds.size();
    for(int i = 0; i < work_size; i++){
        current_progress[i] = progresses[i];
        speedMap[i] = speeds[i];
        works.push(i);
    }
    
    while(!works.empty()){
        for(int i = 0; i < work_size; i++){
            current_progress[i] += speedMap[i];    
        }
        int done = 0;
        while(!works.empty()){
            int cur = works.front();
            if(current_progress[cur] >= 100) {
                works.pop();
                done++;
            }
            else break;
        }
        if(done != 0) answer.push_back(done);
    }
    return answer;
}
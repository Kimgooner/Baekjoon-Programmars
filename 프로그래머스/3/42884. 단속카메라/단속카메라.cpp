#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// -20, -15
// -18, -13
// -14, -5
// -5, -3

bool cmp(vector<int> v1, vector<int> v2){
    return v1[1] < v2[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    sort(routes.begin(), routes.end(), cmp);
    int camera_pos = -30001;
    
    for(int i = 0; i < routes.size(); i++){
        if(camera_pos < routes[i][0]){
            answer++;
            camera_pos = routes[i][1];
        }
    }
    return answer;
}
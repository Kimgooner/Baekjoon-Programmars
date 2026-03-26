#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>

using namespace std;

//<소요시각, <요청 시각, 번호>>
struct Compare {
    bool operator()(pair<int,pair<int,int>> p1, pair<int,pair<int,int>> p2){
        if(p1.first == p2.first){
            if(p1.second.first == p2.second.first) return p1.second.second > p2.second.second;
            else return p1.second.first > p2.second.first;
        }
        else return p1.first > p2.first;
    }
};

bool cmp(vector<int> v1, vector<int> v2){
    return v1[0] < v2[0];
}

int solution(vector<vector<int>> jobs) {
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, Compare> q;
    queue<pair<int,pair<int,int>>> works;
    vector<int> done;
    
    sort(jobs.begin(), jobs.end(), cmp);
    for(int i = 0; i < jobs.size(); i++){
        works.push(make_pair(jobs[i][1],make_pair(jobs[i][0], i)));
    }
    
    int time = 0;
    int count = 0;
    
    while(count != jobs.size()){
        while(!works.empty()){
            if(time < works.front().second.first) break;
            q.push(works.front());
            works.pop();
        }
        if(!q.empty()){
            time += q.top().first;
            done.push_back(time - q.top().second.first);
            q.pop();
            count++;
        }
        else time = works.front().second.first;
    }
    int sum = accumulate(done.begin(), done.end(), 0);
    return sum / done.size();
}
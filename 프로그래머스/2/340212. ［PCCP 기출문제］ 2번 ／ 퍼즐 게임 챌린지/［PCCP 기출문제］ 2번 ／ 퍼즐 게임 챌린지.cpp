#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//level = n;

// (diff - level) = count;
// count * time_prev + (count+1) * time_cur
int binary_search(int s, int e, long long limit, vector<int> &diffs, vector<int> &times){
    if(s == e) return s;
    long long cost = 0;
    int pivot = (s + e) / 2;
    for(int i = 0; i < diffs.size(); i++){
        int count = diffs[i] - pivot;
        if(count <= 0) cost += times[i];
        else cost += times[i] + count * (times[i] + times[i-1]);
    }
    if(cost > limit) return binary_search(pivot+1, e, limit, diffs, times);
    else return binary_search(s, pivot, limit, diffs, times);
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    int level = -1;
    
    for(int d : diffs){
        level = max(level, d);
    }
    answer = binary_search(1, level, limit, diffs, times);
    return answer;
}
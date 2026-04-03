#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int getParent(vector<int> &parent, int x){
    if(parent[x] == x) return x;
    return parent[x] = getParent(parent, parent[x]);
}

void unionFind(vector<int> &parent, int a, int b){
    a = getParent(parent, a);
    b = getParent(parent, b);
    
    if(a < b) parent[b] = a;
    else parent[a] = b;
}

bool cmp(vector<int> a, vector<int> b){
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    sort(costs.begin(), costs.end(), cmp);
    
    vector<int> parent(n);
    for(int i = 0; i < n; i++){
        parent[i] = i;
    }
    
    for(int i = 0; i < costs.size(); i++){
        int start = costs[i][0];
        int end = costs[i][1];
        int cost = costs[i][2];
        
        if(getParent(parent, start) != getParent(parent, end)) {
            unionFind(parent, start, end);
            answer += cost;
        }
    }
    
    return answer;
}
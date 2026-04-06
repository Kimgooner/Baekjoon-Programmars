#include <string>
#include <vector>
#include <iostream>

using namespace std;

int getParent(vector<int> &parent, int x){
    if(parent[x] == x) return x;
    return parent[x] = getParent(parent, parent[x]);
}

void unite(vector<int> &parent, int a, int b){
    a = getParent(parent, a);
    b = getParent(parent, b);
    
    if(a != b){
        if(a < b) parent[b] = a;
        else parent[a] = b;
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    vector<int> parent(n);
    for(int i = 0; i < n; i++){
        parent[i] = i;
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i != j && computers[i][j] == 1){
                unite(parent, i, j);
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        int v = getParent(parent, i);
        if(getParent(parent, i) == i){
            answer++;
        }
        cout << v << " ";
    }

    return answer;
}
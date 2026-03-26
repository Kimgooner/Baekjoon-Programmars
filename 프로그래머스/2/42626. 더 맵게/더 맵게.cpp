#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for(int s : scoville){
        minHeap.push(s);
    }
    
    int count = 0;
    while(minHeap.size() >= 2){
        if(minHeap.top() >= K) return count;
        int gred1 = minHeap.top(); minHeap.pop();
        int gred2 = minHeap.top(); minHeap.pop();
        minHeap.push(gred1 + (gred2 * 2));
        count++;
    }
    if(minHeap.top() >= K) return count;
    return -1;
}
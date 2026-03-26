#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int current_weight = 0;
    int answer = 0;
    queue<int> bridge;
    queue<int> trucks;
    
    for(int i = 0; i < bridge_length; i++){
        bridge.push(0);
    }
    for(int w : truck_weights){
        trucks.push(w);
    }
    
    int time = 0;
    while(!trucks.empty()){
        int truck_out = bridge.front();
        current_weight -= truck_out;
        bridge.pop();
        
        int next_truck = trucks.front();
        if(current_weight + next_truck <= weight){
            current_weight += next_truck;
            bridge.push(next_truck);
            trucks.pop();
        }
        else{
            bridge.push(0);
        }
        time++;
    }
    
    while(!bridge.empty()){
        bridge.pop();
        time++;
    }
    
    answer = time;
    return answer;
}
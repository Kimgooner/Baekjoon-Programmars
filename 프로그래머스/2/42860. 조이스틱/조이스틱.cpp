#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

int getAlphaPos(char alpha){
    return (alpha - 'A') + 1;
}

int getAlphaMove(char cur, char target){
    int cur_pos = getAlphaPos(cur);
    int target_pos = getAlphaPos(target);
    
    int min_pos = min(cur_pos, target_pos);
    int max_pos = max(cur_pos, target_pos);
    
    return min(max_pos - min_pos, min_pos + (26 - max_pos));
}

int solution(string name) {
    int answer = 0;

    for(int i = 0; i < name.size(); i++){
        if(name[i] != 'A') answer += getAlphaMove('A', name[i]);
    }
    
    int move = name.size()-1;
    for(int i = 0; i < name.size(); i++){
        int next = i + 1;
        while(next < name.size() && name[next] == 'A'){
            next++;
        }
        
        int right_move = i + i + (name.size() - next);
        int left_move = (name.size() - next) + (name.size() - next) + i;
        move = min(move, min(right_move, left_move));
    }
    
    return answer + move;
}
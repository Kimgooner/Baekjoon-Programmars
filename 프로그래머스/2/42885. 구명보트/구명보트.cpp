#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 50 50 70 80
// 0 3 -> +1
// 0 2 -> +1
// 0 1 -> +1
// 1 1

// 50 70 80
// 0 2 -> +1
// 0 1 -> +1
// 0 0 -> break;
// +1

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end());

    int answer = 0;
    int left = 0;
    int right = people.size()-1;
    while(left <= right){
        if(people[left] + people[right] <= limit){
            left++;
            right--;
        }
        else{
            right--;
        }
        answer++;
    }
    return answer;
}
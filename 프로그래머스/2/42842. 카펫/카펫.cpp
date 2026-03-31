#include <string>
#include <vector>

using namespace std;

//갈색의 수 = 2w + 2h + 4.
//w, h는 각각 노란칸의 너비와 높이.
//노랑의 수 = w*h.

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    for(int i = 1; i <= yellow; i++){
        if(yellow % i != 0) continue;
        int w = i;
        int h = yellow / i;
        if((2*w + 2*h + 4) == brown) {
            answer.push_back(max(w,h) + 2);
            answer.push_back(min(w,h) + 2);
            break;
        }
    }
    
    return answer;
}
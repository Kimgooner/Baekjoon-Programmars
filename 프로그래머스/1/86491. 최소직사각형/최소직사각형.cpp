#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int max_w = 0;
    int max_h = 0;
    for(vector<int> v : sizes){
        int w = max(v[0], v[1]);
        int h = min(v[0], v[1]);
        max_w = max(max_w, w);
        max_h = max(max_h, h);
    }
    
    return max_w * max_h;
}
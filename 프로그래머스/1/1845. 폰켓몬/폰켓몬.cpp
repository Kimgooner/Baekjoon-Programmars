#include <vector>
#include <map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    map<int, int> mons;
    
    for(int i : nums){
        mons[i]++;
    }
    
    int picks = nums.size() / 2;
    int mons_count = mons.size();
    if(picks > mons_count) return mons_count;
    else return picks;
}
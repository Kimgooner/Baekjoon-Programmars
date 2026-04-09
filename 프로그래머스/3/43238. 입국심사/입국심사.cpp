#include <string>
#include <vector>

using namespace std;

int MAX_PPL = 1000000000;
int MAX_TIME = 1000000000;

long long binary_search(long long s, long long e, int n, vector<int> &times){
    if(s == e) return s;
    long long done = 0;
    long long pivot = (s + e) / 2;
    for(int t : times){
        done += pivot / t;
    }
    if(done >= n) return binary_search(s, pivot, n, times);
    else return binary_search(pivot+1, e, n, times);
}

long long solution(int n, vector<int> times) {
    long long limit = MAX_PPL * MAX_TIME;
    return binary_search(0, limit, n, times);
}
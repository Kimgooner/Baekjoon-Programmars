#include <iostream>
using namespace std;

int N;
int A[1000001];
int B, C;

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    cin >> B >> C;

    long long sum = 0;
    for(int i = 0; i < N; i++){
        int residue = A[i] - B;
        sum++;
        if (residue <= 0) continue;
        sum += (residue / C);
        if(residue % C != 0) sum++;
    }
    cout << sum;
    return 0;
}
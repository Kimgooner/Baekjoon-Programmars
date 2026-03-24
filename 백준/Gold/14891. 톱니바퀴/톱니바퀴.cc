#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int gear[4][8];
int direction[4];
int K;

bool isValid(int n) {
    return n >= 0 && n < 4;
}

void rotate(int n, int d) {
    if (d == 1) {
        int tmp = gear[n][7];
        for (int i = 6; i >= 0; i--) {
            gear[n][i+1] = gear[n][i];
        }
        gear[n][0] = tmp;
    }
    else if (d == -1) {
        int tmp = gear[n][0];
        for (int i = 1; i <= 7; i++) {
            gear[n][i-1] = gear[n][i];
        }
        gear[n][7] = tmp;
    }
}

void rotationAffect(int n) {
    if (isValid(n+1) && gear[n][2] != gear[n+1][6] && direction[n+1] == 0) {
        direction[n+1] = direction[n] * -1;
        rotationAffect(n+1);
    }
    if (isValid(n-1) && gear[n][6] != gear[n-1][2] && direction[n-1] == 0) {
        direction[n-1] = direction[n] * -1;
        rotationAffect(n-1);
    }
}

void print_direction() {
    for (int i = 0; i < 4; i++) {
        cout << direction[i] << " ";
    }
    cout << "\n";
}

int summary() {
    int sum = 0;
    for (int i = 0; i < 4; i++) {
        if (gear[i][0] == 1) sum += (int) pow(2, i);
    }

    return sum;
}

int main() {
    string input;
    for (int i = 0; i < 4; i++) {
        cin >> input;
        for (int j = 0; j < 8; j++) {
            gear[i][j] = input[j] - '0';
        }
    }
    cin >> K;
    int g, d;
    for (int i = 0; i < K; i++) {
        cin >> g >> d;
        fill(direction, direction + 4, 0);
        direction[g-1] = d;
        rotationAffect(g-1);
        //print_direction();

        for (int i = 0; i < 4; i++) {
            rotate(i, direction[i]);
        }
    }
    cout << summary();
}
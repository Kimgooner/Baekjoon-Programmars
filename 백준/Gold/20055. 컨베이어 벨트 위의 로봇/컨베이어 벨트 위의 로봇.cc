#include <iostream>
using namespace std;

int N, K;
int conveyor[205];
int robot[105];

void conveyor_move() {
    int temp = conveyor[2*N];
    for (int i = (2*N); i >= 2; i--) {
        conveyor[i] = conveyor[i-1];
    }
    conveyor[1] = temp;
}

bool conveyor_check() {
    int count = 0;
    for (int i = 1; i <= (2*N); i++) {
        if (conveyor[i] == 0) count++;
    }
    return count >= K;
}

void robot_out() {
    robot[N] = 0;
}

void robot_in() {
    if (conveyor[1] != 0) {
        robot[1] = 1;
        conveyor[1]--;
    }
}

void robot_move_withConveyor() {
    for (int i = N; i >= 2; i--) {
        robot[i] = robot[i-1];
    }
    robot[1] = 0;
    if (robot[N] != 0) {
        robot_out();
    }
}

void robot_move() {
    for (int i = N-1; i >= 1; i--) {
        if (robot[i] != 0 && robot[i+1] == 0 && conveyor[i+1] != 0) {
            robot[i+1] = 1; robot[i] = 0;
            conveyor[i+1]--;
        }
    }
    if (robot[N] != 0) {
        robot_out();
    }
}

void print() {
    cout << "=======\n";
    for (int i = 1; i <= 2*N; i++) {
        cout << conveyor[i] << " ";
    }
    cout << "\n";
    for (int i = 1; i <= N; i++) {
        cout << robot[i] << " ";
    }
    cout << "\n";
    cout << "=======\n";
}

int main() {
    cin >> N >> K;
    for (int i = 1; i <= (2*N); i++) {
        cin >> conveyor[i];
    }

    int level = 0;
    //print();
    while (!conveyor_check()) {
        level++;
        conveyor_move();
        robot_move_withConveyor();
        robot_move();
        robot_in();
        //print();
    }

    cout << level;
}
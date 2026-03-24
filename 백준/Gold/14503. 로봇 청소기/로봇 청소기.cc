#include <iostream>
using namespace std;

int room[50][50];
int N, M;
int r, c, d;

int count = 0;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool isDone = false;

bool isValid(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M && room[x][y] != 1;
}

void rotate() {
    d--;
    if (d < 0) d = 3;
}

bool checkSurround() {
    for (int i = 0; i < 4; i++) {
        int next_r = r + dx[i];
        int next_c = c + dy[i];
        if (isValid(next_r, next_c) && room[next_r][next_c] == 0) {
            return true;
        }
    }
    return false;
}

bool move_forward() {
    int next_r = r + dx[d];
    int next_c = c + dy[d];

    if (isValid(next_r, next_c) && room[next_r][next_c] == 0) {
        r = next_r;
        c = next_c;
        return true;
    }
    return false;
}

bool move_backwards() {
    int next_r = r - dx[d];
    int next_c = c - dy[d];

    if (isValid(next_r, next_c)) {
        r = next_r;
        c = next_c;
        return true;
    }
    return false;
}

void func_1() {
    if (room[r][c] == 0) {
        room[r][c] = 2;
        count++;
    }
}

void func_2() {
    if (!move_backwards()) isDone = true;
}

void func_3() {
    rotate();
    move_forward();
}

void print_room() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << room[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> r >> c >> d;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> room[i][j];
        }
    }

    while (!isDone) {
        func_1();
        if (!checkSurround()) func_2();
        else func_3();
    }

    //print_room();
    cout << count;
    return 0;
}
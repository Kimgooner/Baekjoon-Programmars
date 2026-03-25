#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
using namespace std;

int N, M;
vector<pair<int, int>> stores;
vector<pair<int, int>> houses;

int getLength(pair<int, int> s, pair<int, int> h) {
    return abs(s.first - h.first) + abs(s.second - h.second);
}

int getChickenLength(vector<pair<int, int>> b) {
    int n = houses.size();
    vector<int> minValue(n);
    fill(minValue.begin(), minValue.end(), 1e9);

    for (pair<int,int> p : b) {
        for (int i = 0; i < n; i++) {
            minValue[i] = min(getLength(p, houses[i]), minValue[i]);
        }
    }
    return accumulate(minValue.begin(), minValue.end(), 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;

    int val;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> val;
            if (val == 1) houses.emplace_back(i, j);
            else if (val == 2) stores.emplace_back(i, j);
        }
    }

    int n = stores.size();
    int r = M;

    vector<int> mask(n);
    fill(mask.end() - r, mask.end(), 1);

    int result = 1e9;
    do {
        vector<pair<int,int>> buffer;
        for (int i = 0; i < n; i++) {
            if (mask[i] == 1) {
                buffer.push_back(stores[i]);
            }
        }
        result = min(getChickenLength(buffer), result);
    } while (next_permutation(mask.begin(), mask.end()));

    cout << result << "\n";
}
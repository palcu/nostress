/***************************************************
 * Alex Palcuie
 * FMI No Stress 2015 - buget - 100 puncte O(N log N + N)
 * alex [dot] palcuie [at] gmail [dot] com
 * http://blog.palcu.ro/
****************************************************/
#include <algorithm>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

using namespace std;

#define int64 long long

vector<int> budgets, partial_sums;

int main() {
    ifstream fin("buget.in");
    ofstream fout("buget.out");

    int n; int64 b, max_x=-1;
    fin >> n >> b;

    assert(1 <= n && n < pow(10, 5));
    assert(1 <= b && b < pow(10, 15));

    int64 sum_x = 0;
    for (int i=0; i<n; i++) {
        int x; fin >> x;
        assert(0 <= x && x < pow(10, 9));
        max_x = max_x > x ? max_x : x;
        sum_x += x;
        budgets.push_back(x);
    }
    assert(b < sum_x);

    int left = 1, right = max_x, cap = -1;
    while (left <= right) {
        cap = right - (right-left) / 2;
        cerr << "cap = " << cap << endl;
        int64 sum = 0;
        for (auto x : budgets) {
            if (x <= cap) {
                sum += x;
            } else {
                sum += cap;
            }
        }
        cerr << "sum = " << sum << endl;

        if (sum == b) {
            right = cap;
            break;
        } else if (sum > b) {
            right = cap - 1;
        } else {
            left = cap + 1;
        }
    }
    fout << right << "\n";

    return 0;
}

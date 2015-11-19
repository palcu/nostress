/*
    O(NlogN) from sorting + O(N)
*/

#include <cassert>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

#define int64 long long

const string input_file =   "buget.in";
const string output_file =  "buget.out";

const int kMaxN = 1e5;
const int kMaxVal = 1e9;
const int64 kMaxB = 1e15; 

ifstream fin(input_file.c_str());
ofstream fout(output_file.c_str());

vector<int> elements = {0, 0};
vector<int64> elements_sum;

void set_result(int rez) {
    fout << rez << '\n';
    exit(0);
}

int main() {
    int n; int64 b; fin >> n >> b;
    assert(1 <= n and n < kMaxN);
    assert(0 <= b and b < kMaxB);

    for (int i = 0; i < n; ++i) {
        int x; fin >> x;
        assert(1 <= x and x < kMaxVal);
        elements.push_back(x);
    }
    sort(elements.begin(), elements.end());
    int64 current_sum = 0;
    for (auto current_element : elements) {
        current_sum += current_element;
        elements_sum.push_back(current_sum);
    }
    
    assert(*elements_sum.rbegin() > b);

    for (int i = int(elements_sum.size()) - 1; i >= 0; --i) {
        if (elements_sum[i] + 1LL * elements[i] * (int(elements_sum.size()) - i - 1) <= b) {
            int rez = (b - elements_sum[i]) / (int(elements_sum.size()) - i - 1);
            set_result(rez);
        }
    }
    
    return 0;
}

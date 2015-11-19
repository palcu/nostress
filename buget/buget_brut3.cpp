// Alex Velea
// O(N) + O(maxval - rez) = O(N) + O(rez)
// + parsare

#include <algorithm>
#include <fstream>
#include <vector>
using namespace std;                                                                        

#define int64 long long 

vector<int> values;

ifstream fin("buget.in");
ofstream fout("buget.out");

int main() {
    int n; int64 b; fin >> n >> b;
    for (int i = 0; i < n; ++i) {
        int x; fin >> x;
        values.push_back(x);
    }

    sort(values.begin(), values.end());

    for (int d = *values.rbegin(); d >= 0; --d) {
        int64 sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += min(d, values[i]);
        }

        if (sum <= b) {
            fout << d << '\n';
            exit(0);
        }
    }
    return 0;
}

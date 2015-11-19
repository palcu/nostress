#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

ifstream fin("trenul.in");
ofstream fout("trenul.out");

const int kMaxN = 1e5 + 5;

vector<int> result[kMaxN];
vector<int> event[4];

int main() {
    int aux, n; fin >> aux >> n;
    for (int i = 1; i <= n; ++i) {
        int x; fin >> x;
        event[x].push_back(i);
    }
    vector<int> order = {2, 3, 1};
    int currentPosition = 1;
    for (auto nrOfEl : order) {
        for (auto position : event[nrOfEl]) {
            for (int i = 0; i < nrOfEl; ++i) {
                result[position].push_back(currentPosition++);
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (auto itr : result[i]) {
            fout << itr << ' ';
        }
        fout << '\n';
    }
}


/***************************************************
 * Alex Palcuie
 * FMI No Stress 2015 - buget - 100 puncte O(N log N + N)
 * alex [dot] palcuie [at] gmail [dot] com
 * http://blog.palcu.ro/
****************************************************/
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

#define int64 long long 

vector<int> budgets;

int main() {
    ifstream fin("buget.in");
    ofstream fout("buget.out");
    
    int n; int64 b, sum=0;
    fin >> n >> b;
    for (int i=0; i<n; i++) {
        int x; fin >> x;
        sum += x;
        budgets.push_back(x);
    }

    // Am putea să avem plafonul 1 dacă sumele sunt prea mari
    budgets.push_back(1);
    sort(budgets.begin(), budgets.end(), greater<int>());

    for (int i=0; i<budgets.size(); i++) {
        int64 possible_budget = sum + budgets[i] * i;
        // cerr << possible_budget << endl;
        if (possible_budget <= b) {
            fout << budgets[i] << endl;
            break;
        }
        sum -= budgets[i];
    }
    
    return 0;
}

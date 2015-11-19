#include <cmath>
#include <cassert>

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define int64 long long

const int kMaxX = 1e9, kMaxSize = 1e5 + 1, kMaxVal = 1e9;

const vector<string> good_sources = {"licenta_palcu_100p", "licenta_scipianus_100p"};

int test_number;
vector<int> limit;

int random_int() {
    return rand();
}

double random_01() {
    return (1.0 * rand() / double(RAND_MAX));
}

int linear_element_generator() {
    int r = random_int();
    r = r % (limit[1] - limit[0]) + limit[0];
    return r;
}

int logaritmic_element_generator() {
    double diff = log(limit[1]) - log(limit[0]);
    double r = random_01() * diff;
    return int(exp(r) * limit[0]);
}

void write_test(int x, int n, vector<pair<int, int> > N, int m, vector<pair<int, int> > M) {
    assert(1 <= x and x < kMaxX);
    assert(1 <= n and n < kMaxSize);
    assert(1 <= m and m < kMaxSize);

    for (auto itr : N) {
        assert(itr.first < itr.second);
    }

    for (auto itr : M) {
        assert(itr.first < itr.second);
    }

    random_shuffle(N.begin(), N.end());
    random_shuffle(M.begin(), M.end());

//    string test_location = to_string(test_number) + ".in";
    string test_location = "licenta.in";

    ofstream fout(test_location.c_str());
    fout << x << '\n';
    fout << n << '\n';
    for (auto itr : N) {
        fout << itr.first << ' ' << itr.second << '\n';
    }

    fout << m << '\n';
    for (auto itr : M) {
        fout << itr.first << ' ' << itr.second << '\n';
    }
}

template<typename Function>
vector<pair<int, int> > generate_array(int n, Function element_generator, vector<int> _limits) {
    vector<pair<int, int> > result;
    limit = _limits;
    int currentSum = 0;
    for (int i = 0; i < n; i += 1) {
        currentSum += element_generator();
        assert(1 <= currentSum and currentSum < kMaxVal);
        int a = currentSum;
        currentSum += element_generator();
        assert(1 <= currentSum and currentSum < kMaxVal);
        int b = currentSum;
        result.push_back({a, b});
    }
    return result;
}

template<typename Function>
void generate_test(int seed, int n, vector<int> nLimits, int m, vector<int> mLimits, Function element_generator) {
    srand(seed);
    vector<pair<int, int> > N, M;
    N = generate_array(n, element_generator, nLimits);
    M = generate_array(m, element_generator, mLimits);

    int maxX = 0;

    auto intersect_pair = [](pair<int, int> a, pair<int, int> b) {
        return max(min(a.second, b.second) - max(a.first, b.first), 0);
    };

    for (int itrN = 0, itrM = 0; itrN < int(N.size()) and itrM < int(M.size()); ) {
        maxX = max(maxX, intersect_pair(N[itrN], M[itrM]));
        if (N[itrN].first < M[itrM].first) {
            ++itrN;
        } else {
            ++itrM;
        }
    }


    write_test(maxX, n, N, m, M);
}

void run(int seed, int n, vector<int> nLimits, int m, vector<int> mLimits, int algorithm) {
    cerr << "runing on test\t" << test_number << '\n';
    if (algorithm == 0) {
        generate_test(seed, n, nLimits, m, mLimits, *linear_element_generator);
    } else {
        generate_test(seed, n, nLimits, m, mLimits, *logaritmic_element_generator);
    }
}

string read(string location) {
    ifstream fin(location.c_str());
    string rez, aux;
    while (fin >> aux) {
        rez += aux;
        rez += '#';
    }
    return rez;
}

int main() {
    vector<tuple<int, int, int, int, int, int, int, int> > testData = {
        {666010,    1e2,    1e1,    1e5,    1e4,    1e1,    1e3,    1},
        {666011,    5e2,    1e3,    1e4,    1e4,    1e1,    1e4,    1},
        {666012,    1e3,    1e2,    1e5,    1e5,    1e1,    1e3,    1},
        {666013,    5e3,    1e3,    1e5,    1e5,    1e1,    1e3,    1},
        {666014,    1e4,    1e2,    1e5,    1e4,    1e3,    1e5,    1},
        {666015,    5e4,    1e2,    1e4,    1e5,    1e3,    1e4,    1},
        {666016,    1e5,    1e2,    1e4,    1e5,    1e3,    1e4,    1},
        {666017,    1e5,    1e1,    1e4,    1e5,    1e3,    1e4,    1},
        {666018,    1e5,    1e3,    1e4,    1e5,    1e2,    1e4,    1},
        {666019,    1e5,    1e2,    1e4,    1e5,    1e1,    1e4,    1}
    };

    // unit testing
    for (int j = 0; j < 1; j++) {
        for (int i = 0; i < int(testData.size()); ++i) {
            int seed, n, nLimitA, nLimitB, m, mLimitA, mLimitB, type;
            tie(seed, n, nLimitA, nLimitB, m, mLimitA, mLimitB, type) = testData[i];
            seed += j * 100;
            test_number = i + 1;
            run(seed, n, {nLimitA, nLimitB}, m, {mLimitA, mLimitB}, type);

            vector<string> results;
            for (auto source_name : good_sources) {
                system(("./" + source_name).c_str());
                results.push_back(read("licenta.out"));
            }

            for (auto itr : results) {
                if (itr != results[0]) {
                    cerr << "ERROOORRR\n";
                    system("mv licenta.in error.in");
                    exit(0);
                }
            }

            system(("mv licenta.out grader_test" + to_string(test_number) + ".ok").c_str());
            system(("mv licenta.in grader_test" + to_string(test_number) + ".in").c_str());
        }
    }
    return 0;
}

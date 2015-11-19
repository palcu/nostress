#include <cmath>
#include <cassert>

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define int64 long long

const int kMaxN = 1e5, kMaxVal = 1e9;
const int64 kMaxB = 1e15;

const vector<string> good_sources = {"buget_velea", "buget_scipianus_NlogValmax"};

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

void write_test(int n, int64 b, vector<int> values) {
    assert(1 <= n and n < kMaxN);
    assert(0 <= b and b < kMaxB);
//    string test_location = to_string(test_number) + ".in";
    string test_location = "buget.in";

    ofstream fout(test_location.c_str());
    fout << n << ' ' << b << '\n';
    random_shuffle(values.begin(), values.end());
    for (auto itr : values) {
        assert(1 <= itr and itr < kMaxVal);
        fout << itr << ' '; 
    }
    
}

template<typename Function>
void generate_test(int seed, int n, Function element_generator) {
    srand(seed);
    vector<int> values;
   
   vector<int64> sum(n);
    for (int i = 0; i < n; ++i) {
        values.push_back(element_generator());
    }

    sort(values.begin(), values.end());

    sum[0] = 1LL * values[0] * n;
    for (int i = 1; i < n; ++i) {
        sum[i] = sum[i - 1] + 1LL * (values[i] - values[i - 1]) * (n - i);
    }
    
    int64 b = sum[rand() % (n - 1)];
    b += rand() % (sum[n - 1] - b);
    write_test(n, b, values);     
}

void run(int seed, int n, int algorithm) {
    cerr << "runing on test\t" << test_number << '\n';
    if (algorithm == 0) {
        generate_test(seed, n, *linear_element_generator);
    } else {
        generate_test(seed, n, *logaritmic_element_generator);
    }
}

string read(string location) {
    ifstream fin(location.c_str());
    string rez, aux;
    while (fin >> aux) {
        rez += aux;
        rez += '#';
    }
    return rez;;
}

int main() {
    vector<tuple<int, int, int, int, int> > testData = {
        {666010,    1e2,    0,  1e1, 1e6},
        {666011,    2e2,    1,  1e3, 1e6},
        {666012,    1e3,    0,  1e1, 1e4},
        {666013,    1e3,    1,  1e3, 1e4},
        {666014,    5e3,    0,  1e1, 1e7},
        {666015,    5e3,    1,  1e5, 1e7},
        {666016,    4e4,    0,  1e1, 1e9},
        {666017,    4e4,    1,  1e5, 1e9},
        {666018,    9e4,    0,  1e1, 1e9},
        {666019,    9e4,    1,  1e6, 1e9}
    };

// unit testing
for (int j = 0; j < 1; j++) {

    for (int i = 0; i < int(testData.size()); ++i) {
        int seed, n, type, limitA, limitB;
        tie(seed, n, type, limitA, limitB) = testData[i];
        seed += j * 100;
        limit = {limitA, limitB};
        test_number = i + 1;
        run(seed, n, type);

        vector<string> results;
        for (auto source_name : good_sources) {
            system(("./" + source_name).c_str());
            results.push_back(read("buget.out"));
        }
        
        for (auto itr : results) {
            if (itr != results[0]) {    
                cerr << "ERROOORRR\n";
                system("mv buget.in error.in");
                exit(0);
            }
        }
        
        system(("mv buget.out grader_test" + to_string(test_number) + ".ok").c_str());
        system(("mv buget.in grader_test" + to_string(test_number) + ".in").c_str());
    }
}
    return 0;
}

// Alex Velea
// O(N) + O(rez)
// + parsare

#include <algorithm>
#include <fstream>
#include <vector>
using namespace std;                                                                        

#define int64 long long 

vector<int> values;

ifstream fin("buget.in");
ofstream fout("buget.out");
/*
    1e5 int32   fin     0.06s   read    0.012s  optimization    0.048
    1e6 int32   fin     0.56s   read    0.1s    optimization    0.46 
    1e7 int32   fin     4.89s   read    0.79s   optimization    4.1
    1e8 int32   fin     49.230s read    7.836s  optimization    41.3
*/

const int kBufferSize = 1e4;
int bufferInd = kBufferSize;
char buffer[kBufferSize];

void nextChar() {
    if (++bufferInd >= kBufferSize) {
        fin.read(buffer, kBufferSize);
        bufferInd = 0;
    }
}

bool valid(char c) {
    return (c == '-' or ('0' <= c and c <= '9'));
}

char currentChar() {
    if (bufferInd > kBufferSize) {
        nextChar();
    }
    return buffer[bufferInd];
}

template<typename number>
void readNumber(number &a) {
    a = 0;
    bool signedNumber = false;
    if (currentChar() == '-') {
        signedNumber = true;
    }

    for (; not valid(currentChar()); nextChar())
        ;

    for (; valid(currentChar()); nextChar()) {
        a *= 10;
        a += currentChar() - '0';
    }

    if (signedNumber) {
        a *= -1;
    }
    return ;
}


int main() {
    int n; int64 b; readNumber(n), readNumber(b);
    // int n; int64 b; fin >> n >> b;
    for (int i = 0; i < n; ++i) {
        int x; readNumber(x);
        // int x; fin >> x;
        values.push_back(x);
    }

    sort(values.begin(), values.end());

    int64 sum = 0, where = 0;

    for (int d = 0; ; ++d) {
        while (d == values[where]) {
            sum += values[where];
            where += 1;
        }       
        if (sum + 1LL * (n - where) * d > b) {
            fout << d - 1 << '\n';
            exit(0);
        }
    }
    return 0;
}

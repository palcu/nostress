#include <fstream>
#include <vector>
using namespace std;

ifstream fin("zeul.in");
ofstream fout("zeul.out");

// #########	parsare
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

// #########	endParsare

const int kMaxN = 1e5 + 5;

int inside[kMaxN];

int main() {
    int n, m; readNumber(n); readNumber(m);
    while (m--) {
        int a, b; readNumber(a); readNumber(b);
        inside[a]--;
        inside[b]++;
    }
    vector<int> A, B;
    for (int i = 1; i <= n; ++i) {
        while (inside[i] > 0) {
            --inside[i];
            A.push_back(i);
        }
        while (inside[i] < 0) {
            ++inside[i];
            B.push_back(i);
        }
    }

    fout << A.size() << '\n';
    for (int i = 0; i < int(A.size()); i += 1) {
        fout << A[i] << ' ' << B[i] << '\n';
    }

    return 0;
}
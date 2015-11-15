/***************************************************
 * Ciprian Olariu
 * FMI No Stress 2015 - licenta - 100 puncte O(N log N)
 * ciprian [dot] olariu05 [at] gmail [dot] com
****************************************************/
#include <fstream>
#include <algorithm>
#define pii pair<int, int>
using namespace std;
int n1, n2, K;
pii a[100100], b[100100], sol;

inline pii Intersect(pii A, pii B)
{
	pii rez = make_pair(max(A.first, B.first), min(A.second, B.second));
	if(rez.first > rez.second)
		return make_pair(-1, -1);
	return rez;
}

int main()
{
	int i, j;
	pii now;
	ifstream fin("licenta.in");
	fin >> K;
	fin >> n1;
	for(i = 1; i <= n1; ++i)
		fin >> a[i].first >> a[i].second;
	fin >> n2;
	for(i = 1; i <= n2; ++i)
		fin >> b[i].first >> b[i].second;
	fin.close();
	
	sort(a + 1, a + n1 + 1);
	sort(b + 1, b + n2 + 1);
	sol.first = sol.second = -1;
	for(i = j = 1; i <= n1 && j <= n2; ++i)
	{
		while(j <= n2 && b[j].second < a[i].first)
			j++;
		if(j > n2)
			break;
		now = Intersect(a[i], b[j]);
		if(now.first == -1)
			continue;
		if(now.second - now.first >= K)
		{
			sol = make_pair(now.first, now.first + K);
			break;
		}
	}
	
	ofstream fout("licenta.out");
	if(sol.first >= 0)
		fout << sol.first << ' ' << sol.second << "\n";
	else
		fout << "-1\n";
	fout.close();
	return 0;
}

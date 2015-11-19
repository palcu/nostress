/***************************************************
 * Ciprian Olariu
 * FMI No Stress 2015 - buget - O(N log Valmax)
 * ciprian [dot] olariu05 [at] gmail [dot] com
****************************************************/
#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("buget.in");
int n;
long long B, v[1000100], maxim;

inline bool Ok(long long plafon)
{
	if(1LL * plafon * n <= B)
		return true;
	long long sum = 0LL;
	for(int i = 1; i <= n; ++i)
	{
		sum += min(v[i], plafon);
		if(sum > B)
			return false;
	}
	return (sum <= B);
}

inline long long BinarySearch()
{
	long long st, dr, mij, rez;
	st = rez = 0LL;
	dr = maxim;
	while(st <= dr)
	{
		mij = st + (dr - st) / 2LL;
		if(Ok(mij))
		{
			rez = mij;
			st = mij + 1LL;
		}
		else
			dr = mij - 1LL;
	}
	return rez;
}

int main()
{
	int i;
	fin >> n >> B;
	for(i = 1; i <= n; ++i)
	{
		fin >> v[i];
		maxim = max(maxim, v[i]);
	}
	fin.close();
	
	ofstream fout("buget.out");
	fout << BinarySearch() << "\n";
	fout.close();
	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main()
{
	int n = 0;
	scanf("%d", &n);

	v.resize(n, 0);

	for (int i = 1; i <= n; ++i)
		v[i-1] = i;

	do
	{
		for (int i = 0; i < n; ++i)
			printf("%d ", v[i]);
		printf("\n");
	} while (next_permutation(v.begin(), v.end()));
}
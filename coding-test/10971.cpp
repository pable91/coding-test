#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> v;
int MIN = 1000000000;

int main()
{
	int n = 0;
	cin >> n;

	v.resize(n + 1, vector<int>(n + 1, 0));

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> v[i][j];
		}
	}

	vector<int> vec;
	for (int i = 0; i < n; ++i)
		vec.push_back(i + 1);

	do
	{
		int sum = 0; 
		bool check = false;
		int k = 0;
		for (k = 0; k < n - 1; ++k) {
			if (v[vec[k]][vec[k + 1]] == 0)
				check = true;
			else sum += v[vec[k]][vec[k + 1]];
		}
		
		if (check == false && v[vec[n - 1]][vec[0]] != 0) {
			sum += v[vec[n - 1]][vec[0]];
			if (MIN > sum)
				MIN = sum;
		}

	} while (next_permutation(vec.begin(), vec.end()));

	cout << MIN << endl;
}
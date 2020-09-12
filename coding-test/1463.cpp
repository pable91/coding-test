#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 1000001;

vector<int> dp;

int func(int n)
{
	if (n == 1) return 0;
	if (dp[n] != -1) return dp[n];

	int result = func(n - 1) + 1;
	if (n % 3 == 0) result = min(result, func(n / 3) + 1);
	if (n % 2 == 0) result = min(result, func(n / 2) + 1);
	dp[n] = result;

	return result;
}

int main()
{
	int n;
	cin >> n;
	
	dp.resize(MAX, -1);

	func(n);

	cout << dp[n] << endl;
}
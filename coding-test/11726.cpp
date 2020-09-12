#include <iostream>
#include <vector>

using namespace std;
vector<int> dp;

int func(int n)
{
	if (n == 1) return 1;
	if (n == 2) return 2;

	if (dp[n] != -1) return dp[n];
	  
	return dp[n] = (func(n - 1) + func(n - 2)) % 10007;
}
int main()
{

	int n = 0;
	cin >> n;

	dp.resize(1001, -1);

	cout << func(n) << endl;
}
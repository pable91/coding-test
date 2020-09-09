#include <iostream>
#include <queue>

using namespace std;

vector<vector<int>> v;
queue<pair<int, int>> q;
int answer = 0;
int n, m = 0;
int dy[8] = {1,1,0,-1,-1,-1,0,1};
int dx[8] = {0,1,1,1,0,-1,-1,-1};

void BFS(int y, int x)
{
	v[y][x] = 0;
	q.push({ y, x });
	answer += 1;

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int k = 0; k < 8; k++)
		{
			int yy = y + dy[k];
			int xx = x + dx[k];
			if (yy >= 0 && yy < m && xx >= 0 && xx < n)
			{
				if (v[yy][xx] == 1)
				{
					v[yy][xx] = 0;
					q.push({ yy,xx });
				}
			}
		}
	}
}

int main()
{
	while (1) {
		cin >> n >> m;

		if (n == 0 && m == 0)
			return 0;

		v.resize(m, vector<int>(n, 0));

		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> v[i][j];
			}
		}

		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (v[i][j] == 1) {
					BFS(i, j);
				}
			}
		}

		cout << answer << endl;
		answer = 0;

		v.clear();
	}
}
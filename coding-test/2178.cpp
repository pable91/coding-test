#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int x = 0, y = 0;

vector<string> v;
vector<vector<int>> check;
queue<pair<int, int>> q;

int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,-1,1};

int answer = 0;
void BFS(int _y, int _x)
{
	v[_y][_x] = '0';
	q.push({ _y,_x });
	answer += 1;

	while (!q.empty()) {
		answer += 1;
		int qsize = q.size();
		for (int k = 0; k < qsize; k++)
		{
			int yy = q.front().first;
			int xx = q.front().second;
			q.pop();

			for (int i = 0; i < 4; ++i)
			{
				if (yy + dy[i] >= 0 && yy + dy[i] < y &&
					xx + dx[i] >= 0 && xx + dx[i] < x) {
					if (v[yy + dy[i]][xx + dx[i]] == '1') {
						v[yy + dy[i]][xx + dx[i]] = '0';
						check[yy + dy[i]][xx + dx[i]] = answer;
						q.push({ yy + dy[i], xx + dx[i] });
					}
				}
			}

		}
	}
}

int main()
{
	cin >> y >> x;

	v.resize(y);
	check.resize(y);

	for (int i = 0; i < y; ++i)
	{
		check[i].resize(x, 0);
	}

	string str;
	for (int i = 0; i < y; ++i) {
		cin >> str;
		v[i] = str;
	}

	for (int i = 0; i < y; ++i) {
		for (int j = 0; j < v[i].size(); ++j) {
			if (v[i][j] == '1')
				BFS(i, j);
		}
	}

	cout << check[y-1][x-1] << endl;
}
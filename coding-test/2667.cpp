#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
vector<vector<char>> v;
vector<int> answer;
queue<pair<int, int>> q;
int n;
char str[25];

int cnt;


void DFS(int i, int j)
{
	cnt += 1;
	v[i][j] = '0';

	// 위
	if (i + 1 < n && v[i + 1][j] == '1')
		DFS(i + 1, j);
	// 아래
	if (i - 1 >= 0 && v[i - 1][j] == '1')
		DFS(i - 1, j);
	// 오른쪽
	if (j + 1 < n && v[i][j + 1] == '1')
		DFS(i, j + 1);
	// 왼쪽
	if (j - 1 >= 0 && v[i][j - 1] == '1')
		DFS(i, j - 1);
}

int dy[4] = {1, -1, 0, 0 };
int dx[4] = {0, 0, 1, -1};

void BFS(int i, int j)
{
	q.push({ i, j });
	cnt += 1;
	v[i][j] = '0';

	while (!q.empty())
	{
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			for (int k = 0; k < 4; ++k)
			{
				int nx = x + dx[k], ny = y + dy[k];
				if (ny < n && nx >= 0 && ny >= 0 && nx < n )
				{
					if (v[ny][nx] == '1') {
						q.push({ ny ,nx });
						cnt += 1;
						v[ny][nx] = '0';
					}
				}
			}
			//if (y + 1 < n && v[y + 1][x] == '1') {
			//	q.push({ y + 1, x });
			//	v[y + 1][x] = '0';
			//	cnt += 1;
			//}
			//// 아래
			//if (y - 1 >= 0 && v[y - 1][x] == '1') {
			//	q.push({ y - 1, x });
			//	v[y - 1][x] = '0';
			//	cnt += 1;
			//}
			//// 오른쪽
			//if (x + 1 < n && v[y][x + 1] == '1') {
			//	q.push({ y, x + 1 });
			//	v[y][x + 1] = '0';
			//	cnt += 1;
			//}
			//// 왼쪽
			//if (x - 1 >= 0 && v[y][x - 1] == '1') {
			//	q.push({ y, x - 1 });
			//	v[y][x - 1] = '0';
			//	cnt += 1;
			//}
		
	}
}

void solution() 
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cnt = 0;
			if (v[i][j] == '1') {
				BFS(i, j);	
				//DFS(i, j);
				answer.push_back(cnt);
			}
		}
	}

	sort(answer.begin(), answer.end());

	cout << answer.size() << endl;
	for (auto elem : answer)
		cout << elem << endl;
}

int main()
{
	cin >> n;

	v.resize(n, vector<char>(n,0));
	
	for (int i = 0; i < n; ++i) {
		cin >> str;
		//scanf("%s", &str);
		for (int j = 0; j < n; ++j) {
			v[i][j] = str[j];
		}
	}

	solution();
}
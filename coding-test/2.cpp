#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> v;
vector<bool> visit;
queue<int> q;
queue<int> q2;

const int MAX = 100001;
int cnt = 0;

void bfs(int i) 
{
	visit[i] = true;
	q.push(i);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		int size = v[cur].size();
		for (int i = 0; i < size; ++i) {
			int next = v[cur][i];
			if (!visit[next]) {
				visit[next] = true;
				q.push(next);
			}
		}
	}
}

int main() {
	int N;
	cin >> N;

	v.resize(MAX);
	visit.resize(MAX, false);

	for (int i = 0; i < N; ++i) {
		int x, y = 0;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
		q2.push(x);
		q2.push(y);
	}

	while(!q2.empty()){
		int n = q2.front();
		q2.pop();
		if (!visit[n]) {
			cnt += 1;
			bfs(n);
		}
	}

	cout << cnt << endl;
}
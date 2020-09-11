#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

const int MAX = 100005;
bool visit[MAX] = { false, };
int dist[MAX] = { 0, };
queue<int> q;

int n, m = 0;

void BFS(int n)
{
	visit[n] = true;
	dist[n] = 0;
	q.push(n);

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		if (now - 1 >= 0) {
			if (visit[now - 1] == false) {
				q.push(now - 1);
				visit[now - 1] = true;
				dist[now - 1] = dist[now] + 1;
			}
		}
		if (now + 1 < MAX) {
			if (visit[now + 1] == false) {
				q.push(now + 1);
				visit[now + 1] = true;
				dist[now + 1] = dist[now] + 1;
			}
		}
		if (now * 2 < MAX) {
			if (visit[now * 2] == false) {
				q.push(now * 2);
				visit[now * 2] = true;
				dist[now * 2] = dist[now] + 1;
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	BFS(n);

	cout << dist[m] << endl;
}
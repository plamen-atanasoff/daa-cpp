#include <iostream>
#include <vector>
#include <deque>
#include <utility>
#include <climits>
using namespace std;

namespace {
	const int MAX = 200'007;

	int n, start, finish;

	vector<pair<int , int> > adj[MAX];
	bool visited[MAX];
	int d[MAX];
}

static void bfs(int s) {
	deque<int> q;
	q.push_back(s);
	fill(d, d + n + 7, INT_MAX / 2);
	d[s] = 0;
	while (!q.empty()) {
		int p = q.front();
		q.pop_front();
		if (visited[p]) continue;

		visited[p] = true;
		for (auto& y : adj[p]) {
			if (d[y.first] > d[p] + y.second) {
				d[y.first] = d[p] + y.second;

				if (y.second == 0) {
					q.push_front(y.first);
				}
				else if (y.second == 1) {
					q.push_back(y.first);
				}
			}
		}
	}
}

void town() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> start >> finish;
	int p, q;
	while (cin >> p >> q) {
		adj[p].push_back({ q, 0 });
		adj[q].push_back({ p, 1 });
	}

	bfs(start);

	if (d[finish] == INT_MAX / 2) cout << "X";
	else cout << d[finish];
	cout << endl;
}
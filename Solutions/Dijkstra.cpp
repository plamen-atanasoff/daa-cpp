#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>
using namespace std;

namespace {
	const int MAX = 1007;
	int n, m, s;
	// pair represents an edge where pair.first is w and pair.second is v;
	vector<pair<int, int> > adj[MAX];
	int d[MAX];
	bool visited[MAX];
}

void dijkstra() {
	cin >> n >> m;
	int u, v, w;
	for (int i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		// graph is not directed
		adj[u].push_back({w, v});
		adj[v].push_back({w, u});
	}
	cin >> s;

	fill(d, d + MAX, INT_MAX);
	d[s] = 0;

	// pair represents an edge where pair.first is w and pair.second is v;
	priority_queue<pair<int, int> > pq;
	pq.push({ d[s], s });
	while (!pq.empty()) {
		int p = pq.top().second;
		pq.pop();
		if (visited[p]) continue;
		visited[p] = true;

		for (auto& y : adj[p]) {
			if (d[y.second] > d[p] + y.first) {
				d[y.second] = d[p] + y.first;
				pq.push({ -d[y.second], y.second }); // push negative value to simulate min priority queue
			}
		}
	}

	for (int i = 0; i < n; i++) cout << d[i] << " ";
	cout << endl;
}
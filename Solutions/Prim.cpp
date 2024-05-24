#include <iostream>
#include <vector>
#include <queue>
using namespace std;

namespace {
	const int MAX = 1000005;

	struct edge {
		int to, w;
		bool operator<(edge other) {
			return w > other.w;
		}
	};

	bool operator<(const edge& lhs, const edge& rhs) {
		return lhs.w > rhs.w;
	}

	int n, m, sum;

	bool added[MAX];
	vector<edge> adj[MAX];

	vector<edge> res;
}

void prim() {
	cin >> n >> m;
	int a, b, w;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b >> w;
		adj[a].push_back({ b, w });
		adj[b].push_back({ a, w });
	}

	priority_queue<edge> pq;
	added[1] = 1; // could be any node
	for (edge& e : adj[1]) { // no loops(loop is an edge that connects a node with itself, cycle and loop are different)
		pq.push(e);
	}

	while (!pq.empty()) {
		edge p = pq.top();
		pq.pop();
		if (added[p.to]) continue;
		added[p.to] = true;
		res.push_back(p);
		sum += p.w;
		for (edge& y : adj[p.to]) {
			pq.push(y);
		}
	}

	if (res.size() == n - 1) cout << sum;
	else cout << "Graph is not connected";
	cout << endl;
}
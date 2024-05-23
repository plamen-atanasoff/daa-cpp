// https://arena.olimpiici.com/api/public/problems/881/pdf

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

namespace {
	constexpr int MAX = 10'007;
	int n, m;
	vector<pair<int, bool> > neighbours[MAX];
	bool visited[MAX];
	vector<pair<int, bool> > currVisited;
	bool h[MAX];
}

void bfs(int s) {
	currVisited.clear();
	queue<pair<int, bool> > q;
	q.push({ s, true });
	visited[s] = true;

	while (!q.empty()) {
		pair<int, bool> x = q.front();
		q.pop();
		currVisited.push_back(x);

		for (const auto& y : neighbours[x.first]) {
			if (!visited[y.first]) {
				q.push({ y.first, x.second ? y.second : !y.second });
				visited[y.first] = true;
			}
		}
	}
}

size_t getCount() {
	size_t hCtr = 0;
	for (const auto& x : currVisited) {
		if (x.second) hCtr++;
	}

	return hCtr < currVisited.size() / 2 ? currVisited.size() - hCtr : hCtr;
}

void honest() {
	cin >> n >> m;
	char c;
	int x, y;
	for (int i = 1; i <= m; i++) {
		cin >> x >> c >> y;
		neighbours[x].push_back({ y, c == 'h' ? true : false });
		neighbours[y].push_back({ x, c == 'h' ? true : false });
	}

	size_t res = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			bfs(i);
			res += getCount();
		}
	}

	cout << res << endl;
}

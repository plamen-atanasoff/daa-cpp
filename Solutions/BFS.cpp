#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

namespace {
	int n, m;
	vector<int> neighbours[100];
	bool visited[100];
}

void bFS() {
	cin >> n >> m;
	int u, v;
	for (int i = 1; i <= m; i++) {
		cin >> u >> v;
		neighbours[u].push_back(v);
		neighbours[v].push_back(u);
	}

	for (int i = 0; i < 100; i++) {
		sort(neighbours[i].begin(), neighbours[i].end());
	}

	queue<int> nodes;
	nodes.push(0);
	visited[0] = true;
	while (!nodes.empty()) {
		int x = nodes.front();
		nodes.pop();
		cout << x << " ";
		for (auto y : neighbours[x]) {
			if (!visited[y]) {
				visited[y] = true;
				nodes.push(y);
			}
		}
	}
	cout << endl;
}
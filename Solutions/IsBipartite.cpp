#include <iostream>
#include <vector>
using namespace std;

namespace {
	constexpr int MAX = 105;
	int n, m;
	vector<int> neighbours[MAX];
	bool visited[MAX];
	bool colour[MAX];

	bool flag = true;
}

static void dfs(int s) {
	visited[s] = true;
	for (int y : neighbours[s]) {
		if (!visited[y]) {
			colour[y] = 3 - colour[s];
			dfs(y);
		}
		else {
			if (colour[s] == colour[y]) {
				flag = false;
				return;
			}
		}
	}
}

void isBipartite() {
	cin >> n >> m;
	int x, y;
	for (int i = 1; i <= m; i++) {
		cin >> x >> y;
		neighbours[x].push_back(y);
		neighbours[y].push_back(x);
	}

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			colour[i] = 1;
			dfs(i);
		}
	}

	cout << flag << endl;
}

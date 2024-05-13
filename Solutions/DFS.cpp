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

void dFSRec(int node) {
	visited[node] = true;
	cout << node << " ";
	for (int y : neighbours[node]) {
		if (!visited[y]) {
			dFSRec(y);
		}
	}
}

int main() {
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

	dFSRec(0);
	cout << endl;
}
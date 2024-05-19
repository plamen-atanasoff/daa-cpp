#include <iostream>
#include <vector>
using namespace std;

namespace {
	constexpr int MAX = 10'000;
	int n, m, k;
	vector<int> neighbours[MAX];
	bool visited[100][100];
	int ccount;
}

void DFS(int x, int y) {
	visited[x][y] = true;
	for (int z : neighbours[x * m + y]) {
		if (!visited[z / m][z % m]) {
			DFS(z / m, z % m);
		}
	}
}

void viruses() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m >> k;
	int x, y;
	for (int i = 1; i <= k; i++) {
		cin >> x >> y;
		visited[x - 1][y - 1] = true;
	}

	for (int i = 0; i < n * m; i++) {
		int row = i / m;
		int col = i % m;
		if (row + 1 < n) {
			neighbours[i].push_back(i + m);
		}
		if (row - 1 >= 0) {
			neighbours[i].push_back(i - m);
		}
		if (col + 1 < m) {
			neighbours[i].push_back(i + 1);
		}
		if (col - 1 >= 0) {
			neighbours[i].push_back(i - 1);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j]) {
				ccount++;
				DFS(i, j);
			}
		}
	}

	cout << ccount << endl;
}
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

namespace {
	constexpr int MAX = 1024;

	int n, m;
	vector<int> neighbours[MAX];
	bool visited[MAX];

	int root[MAX];
	int depth[MAX];

	int edges[MAX];
}

static void bfs(int s) {
	queue<int> q;
	visited[s] = true;
	q.push(s);
	while (!q.empty()) {
		int node = q.front();
		cout << node << " ";
		q.pop();
		for (int y : neighbours[node]) {
			if (!visited[y]) {
				visited[y] = true;
				q.push(y);
			}
		}
	}
	cout << endl;
}

static void dfsRec(int s) {
	visited[s] = true;
	cout << s << " ";
	for (int y : neighbours[s]) {
		if (!visited[y]) {
			dfsRec(y);
		}
	}
}

static void dfs(int s) {
	dfsRec(s);
	cout << endl;
}

static int find(int x) {
	if (root[x] == -1) {
		return x;
	}

	return root[x] = find(root[x]);
}

static void uni(int x, int y) {
	int rootX = find(x);
	int rootY = find(y);
	if (rootX == rootY) return;

	if (depth[rootX] > depth[rootY]) {
		root[rootY] = rootX;
	}
	else {
		root[rootX] = rootY;
		if (depth[rootX] == depth[rootY]) depth[rootY]++;
	}
}

static vector<int> toposort() {
	queue<int> q;
	vector<int> res;

	for (int i = 0; i < n; i++) {
		for (int y : neighbours[i]) {
			edges[y]++;
		}
	}

	for (int i = 0; i < n; i++) {
		if (edges[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int node = q.front();
		q.pop();
		res.push_back(node);
		for (int y : neighbours[node]) {
			edges[y]--;
			if (edges[y] == 0) q.push(y);
		}
	}

	if (res.size() == n) {
		return res;
		for (int x : res) {
			cout << x << " ";
		}
		cout << endl;
	}
	else {
		return vector<int>();
	}
}

void init() {
	cin >> n >> m;
	int a, b;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		neighbours[a].push_back(b);
		neighbours[b].push_back(a);
	}
}

void initToposort() {
	cin >> n >> m;
	int a, b;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		neighbours[a].push_back(b);
	}
}

void test() {
	//init();
	//bfs(0);
	//dfs(0);

	fill(root, root + MAX, -1);

	initToposort();
	vector<int> res = toposort();


}

// BFS and DFS example:
// 6 7
// 0 2
// 0 4
// 0 5
// 1 5
// 2 3
// 2 4
// 4 5
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace {
	constexpr int MAX_NODES = 1000;

	struct Edge {
		int lake1;
		int lake2;
		int width;

		bool operator<(const Edge& other) {
			return other.width < width;
		}
	};

	int n, m, k;
	int ctr;
	std::vector<Edge> edges;
	std::vector<Edge> mst; // minimal spanning tree
	
	int nodesRoots[MAX_NODES];
	int nodesComponentsDepth[MAX_NODES];
}

static int find(int node) {
	if (nodesRoots[node] == 0) {
		return node;
	}

	return find(nodesRoots[node]);
}

static bool myUnion(int n1, int n2) {
	int r1 = find(n1);
	int r2 = find(n2);
	if (r1 == r2) return false;

	if (nodesComponentsDepth[r1] > nodesComponentsDepth[r2]) {
		nodesRoots[r2] = r1;
	}
	else if (nodesComponentsDepth[r1] < nodesComponentsDepth[r2]) {
		nodesRoots[r1] = r2;
	}
	else {
		nodesRoots[r2] = r1;
		nodesComponentsDepth[r1]++;
	}

	return true;
}

void channels() {
	cin >> n >> m;
	edges.reserve(m);
	int u, v, w;
	for (int i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		edges.push_back({ u, v, w });
	}
	cin >> k;

	sort(edges.begin(), edges.end());

	mst.reserve(n - 1);
	for (int i = 0; i < m; i++) {
		if (myUnion(edges[i].lake1, edges[i].lake2)) {
			mst.push_back(edges[i]);
		}
		if (mst.size() == n - 1) {
			break;
		}
	}

	for (int i = 0; i < n - 1; i++) {
		if (k > mst[i].width) {
			ctr++;
		}
	}

	cout << ctr << endl;
}
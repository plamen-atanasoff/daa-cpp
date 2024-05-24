#include <iostream>
using namespace std;

namespace {
	constexpr int MAX = 1'000'000;
	int n, m;
	int s[MAX], arr[MAX];
}

int find(int x) {
	if (arr[x] == -1) {
		return x;
	}

	return arr[x] = find(arr[x]);
}

void myUnion(int x, int y, int& ccount) {
	int rX = find(x);
	int rY = find(y);
	if (rX == rY) return;

	ccount--;

	if (s[rX] < s[rY]) {
		arr[rX] = rY;
	}
	else {
		arr[rY] = rX;
		if (s[rX] == s[rY]) s[rX]++;
	}
}

void countComponents() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	fill(arr, arr + MAX, -1);

	cin >> n >> m;
	int x, y;
	int ccount = n;
	for (int i = 1; i <= m; i++) {
		cin >> x >> y;
		myUnion(x, y, ccount);
	}

	cout << ccount << endl;
}
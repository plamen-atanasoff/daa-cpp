#include <iostream>
using namespace std;

namespace {
	constexpr int MAX = 5007;
	int n;
	int field[MAX][MAX];

	constexpr pair<int, int> pos[] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
}

bool iceExists() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (field[i][j] > 0) return true;
		}
	}

	return false;
}

void meltIce() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (field[i][j] == 0) continue;

			int ctr = 0;
			for (const auto& p : pos) {
				if (field[i + p.first][j + p.second] == 0) {
					ctr++;
				}
			}
			if (ctr >= 2) {
				field[i][j] = -1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (field[i][j] == -1) field[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << field[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void ice() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	char c;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> c;
			field[i][j] = c == '1' ? 1 : 0;
		}
	}
	cout << endl;

	int ctr = 0;
	while (iceExists()) {
		ctr++;
		meltIce();
	}

	cout << ctr << endl;
}
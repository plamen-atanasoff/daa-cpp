#include <iostream>
using namespace std;

namespace {
	const int SIZE = 300'000;
	long long n, r, i, j, cnt;
	long long arr[SIZE];
}

void monumentDistance() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// entries are sorted in ascending order
	cin >> n >> r;
	for (i = 0; i < n; i++) cin >> arr[i];

	for (i = 0; i < n - 1; i++) {
		while (j < n && arr[j] - arr[i] <= r) j++;
		cnt += n - j;
	}

	cout << cnt;
}
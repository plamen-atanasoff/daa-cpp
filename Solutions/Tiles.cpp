// There are two tile workers:
// worker1 puts A tiles per day and rests one every K-th day,
// worker2 puts B tiles per day and rests one every M-th day.
// How many days are needed for both workers to put X tiles?
// 1 <= A, B <= 10^9
// 2 <= K, M <= 10^18
// 1 <= X <= 10^18

#include <iostream>
using namespace std;

namespace {
	long long A, K, B, M, X;
}

static long long calculateTiles(long long days) {
	return (days * A - (days / K) * A) + (days * B - (days / M) * B);
}

void tiles() {
	cin >> A >> K >> B >> M >> X;

	long long l = 1;
	long long r = (2 * X) / (A + B) + 1;
	while (l < r) {
		long long mid = l + (r - l) / 2;
		if (calculateTiles(mid) >= X) {
			r = mid;
		}
		else {
			l = mid + 1;
		}
	}

	cout << l << endl;
}
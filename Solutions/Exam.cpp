// N and F are given, where F is the faculty number of the first student on the line;
// if the consecutive sum of all students' faculty numbers becomes >= of N,
// the next student in line is given an excellent grade and the sum becomes 0;
// find the count of students needed before the first excellent grade is given;
// 1 <= N <= 1e18; 1 <= F <= 1e5

#include <iostream>
using namespace std;

namespace {
	long long N, F;
}

// sum of m integers from f is (m/2)*(2f + (m-1))
static long long sum(long long m) {
	return F * (m - 1) + (m - 2) * (m - 1) / 2;
}

void exam() {
	cin >> N >> F;

	long long l = 1;
	long long r = 2e9; // big enough number
	while (l < r) {
		long long mid = l + (r - l) / 2;
		if (sum(mid) < N) {
			l = mid + 1;
		}
		else {
			r = mid;
		}
	}

	cout << l - 1 << endl;
}
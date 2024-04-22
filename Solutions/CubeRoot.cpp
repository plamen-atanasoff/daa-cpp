#include <iostream>
#include <iomanip>
using namespace std;

namespace {
	double x, l, r, mid;
}

void cubeRoot() {
	cin >> x;

	r = max(double(1), x);
	for (int i = 0; i < 100; i++) {
		mid = l + (r - l) / 2;
		if (mid * mid * mid >= x) {
			r = mid;
		}
		else {
			l = mid;
		}
	}

	cout << setprecision(20) << l << endl;
}
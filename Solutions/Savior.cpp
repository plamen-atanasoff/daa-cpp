#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

namespace {
	int T;
	double x1, y, x2, y2, v1, v2;
}

double calcTimeTo(double x) {
	return sqrt(y * y + (x1 - x) * (x1 - x)) * (1.0 / v1) +
		sqrt(y2 * y2 + (x2 - x) * (x2 - x)) * (1.0 / v2);
}

void minTime() {
	double l = min(x1, x2);
	double r = max(x1, x2);

	for (int i = 0; i < 100; i++) {
		double m1 = l + (1.0 / 3) * (r - l);
		double m2 = l + (2.0 / 3) * (r - l);

		double time1 = calcTimeTo(m1);
		double time2 = calcTimeTo(m2);

		if (time1 < time2) {
			r = m2;
		}
		else {
			l = m1;
		}
	}

	cout << fixed << setprecision(5) << calcTimeTo(l) << endl;
}

void savior() {
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> x1 >> y >> x2 >> y2 >> v1 >> v2;
		minTime();
	}
}
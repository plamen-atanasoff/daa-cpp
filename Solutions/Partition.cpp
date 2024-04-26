#include <iostream>
#include <iomanip>
using namespace std;

namespace {
	struct Point {
		double x, y;
	};

	double L, xB, yB, x, y;
}

static double area(const Point& A, const Point& B, const Point& C) {
	return abs((B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y));
}

static Point getMid(const Point& A, const Point& B) {
	Point res;
	res.x = (A.x + B.x) / 2;
	res.y = (A.y + B.y) / 2;

	return res;
}

static Point findPoint(const Point& P, Point A, Point B, double target) {
	Point B1 = B;
	for (int i = 1; i <= 1'000'000; i++) {
		Point M = getMid(A, B);
		double areaBMP = area(B1, M, P);
		if (areaBMP < target) {
			B = M;
		}
		else {
			A = M;
		}
	}

	return getMid(A, B);
}

void partition() {
	Point A, B, C, P;
	A.x = 0;
	A.y = 0;
	C.x = 0;
	cin >> C.y;
	cin >> B.x;
	cin >> B.y;
	cin >> P.x;
	cin >> P.y;

	if (area(A, B, P) == 0) {
		swap(A, C);
	}
	else if (area(A, C, P) == 0) {
		swap(A, B);
	}

	double areaABC = area(A, B, C);
	double areaAPC = area(A, P, C);
	double areaABP = area(A, B, P);

	Point res;
	if (areaAPC > areaABP) {
		res = findPoint(P, A, C, areaABC / 2);
	}
	else {
		res = findPoint(P, A, B, areaABC / 2);
	}

	cout << fixed << setprecision(6) << res.x << " " << res.y << endl;
	
}
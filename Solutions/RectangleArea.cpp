// N rectangles are given with sides parallel to the coordinate axis
// find the area of the figure, created by the rectangles
// coordinates x1, y1 and x2, y2 of the opposite ends of a rectangle are given on every row
// 1 <= N <= 100
// -10'000 <= x,y <= 10'000
// 
// example
// given: 2
//		  1 1 3 3
//		  2 2 4 4
// return: 7

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace {
	struct event {
		int x, y1, y2, type;
		bool operator<(const event& other) const {
			return x < other.x;
		}
	};
	constexpr int MAX_SIZE_LINE = 21'000;
	constexpr int MAX_SIZE_POINTS = 2 * 100;
	constexpr int OFFSET = 10'000;
	int N, area;
	int line[MAX_SIZE_LINE];
	event events[MAX_SIZE_POINTS];
}

static int count() {
	int cnt = 0;
	for (int i = 0; i < MAX_SIZE_LINE; i++) {
		if (line[i] > 0) cnt++;
	}

	return cnt;
}

static void update(int y1, int y2, int type) {
	for (int i = y1; i < y2; i++) line[i] += type;
}

void rectangleArea() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	int a, b, c, d;
	int j = 0;

	for (int i = 1; i <= N; i++) {
		cin >> a >> b >> c >> d;

		a += OFFSET;
		b += OFFSET;
		c += OFFSET;
		d += OFFSET;
		if (c < a) swap(a, c);
		if (d < b) swap(b, d);

		events[j++] = { a, b, d, 1 };
		events[j++] = { c, b, d, -1 };
	}

	sort(events, events + j);

	int lastX = events[0].x;
	for (int i = 0; i < 2*N; i++) {
		const event& e = events[i];

		area += (e.x - lastX) * count();
		update(e.y1, e.y2, e.type);
		lastX = e.x;
	}

	cout << area << endl;
}
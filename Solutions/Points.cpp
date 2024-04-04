#include <iostream>
#include <vector>
#include <algorithm>

constexpr int MAX = 100'000;

struct event {
	int x;
	int type; // 1 for opening of segment, -1 for closing, 0 for point
	int idx;

	bool operator<(const event& other) {
		if (x == other.x) return type > other.type;
		else return x < other.x;
	}
};

int n, m, x1, x2, res[MAX];
std::vector<event> events;

int main() {
	std::cin >> n >> m;
	for (int i = 0; i < n; i++) {
		std::cin >> x1 >> x2;
		if (x1 > x2) std::swap(x1, x2);
		events.push_back({ x1, 1, 0});
		events.push_back({ x2, -1, 0});
	}

	for (int i = 0; i < m; i++) {
		std::cin >> x1;
		events.push_back({ x1, 0, i });
	}

	std::sort(events.begin(), events.end());

	int currentsegmentsCount = 0;
	for (event e : events) {
		currentsegmentsCount += e.type;
		if (e.type == 0) {
			res[e.idx] = currentsegmentsCount;
		}
	}

	for (int i = 0; i < m; i++) {
		std::cout << res[i] << ' ';
	}
	std::cout << std::endl;
}

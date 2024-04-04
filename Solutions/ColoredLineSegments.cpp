#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Event {
	int x;
	// 1 if point is start, -1 if end
	int type;
};

// compare function for std::sort
// returns ​true if the first argument is less than (i.e. is ordered before) the second
bool compare(const Event& p, const Event& q) {
	if (p.x == q.x) return p.type > q.type;
	else return p.x < q.x;
}

int n, a, b;
vector<Event> events;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a >> b;

		events.push_back({a, 1});
		events.push_back({b, -1});
	}

	sort(events.begin(), events.end(), compare);

	int begginingNotOverlappingSegmentX = 0;
	int searchedSegments = 0;
	int curOverlappingCount = 0;
	int maxNotOverlappingSegmentLength = 0;
	for (Event e : events) {
		curOverlappingCount += e.type;
		if (e.type == 1 && curOverlappingCount == 1) {
			searchedSegments++;

			begginingNotOverlappingSegmentX = e.x;
		}
		if (curOverlappingCount == 0) {
			int curLen = e.x - begginingNotOverlappingSegmentX;
			if (curLen > maxNotOverlappingSegmentLength) {
				maxNotOverlappingSegmentLength = curLen;
			}
		}
	}

	cout << searchedSegments << ' ' << maxNotOverlappingSegmentLength << endl;
}

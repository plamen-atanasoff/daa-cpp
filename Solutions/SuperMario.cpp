#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

namespace {
	constexpr int MAX = 10'000'007;
	long long N, K, F, A, B, M;
	long long arr[MAX];
}

void superMario() {
	cin >> N >> K >> F >> A >> B >> M;

	arr[1] = F;
	for (int i = 2; i <= N; i++) {
		arr[i] = (arr[i - 1] * A + B) % M;
	}

	priority_queue<pair<long long, long long>, vector<pair<long long, long long> >, greater<pair<long long, long long> > > pq;
	pq.push({0, 0});
	for (int i = 1; i <= N + 1; i++) {
		while (!pq.empty() && i - K > pq.top().second) pq.pop();

		long long price = arr[i] + pq.top().first;
		pq.push({ price, i });
	}

	cout << pq.top().first << endl;
}
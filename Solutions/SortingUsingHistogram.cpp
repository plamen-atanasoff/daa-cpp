// useful if there are a lot of values and the values are in a smaller range
#include <iostream>
using namespace std;

namespace {
	const int SIZE = 1000;
	int n, num;
	int arr[SIZE];
}

void sortingUsingHistogram() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> num;
		arr[num]++;
	}

	for (int i = 0; i < SIZE; i++) {
		while (arr[i] > 0) {
			cout << i << " ";
			arr[i]--;
		}
	}
}
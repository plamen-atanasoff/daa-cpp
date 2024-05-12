#include <iostream>

namespace {
	int arr[10'000];
}

void subarray() {
	int n;
	std::cin >> n;

	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}

	long long sum = 0;
	// i is length of subarray
	for (int i = 1; i <= n; i += 2) {
		// j is start of the subarray and j + i is the end(exclusive)
		for (int j = 0; j + i <= n; j++) {
			// k goes through all indices of the subarray
			for (int k = j; k < j + i; k++) {
				sum += arr[k];
			}
		}
	}

	std::cout << sum;
}
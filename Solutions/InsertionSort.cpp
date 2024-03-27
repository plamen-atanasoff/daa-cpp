#include <iostream>
#include <utility>
using namespace std;

const int SIZE = 120;
int n;
int arr[SIZE];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i < n; i++) {
		int j = i;
		while (j > 0 && arr[j] < arr[j - 1]) {
			swap(arr[j], arr[j - 1]);
			j--;
		}

		for (j = 0; j < n; j++) {
			cout << arr[j] << " ";
		}
		cout << endl;
	}
}
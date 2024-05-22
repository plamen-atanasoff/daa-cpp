#include <iostream>
#include <vector>
using namespace std;

namespace {
	constexpr int MAX = 100'007;
	int n;

	vector<int> neighbours[MAX];
    bool visited[MAX];
    int color[MAX];
    int colorCnt[2];
}

void dfs(int x, bool c)
{
    color[x] = c;
    visited[x] = true;

    colorCnt[c]++;
    for (int y : neighbours[x])
    {
        if (!visited[y])
        {
            dfs(y, !c);
        }
    }
}

void mahmoudAndEhabBipartiteness() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    int x, y;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> x >> y;

        neighbours[x].push_back(y);
        neighbours[y].push_back(x);
    }

    dfs(1, 0);

    cout << colorCnt[0] * 1LL * colorCnt[1] - ((long long)n - 1) << endl;
}

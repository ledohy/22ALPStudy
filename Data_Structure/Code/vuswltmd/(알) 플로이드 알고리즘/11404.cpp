#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <cmath>
#include <queue>
#include <tuple>
#include <set>
#include <queue>
#include <map>
using namespace std;

const int INF = 100 * 100000;
int d[105][105];
int n, m;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			d[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++)
	{
		int a, b, cost;
		cin >> a >> b >> cost;

		d[a][b] = min(d[a][b], cost);
	}

	for (int i = 1; i <= n; i++)
	{
		d[i][i] = 0;
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (d[i][k] + d[k][j] < d[i][j])
					d[i][j] = d[i][k] + d[k][j];
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (d[i][j] == INF) cout << "0 ";
			else cout << d[i][j] << ' ';
		}
		cout << '\n';
	}
}

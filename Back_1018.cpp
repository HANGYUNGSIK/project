#include <iostream>
#include <vector>

using namespace std;

int Count(vector<string> v, int x, int y)
{
	char startColor = v[x][y];
	int atherCount{};

	for (int i = x; i < x+8; i++)
	{
		for (int j = y; j < y+8; j++)
		{
			if ((i + j) % 2 == 0)
			{
				if (v[i][j] != startColor)
					atherCount++;
			}
			else
				if (v[i][j] == startColor)
					atherCount++;
		}
	}

	return min(atherCount, 64-atherCount);
}

int main()
{
	int n{}, m{};
	int minCount = 10000;

	cin >> n >> m;
	vector<string> v(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	for (int i = 0; i <= n-8; i++)
	{
		for (int j = 0; j <= m-8; j++)
		{
			minCount = min(minCount, Count(v, i, j));
		}
	}

	cout << minCount << endl;
}
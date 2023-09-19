// Gopal Kataria
// ECD 2023 112 006
// IIIT Hyderabad

#include <stdio.h>

int main()
{
	int n, grid[100][100], i, xa, xb, ya, yb, x, y, area = 0;
	for (x = 0; x < 100; x++)
		for (y = 0; y < 100; y++)
			grid[x][y] = 0; // setting entire grid initially to zero

	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d %d %d %d", &xa, &xb, &ya, &yb);
		for (x = xa; x < xb; x++)
			for (y = ya; y < yb; y++)
				grid[x][y] = 1; // setting covered squares to 1
	}

	for (x = 0; x < 100; x++)
		for (y = 0; y < 100; y++)
			area += grid[x][y]; // counting area

	printf("%d\n", area);
	return 0;
}

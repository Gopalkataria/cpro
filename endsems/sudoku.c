#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#define rep(x, lim) for (int x = 0; x < lim; x++)
#define lint long long

#define min(a, b) ((a) < (b) ? (a) : (b)) // /  min function
#define max(a, b) ((a) > (b) ? (a) : (b)) // /  max function

#define out(x) printf("%d ", x)
#define inp(x) scanf("%d", &x)
#define endl printf("\n");

int puzz[9][9];

void printbin( int pos) {
	
	for (int i = 1 ; i < 10 ; i++)
	{
      out( ((pos & (1<<i)) >> i ) * i  ) ; 
	}
	
}

int checkpuzz()
{
	for (int x = 0; x < 9; x += 3)
	{
      for (int y = 0; y < 9; y += 3)
      {
      	int check[10] = {0};
      	// /  out(y) ; out(x);
      	for (int i = x; i < x + 3; i++)
      	{
            for (int j = y; j < y + 3; j++)
            {
            	// /  out( puzz[i][j]) ;
            	check[puzz[i][j]] += 1;
            }
      	}
      	for (int i = 1; i < 10; i++)
      	{
            if (check[i] != 1 && check[i] != 0)
            {
            	return 0;
            }
      	}
      }
      // /  endl ;
	}

	for (int i = 0; i < 9; i++)
	{
      int check[10] = {0};
      for (int j = 0; j < 9; j++)
      	check[puzz[i][j]] += 1;

      for (int j = 1; j < 15; j++)
      {
      	if (check[j] != 1 && check[j] != 0)
      	{
            return 0;
      	}
      }
	}

	for (int i = 0; i < 9; i++)
	{
      int check[10] = {0};
      for (int j = 0; j < 9; j++)
      	check[puzz[j][i]] += 1;

      for (int j = 1; j < 10; j++)
      {
      	if (check[j] != 1 && check[j] != 0)
      	{
            return 0;
      	}
      }
	}
	//
	return 1;
}

int inpos(int r, int c, int n)
{
	puzz[r][c] = n;
	int res = checkpuzz();
	puzz[r][c] = 0;
	return res;
}

int possibles(int row, int col)
{

	//  row possibles
	int rowpos = ~0;
	for (int i = 0; i < 9; i++)
	{
      rowpos &= ~(1 << puzz[row][i]);
	}

	// col possibles
	int colpos = ~0;
	for (int i = 0; i < 9; i++)
	{
      colpos &= ~(1 << puzz[i][col]);
	}

	// cell possibles
	int cellposs = ~0;
	for (int i = row - (row % 3); i < row - (row % 3) + 3; i++)
	{
      for (int j = col - (col % 3); j < col - (col % 3) + 3; j++)
      {
      	colpos &= ~(1 << puzz[i][j]);
      }
	}
	return (rowpos & colpos & cellposs);
}

int solver(int row, int col)
{
	// out( row) ;
	// out(col) ;
	// out( puzz[row][col]) ;
	// endl ;
	// rep(i, 9)
	// {
	// 	rep(j, 9) out(puzz[i][j]);
	// 	endl;
	// }

	if (puzz[row][col] > 0)
	{
      if (col < 8)
      {
      	return solver(row, col + 1);
      }
      else if (col == 8 && row < 8)
      {
      	return solver(row + 1, 0);
      }
      else if (row == 8 && col == 8)
      {
      	return 1;
      }
	}

	int pos = possibles(row, col);
	// endl ; 
	// endl ; 
	// out(row) ; out(col) ; 
	// endl ; 
	// printbin(pos) ; 
	// endl ; 
	for (int n = 1; n < 10; n++)
	{
      if (pos & (1 << n))
      {
      	if (inpos(row, col, n))
      	{
            puzz[row][col] = n;

            if (puzz[row][col] > 0)
            {
            	if (col < 8)
            	{
                  if (solver(row, col + 1))
                  	return 1;
            	}
            	else if (col == 8 && row < 8)
            	{
                  if (solver(row + 1, 0))
                  	return 1;
            	}
            	else if (row == 8 && col == 8)
            	{
                  return 1;
            	}
            }
            puzz[row][col] = 0;
      	}
      }
	}
	return 0;
}

int main()
{

	rep(i, 9) rep(j, 9) inp(puzz[i][j]);

	// out(checkpuzz()
	int i = solver(0, 0);
	if (i)
      rep(i, 9)
      {
      	rep(j, 9) out(puzz[i][j]);
      	endl;
      }
	// i += 1;
	endl;

	// while(n--) sol() ;
	return 0;
}

// Gopal Kataria
// ECD 2023 112 006
// IIIT Hyderabad

#include <stdio.h>

int main()
{
  int n = 0, door = 0;
  scanf("%d", &n);
  for (int x = 1; x <= n; x++)
  {
    door = 0;
    for (int y = 1; y <= x; y++)
    {
      if (x % y == 0)
      {
        door += 1;
        door &= 1;
      }
    }
    if (door)
    {
      printf("%d ", x);
    }
  }

  printf("\n");
  return 0;
}
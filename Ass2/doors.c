// Gopal Kataria
// ECD 2023 112 006
// IIIT Hyderabad

#include <stdio.h>

int main()
{
  int n = 0, doorstate = 0;
  scanf("%d", &n);
  for (int x = 1; x <= n; x++)
  {
    doorstate = 0; // all doors closed in begining
    for (int y = 1; y <= x; y++)
    {
      if (x % y == 0)
      {
        doorstate ^= 1; // swap state
      }
    }
    if (doorstate) // door open
    {
      printf("%d ", x);
    }
  }

  printf("\n");
  return 0;
}

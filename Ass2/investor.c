// Gopal Kataria
// ECD 2023 112 006
// IIIT Hyderabad

#include <stdio.h>

int main()
{
	int money = 0, invested = 0;
	scanf("%d", &money);
	do
	{
		invested += money & 1;
		money >>= 1;
	} while (money != 0);
	printf("%d\n", invested);
	return 0;
}

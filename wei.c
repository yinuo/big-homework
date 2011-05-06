#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[])
{
	while (1) {
		printf("1.decimal to binary\n");
		printf("2.x*y\n");
		printf("3.low or up exchange\n");
		printf("4.encryption\n");
		printf("5.Exit\n");
		printf("Please choose [ 1 - 5 ]:\n");
		int n;
		scanf("%d", &n);
		switch (n) {
		case 1:
			decimal();
			continue;
		case 2:
			blus();
			continue;
		case 3:
			change();
			continue;
		case 4:
			mi();
			continue;
		case 5:
			exit(0);
			return 0;
		}
	}
}

decimal()
{
	int x;
	int i = 31;
	int flag = 0;
	printf("Input a number:");
    scanf("%d", &x);
    printf("decimal %d change to binary is ",x);
	for (; i >= 0; i--) {
		if ((x >> i) & 1)
			flag = 1;
		if (flag)
			for (; i >= 0; i--) {
				if ((x >> i) & 1)
					printf("1");
				else
					printf("0");
			}
	}
	printf("\n");
	return 0;

}

blus()
{
	int x, y, ax, ay;
	int i, result = 0;
	int flag = 0;
	printf("Please input x y:");
	scanf("%d %d", &x, &y);
	if ((x >> 31) & 1)
		ax = ~(x - 1);
	else
		ax = x;
	if ((y >> 31) & 1)
		ay = ~(y - 1);
	else
		ay = y;
	if (((x >> 31) & 1) ^ ((y >> 31) & 1))
		flag = 1;
	for (i = 0; i < 31; i++) {
		if ((ay >> i) & 1)
			result += ax << i;
	}
	if (flag)
		result = ~result + 1;

	printf("%d * %d = %d\n", x, y, result);
	return 0;

}

change()
{
	int i;
	char a[] = { 0 };
	printf("Please input a string:");
	scanf("%s", a);
	for (i = 0; a[i] != '\0'; i++) {
		if (a[i] >= 'a' && a[i] <= 'z')
			a[i] &= 223;
		else if (a[i] >= 'A' && a[i] <= 'Z')
			a[i] |= 32;
	}


	printf("%s\n", a);
	return 0;


}

mi()
{
	int i;
	int c = 8;
	char a[] = { 0 };
    printf("Please input a string:");
	scanf("%s", a);
	for (i = 0; a[i] != '\0'; i++)
		a[i] ^= c;
	printf("After encrytion: %s\n", a);
}

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
	int t = 0, i, count = 0;
	int n,m;
    n = atoi(argv[1]);
    m = atoi(argv[2]);
	int a[n];
	for (i = 0; i < n; i++)
		a[i] = 1;

	while (t < n) {
		for (i = 0; i < n; i++) {
			if (a[i] == 1)
				count++;
			if (count == m) {
				a[i] = 0;
				t++;
				count = 0;
				printf("%3d: %3d  出局", t, i + 1);
				if (t % 5 == 0)
					printf("\n");
			}
            

		}

	}

	return 0;
}


#include <stdio.h>
#include <math.h>

int main()
{

	int D, VF, VG;
	double t;
	while (scanf("%d %d %d", &D, &VF, &VG) == 3) {

		t = 12.0 / VF;

		if ( sqrt(D*D + 144) / VG <= t) {

			printf("S\n");
		} else {
			printf("N\n");
		}
	}
	return 0;
}

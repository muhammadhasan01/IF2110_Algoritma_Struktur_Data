#include <stdio.h>
#include <math.h>

double a;
long double b;

int main() {

	scanf("%lf", &a);
	scanf("%Lf", &b);
	printf("%lf dan %Lf\n", a, b);

	return 0;
}

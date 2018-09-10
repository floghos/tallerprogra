#include <stdio.h>
#include <math.h>

void recursive() {
	long long num;
	double root;
    if (scanf("%lld", &num) != EOF) {
		root = sqrt(num);
        recursive();
		printf("%.4f\n", root);
    }
}

int main(int argc, char const *argv[]) {
	recursive();

	return 0;
}

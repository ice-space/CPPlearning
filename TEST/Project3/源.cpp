#include<stdio.h>
#include<stdlib.h>

int main() {
	int n;
	int i = 0;
	int j = 0;
	scanf_s("%d", &n);

	int stones[5];
	while (i <= 4) {
		stones[i] = 0;
	}
	i = 1;
	while (i < n) {
		scanf_s("%d", &stones[i]);
	}
	if (n == 5) {
		for (i = 0; i <= 4; i++) {
			for (j = 0; j <= 4; j++) {
				if (stones[i] <= stones[j]) {
					if (stones[i] == stones[j]) {
						stones[i] = 0;
						stones[j] = 0;
					}
					else {
						stones[i] = 0;
						stones[j] = stones[j] - stones[i];
					};

				};

			};
		};
		for (i = 0; i <= 4; i++) {
			printf("%d", stones[i]);
		}

	}
	else {
		i = 1;
		printf("%d", stones[i]);
	}




}
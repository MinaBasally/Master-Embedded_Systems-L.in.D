/*
 * Ass6_Q2.c
 *
 *  Created on: Dec 10, 2023
 *      Author: Mina
 */

#include "stdio.h"
#define max_entries 10

int main() {
	int i = 1, j, q, k;
	struct Sdistance {
		unsigned int feet;
		float inch;
	} dist[max_entries], total_dist = { 0, 0 };

	while (i) {
		fflush(stdin);
		printf("****Enter the distances(foot-inch) to find their sum****");

		for (j = 0; j < max_entries; j++) {
			fflush(stdin);
			printf("\n\nEnter distance #%d...\nfeet = ", j + 1);
			scanf("%u", &dist[j].feet);
			fflush(stdin);
			printf("inch = ");
			scanf("%f", &dist[j].inch);
			total_dist.feet = total_dist.feet + dist[j].feet;
			total_dist.inch = total_dist.inch + dist[j].inch;
			fflush(stdin);
			printf("\nEnter another distance? Yes = 1...No = 0 : ");
			scanf("%d", &q);
			if (q == 0)
				break;
		}

		for (k = 0; k < j; k++) {
			if (total_dist.inch > 12) {
				total_dist.inch = total_dist.inch - 12;
				total_dist.feet++;
			} else
				break;
		}

		fflush(stdin);
		printf("\nTOTAL DISTANCE = %u' %.2f\"", total_dist.feet, total_dist.inch);
		fflush(stdin);
		printf("\n\nagain = 1...exit = 0 : ");
		scanf("%d", &i);
		fflush(stdin);
		printf("\n\n\n");
	}

	return 0;
}

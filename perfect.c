#include <stdio.h>
#include <stdlib.h>

int main() {

	int t, w, s, a, b, wallNum, numWindows, numGaps, m, numPlans, gapSize;

	// Read in number of walls to process
	scanf("%d", &t);

	// Loop through each wall
	for(wallNum = 1; wallNum <= t; wallNum++) {

		// Read in wall width, window size, min & max number of windows
		scanf("%d %d %d %d", &w, &s, &a, &b);

		// Initialize number of plans that work to 0
		numPlans = 0;

		// Loop through every possible number of windows
		for(numWindows = a; numWindows <= b; numWindows++) {

			// Calculate number of gaps and gap size
			numGaps = numWindows + 1;
			gapSize = (w - (numWindows * s)) / numGaps;

			// If this plan would work, increase our count
			if( (w - (numWindows * s)) % numGaps == 0 && gapSize > 0 )
				numPlans++;

		}

		// Print out number of plans that work
		printf("Wall #%d: %d\n", wallNum, numPlans);

		// Loop through every possible number of windows
		for(numWindows = a; numWindows <= b; numWindows++) {

			// Calculate number of gaps and gap size
			numGaps = numWindows + 1;
			gapSize = (w - (numWindows * s)) / numGaps;

			// If this plan would work, print out number of windows and gap size
			if( (w - (numWindows * s)) % numGaps == 0 && gapSize > 0 )
				printf("%d %d\n", numWindows, gapSize);

		}

		// Print out an extra line
		printf("\n");

	}

}

#include <stdio.h>

int main() {

	int i, dayNum, numDays, n, count, numCoins;

	// Read in the number of days we will need to process.
	scanf("%d", &numDays);

	// Loop through each day.
	for(dayNum = 1; dayNum <= numDays; dayNum++) {

		// Read in the number of stacks in this row.
		scanf("%d", &n);

		// Initialize our count of incorrect stacks to 0.
		count = 0;

		// Loop through each stack in this row.
		for(i = 0; i < n; i++) {

			// Read in the number of coins in this stack.
			scanf("%d", &numCoins);

			// This stack's parity is incorrect if it is not equal to it's positions parity.
			if(numCoins % 2 != i % 2)
				count++;

		}

		// We may want to instead have all the stacks be opposite parities of their positions.
		// Thus, we take the smaller between our count and the count with opposite parities (n - count).
		if(n - count < count) count = n - count;

		// Print out our answer.
		printf("Row #%d: Jerry needs to add a minimum of %d coins\n", dayNum, count);

	}
}
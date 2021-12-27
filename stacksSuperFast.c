#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// This runs 25-30% faster than the normal stacks program.
// It reads values in as strings instead(this is faster)
// Then, to check parity, it just looks at the last character and compares it to an array.
// Also, the parity of i is kept track by using a seperate variable

int main() {

	int i, caseNum, numCases, n, count, temp;
	int *arr = malloc(sizeof(int) * 256);
	char *str = malloc(sizeof(char) * 10);

	arr['0'] = arr['2'] = arr['4'] = arr['6'] = arr['8'] = 0;
	arr['1'] = arr['3'] = arr['5'] = arr['7'] = arr['9'] = 1;

	scanf("%d", &numCases);

	for(caseNum = 1; caseNum <= numCases; caseNum++) {
		scanf("%d", &n);

		temp = 0;
		count = 0;
		for(i = 0; i < n; i++, temp = temp == 1 ? 0 : 1) {
			scanf("%s", str);
			if(temp != arr[str[strlen(str) - 1]])
				count++;
		}
		if((temp = n - count) < count) count = temp;
		printf("Row #%d: Jerry needs to add a minimum of %d coins\n", caseNum, count);
	}

	free(arr);
	free(str);
}
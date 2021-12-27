import java.util.Scanner;

/*
 * Stacks on Stacks - stacks.java
 * Solution written by Joshua Linge
 */

/*
Sample input:
2
8
1 18 17 20 25 100 203 44
4
26 26 28 28

Sample output:
Row #1: Jerry needs to add a minimum of 0 coins
Row #2: Jerry needs to add a minimum of 2 coins

 */
public class stacks {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		// Read in the number of days to process.
		int numDays = in.nextInt();
		
		// Loop through each day.
		for(int curDay = 1; curDay <= numDays; ++curDay) {
			int numStacks = in.nextInt();
			
			// Read in the size of each stack.
			int[] stacks = new int[numStacks];
			for(int curStack = 0; curStack < numStacks; ++curStack) {
				stacks[curStack] = in.nextInt();
			}
			
			// Save the minimum number of coins needed to add 
			// to the stacks to have alternating parities.
			int minCoins = numStacks;
			
			// Try forcing the parity of the first stack to be 
			// even parity, and then odd parity, saving the  
			// minimum number of coins required to have all 
			// stacks have alternating parities.
			for(int parity = 0; parity < 2; ++parity) {
				int coins = 0;
				
				// Check the each location and count the number 
				// of coins needed to force this parity.
				for(int curStack = 0; curStack < numStacks; ++curStack) {
					// Determine the required parity for this stack.
					int reqParity = (curStack + parity) % 2;
					
					// If the required parity does not match the 
					// actual parity, add a coin.
					if(reqParity != (stacks[curStack] % 2)) {
						++coins;
					}
				}
				
				// Save the minimum coins used
				minCoins = Math.min(minCoins, coins);
			}
			
			// Output answer for the current day/row.
			System.out.printf("Row #%d: Jerry needs to add a minimum of %d coins%n", curDay, minCoins);
		}
		
		in.close();
	}

}

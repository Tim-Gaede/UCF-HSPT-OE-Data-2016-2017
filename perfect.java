import java.util.*;

public class perfect {
	
	public static void main(String[] args) {
		
		Scanner in = new Scanner(System.in);
		
		int t = in.nextInt(); //number of test cases
		
		for(int wall = 1; wall <= t; wall++){
			
			//variables from input
			int w = in.nextInt(); //width of the wall
			int s = in.nextInt(); //number of blocks per window
			int a = in.nextInt(); //smallest desired number of windows
			int b = in.nextInt(); //largest desired number of windows
			
			ArrayList<solution> solutions = new ArrayList<solution>();
			
			for(int numWindows = a; numWindows <= b; numWindows++){
				int roomForGaps = w-numWindows*s; //The space on the wall not taken up by windows
				if(roomForGaps <= 0) break; //If there is not enough room for gaps, we can't put this or any more number of windows
				int numGapsNeeded = numWindows+1; //There is a gap after every window, and a gap before the first window, so there is one more gap then there are windows
				if(roomForGaps % numGapsNeeded == 0){ //the space left for gaps needs to be distributed evenly over the gaps
					solutions.add(new solution(numWindows,roomForGaps/numGapsNeeded));//saving a new solution
				}
			}
			
			//printing the answer for this test case
			System.out.println("Wall #"+wall+": " + solutions.size());
			for (solution ans : solutions) {//for each loop over the ArrayList
				System.out.println(ans.numberOfWindows + " " + ans.gapSize);
			}
			System.out.println();//line between test cases
			
			
		}
		
		in.close();
	}
	
	//class to hold possible answers
	static class solution{
		int numberOfWindows, gapSize;

		public solution(int numberOfWindows, int gapSize) {
			this.numberOfWindows = numberOfWindows;
			this.gapSize = gapSize;
		}
		
		
		
	}

}

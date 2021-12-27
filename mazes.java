/*
 This solution uses a technique called 0/1 BFS, which finds the 
 shortest path in a graph where all edge weights are either 0
 or 1. The maze can be thought of as a graph where the nodes
 are the cells and each node has an edge to the 4 adjacent cells.
 Clearing a cell costs 1, so edges to blocked cells have weight
 1 while edges to clear cells have weight 0.
 The shortest path from S to E in this graph is equal to the
 minimum number of cells which must be cleared.
 
 0/1 BFS works the same way as regular BFS, except nodes that
 were reached over a 0 edge are added to the front of the queue
 instead of the back and their distance is not incremented. 
 This way, all possible "free" nodes are visited, whenever
 possible, before incurring any cost.
 */
import java.util.*;
public class mazes {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		int t = in.nextInt();
		for(int z = 1; z <= t; z ++)
		{
			//Taking in the input
			int n = in.nextInt();
			int m = in.nextInt();
			boolean[][] map = new boolean[n][m];
			int start_i = -1;
			int start_j = -1;
			int end_i = -1;
			int end_j = -1;
			
			for(int i = 0; i < n; i ++)
			{
				String row = in.next();
				for(int j = 0; j < m; j++)
				{
					char c = row.charAt(j);
					map[i][j] = c == '.' || c == 'S' || c == 'E';
					if(c=='S')
					{
						start_i = i;
						start_j = j;
					}
					if(c=='E')
					{
						end_i = i;
						end_j = j;
					}
				}
			}
			
			//stores the distance from s to each cell.
			int[][] distance = new int[n][m];
			for(int i = 0; i < n; i ++)
				Arrays.fill(distance[i],  -1);
			
			ArrayDeque<Integer> queue = new ArrayDeque<Integer>();
			
			//initially we are at cell (start_i, end_i)
			queue.add(start_i);
			queue.add(start_j);		
			distance[start_i][start_j] = 0;
	
			//These arrays store the four directions that we can move
			int[] di = new int[] {0,0,1,-1};
			int[] dj = new int[] {1,-1,0,0};
			
			while(!queue.isEmpty())
			{
				//The current cell
				int at_i = queue.poll();
				int at_j = queue.poll();
				
				//Try all 4 directions
				for(int k = 0; k < 4; k ++)
				{
					int next_i = at_i + di[k];
					int next_j = at_j + dj[k];
					
					/*
					 * If we are trying to go to a cell that is out of bounds or
					 * that has already been visited, don't.
					 */
					if(next_i >= n || next_i < 0 || next_j >= m || next_j < 0 || distance[next_i][next_j] != -1)
						continue;
					
					//If we are moving into a blocked cell
					if(!map[next_i][next_j])
					{
						//We have incurred 1 cost for clearing this cell
						distance[next_i][next_j] = distance[at_i][at_j] + 1;
						queue.add(next_i);
						queue.add(next_j);
					}
					
					//If we are moving into a clear cell
					else
					{
						//It does not cost any extra
						distance[next_i][next_j] = distance[at_i][at_j];
						
						//Add it to the front of the queue
						queue.addFirst(next_j);
						queue.addFirst(next_i);
					}
				}
			}
			
			//The answer is the distance from S to E
			System.out.println("Maze #" + z + ": " + distance[end_i][end_j]);
		}
	}
}

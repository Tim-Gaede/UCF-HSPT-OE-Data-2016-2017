
from collections import deque
from itertools import product

# vector addition
def add(a, b):
   return tuple(x+y for x,y in zip(a,b))
cardinalDirs = [(1,0), (0,1), (-1,0), (0,-1)]

numTests = int(input())
for testCase in range(1,numTests+1):
   numRows, numCols = map(int, input().split())
   grid = [input() for _ in range(numRows)]

   src = None
   dst = None
   for i, curRow in enumerate(grid):
      for j, c in enumerate(curRow):
         if c == 'S':
            src = (i,j)
         elif c == 'E':
            dst = (i,j)

   # Run a 0/1 Breath First Search (BFS) to find the ending node   
   # Cost 0 edges go to the front of the deque and cost 1 to the back.
   q = deque()
   dist = {src:0}
   q.append((src, 0))
   while q:
      
      # Only process this node if we are optimal.
      cur, d = q.popleft()
      if dist[cur] != d:
         continue

      # Try moving to all adjacent squares.
      for dv in cardinalDirs:
         newLoc = add(cur, dv)
         if 0 <= newLoc[0] and newLoc[0] < numRows and 0 <= newLoc[1] and newLoc[1] < numCols:
            extra = 1 if grid[newLoc[0]][newLoc[1]] == '#' else 0
            newD = d + extra
            if newLoc not in dist or newD < dist[newLoc]:
               dist[newLoc] = newD
               if extra == 0:
                  q.appendleft((newLoc, newD))
               else:
                  q.append((newLoc, newD))

   # Print out how far the destination is
   print('Maze #{}: {}'.format(testCase, dist[dst]))


# Read in the number of tests
numTests = int(input())
for testCase in range(1, numTests+1):
   numRows, numCols = map(int, input().split())

   # Read in the rows of the field
   grid = [input() for _ in range(numRows)]

   # Compress the grid to a single string and count number of 'H's
   numHyenas = ''.join(grid).count('H')

   # Print the answer
   print('Location #{}: {}'.format(testCase, numHyenas))

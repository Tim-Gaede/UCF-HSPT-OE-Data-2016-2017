
from math import sqrt, floor

numTests = int(input())

for testCase in range(1, numTests+1):
   radius, sideLength = map(int, input().split())

   # Try placing as many squares as possible at each column.
   multiplier = 1
   numSquares = 0
   position = sideLength * 0.5
   while position < radius:

      # Find the height used using pythagorean theorem.
      # This tells the distance from top to bottom of the circle
      # from the given x location.
      halfHeight = sqrt(radius ** 2 - position ** 2)
      height = 2 * halfHeight

      # Use this height to determine how many squares go here.
      squaresAdded = int(floor(height / sideLength + 1e-9))
      squaresAdded *= multiplier
      numSquares += squaresAdded

      position += sideLength

      # Count both the left and right side after placing the initial column
      multiplier = 2

   # Get the area estimated by the squares
   area = numSquares * sideLength ** 2
   print('Measure #{}: {}'.format(testCase, area))


numTests = int(input())
for testCase in range(1, numTests+1):
   width, windowWidth, minWindows, maxWindows = map(int, input().split())

   # Try all possible number of windows and find window sizes that work
   result = []
   for numWindows in range(minWindows, maxWindows+1):
      numGaps = numWindows+1
      remainingWidth = width - windowWidth*numWindows
      if remainingWidth > 0 and remainingWidth % numGaps == 0:
         gapSize = remainingWidth / numGaps 
         result.append((numWindows, gapSize))

   # Print the result
   print('Wall #{}: {}'.format(testCase, len(result)))
   for a, b in result:
      print(a, int(b))
   print()

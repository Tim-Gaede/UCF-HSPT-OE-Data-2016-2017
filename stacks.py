
numTests = int(input())
for testCase in range(1, numTests+1):
   numCoins = int(input())
   coins = map(int, input().split())

   # For odd and even locations, tally the number of odd and even coin counts.
   table = [[0,0], [0,0]]
   for i, curCoin in enumerate(coins):
      table[i&1][curCoin&1] += 1

   # Determine if it is better to start odd or start even
   result = min(table[0][0]+table[1][1], table[0][1]+table[1][0])
   print('Row #{}: Jerry needs to add a minimum of {} coins'.format(testCase, result))

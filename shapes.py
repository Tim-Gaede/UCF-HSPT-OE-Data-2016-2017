
from collections import defaultdict
from itertools import repeat

# Give a default value for anything not 3 or 4. Otherwise print the good message.
d = defaultdict(repeat("Johnny will not be pleased with this one.").__next__)
d[3] = d[4] = "Johnny's favorite!"

# Answer the query for each shape
numTests = int(input())
for testCase in range(1,numTests+1):
   numSides = int(input())
   print("Shape #{}: {}".format(testCase, d[numSides]))

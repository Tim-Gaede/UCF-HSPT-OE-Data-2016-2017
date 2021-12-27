
# Add pitches and sharps and flats to a map of pitches
# Map those values to an integer in the range [0,12)
rawPitches = 'ABCDEFG'
pitchMap = {'A':0, 'B':2, 'C':3, 'D':5, 'E':7, 'F':8, 'G':10}
for pitch in rawPitches:
   if pitch not in 'EB':
      pitchMap[pitch+'#'] = (pitchMap[pitch]+1) % 12
   if pitch not in 'FC':
      pitchMap[pitch+'b'] = (pitchMap[pitch]+11) % 12
   
numTests = int(input())
for testCase in range(1,numTests+1):

   # Read in the notes as a list. Cut off the number of notes as this
   # is python and we have style.
   notes = input().split()[1:]

   # Compute the cost of switching between notes. We greedily pick the closer
   # of two octaves in each step.
   minHalfsteps = 0
   for fromNote, toNote in zip(notes, notes[1:]):
      diff = abs(pitchMap[fromNote]-pitchMap[toNote])
      minHalfsteps += min(diff, 12-diff)

   # Print the result.
   print('Song #{}: {}'.format(testCase, minHalfsteps))

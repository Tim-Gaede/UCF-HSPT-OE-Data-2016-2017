/*
 * Infinite Keyboard - keyboard.cpp
 * Solution written by Joshua Linge
 */

/*
Sample Input:
2
5 F B D# D G
4 Db C# C B

Sample Output:
Song #1: 16
Song # 2: 2

 */

#include <iostream>
using namespace std;

// Names for all the notes.
const string NOTE_NAMES[] = {"C", "C#", "Db", "D", "D#", "Eb", "E", "F", "F#",
                             "Gb", "G", "G#", "Ab", "A", "A#", "Bb", "B"};

// Index into the octave for each note.
const int NOTE_INDICES[] = {0, 1, 1, 2, 3, 3, 4, 5, 6, 6, 7, 8, 8, 9, 10, 10, 11};

// Total number of notes within an octave.
const int NUMBER_OF_NOTES = 12;

int getNoteIndex(string note) {
    // Search through all the notes
    // Return the index of the note that matches.
    for(int curNote = 0; curNote < 17; ++curNote) {
        if(note == NOTE_NAMES[curNote]) {
            return NOTE_INDICES[curNote];
        }
    }
    // Invalid note.
    return -1;
}

int getMinDistance(int note1, int note2) {
    // Ensure that note2 is the note higher in the octave
    if(note1 > note2) {
        int temp = note1;
        note1 = note2;
        note2 = temp;
    }
    
    // Walk within the same octave.
    int dist1 = note2 - note1;
    
    // Walk across to another octave.
    int dist2 = note1 + NUMBER_OF_NOTES - note2;
    
    // Return the minimum distance.
    return min(dist1, dist2);
}

int main() {
	
    // Read in the number of songs to process.
    int numSongs;
    cin >> numSongs;

    // Loop through each song.
    for(int curSong = 1; curSong <= numSongs; ++curSong) {
        int numNotes;
        cin >> numNotes;
        
        // Read each note and convert the note into its
        // index in the octave.
        int notes[numNotes];
        for(int curNote = 0; curNote < numNotes; ++curNote) {
            string note;
            cin >> note;
            notes[curNote] = getNoteIndex(note);
        }
        
        // Go through the song and find the minimun number
        // of half steps needed between each note.
        int steps = 0;
        for(int curNote = 0; curNote < numNotes-1; ++curNote) {
            steps += getMinDistance(notes[curNote], notes[curNote+1]);
        }
        
        // Output the minimum number of half steps to play the song.
        printf("Song #%d: %d\n", curSong, steps);
    }
    
	return 0;
}

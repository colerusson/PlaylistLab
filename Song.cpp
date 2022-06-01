#include "Song.h"
#include <iostream>

Song::Song() {
    titleOfSong = "No title";
    firstLine = "No first line";
}

Song::Song(string songTitle, string songFirstLine) {
    titleOfSong = songTitle;
    firstLine = songFirstLine;
}

void Song::PrintNameAndFirstLine() {
    cout << titleOfSong << ": \"" << firstLine << "\", ";
}

void Song::PrintNumberOfPlays() {
    cout << numberOfPlays;
}

void Song::SetNumberOfPlays() {
    numberOfPlays += 1;
}

string Song::GetSongTitle() {
    return titleOfSong;
}

string Song::PlaySong() {
    return firstLine;
}

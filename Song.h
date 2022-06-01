#ifndef CHAPTER8PROJECTPLAYLIST_SONG_H
#define CHAPTER8PROJECTPLAYLIST_SONG_H
#include <string>
#include <vector>
using namespace std;


class Song {
public:
    Song();
    Song(string songTitle, string songFirstLine);
    void PrintNameAndFirstLine();
    void PrintNumberOfPlays();  
    void SetNumberOfPlays();
    string GetSongTitle();
    string PlaySong();

private:
    string titleOfSong;
    string firstLine;
    int numberOfPlays;
};


#endif

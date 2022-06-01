#ifndef CHAPTER8PROJECTPLAYLIST_PLAYLIST_H
#define CHAPTER8PROJECTPLAYLIST_PLAYLIST_H
#include <iostream>
#include <string>
#include <vector>
#include "Song.h"
using namespace std;

class Playlist {
public:
    Playlist();
    explicit Playlist(string userPlaylist);
    void PrintPlaylists();
    void AddSongToPlaylist(Song* newSong);
    string GetPlaylistName();
    void PlayPlaylist();
    void PrintSongNames();
    void RemovePlaylistSong(int userIndex);
    string ReturnSongTitle(int userIndex);
    int ReturnVectorSize();

private:
    string playlistName;
    vector<Song*> playlistSongs;
};


#endif

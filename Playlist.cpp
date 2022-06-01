#include "Playlist.h"

Playlist::Playlist() {
    playlistName = "no name";
}

Playlist::Playlist(string userPlaylist) {
    playlistName = userPlaylist;
}

void Playlist::PrintPlaylists() {
    cout << playlistName << endl;
}

void Playlist::AddSongToPlaylist(Song* newSong) {
    playlistSongs.push_back(newSong);
}

string Playlist::GetPlaylistName() {
    return playlistName;
}

void Playlist::PlayPlaylist() {
    unsigned int i;
    for (i = 0; i < playlistSongs.size(); ++i){
        cout << playlistSongs.at(i)->PlaySong() << endl;
        playlistSongs.at(i)->SetNumberOfPlays();
    }
}

void Playlist::PrintSongNames() {
    unsigned int i;
    for (i = 0; i < playlistSongs.size(); ++i) {
        cout << i << ": " << playlistSongs.at(i)->GetSongTitle() << endl;
    }
}

void Playlist::RemovePlaylistSong(int userIndex) {
    playlistSongs.erase(playlistSongs.begin() + userIndex);
}

string Playlist::ReturnSongTitle(int userIndex) {
    return playlistSongs.at(userIndex)->GetSongTitle();
}

int Playlist::ReturnVectorSize() {
    return playlistSongs.size();
}

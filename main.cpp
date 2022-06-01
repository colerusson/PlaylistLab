#include <iostream>
#include <string>
#include <vector>
#include "Song.h"
#include "Playlist.h"
using namespace std;

string GetUserString(const string& prompt);

int main() {
    cout << "Welcome to the Firstline Player!  Enter options to see menu options." << endl << endl;

    string userMenuChoice = "none";
    bool continueMenuLoop = true;
    vector<Song*> allSongs;
    vector<Playlist> allPlaylists;

    while (continueMenuLoop) {
        userMenuChoice = GetUserString("Enter your selection now: ");

        if (userMenuChoice == "add") {
            const string DONE_KEYWORD = "DONE";
            cout << "Enter songs' names and first lines"
                      << " (type \"" << DONE_KEYWORD << "\" when done):" << endl;
            string songName = "none";
            string firstLine = "none";
            songName = GetUserString("Song Name: ");
            while (songName != DONE_KEYWORD) {
                firstLine = GetUserString("Song's first line: ");
                Song* newSong = new Song(songName, firstLine);
                allSongs.push_back(newSong);
                songName = GetUserString("Song Name: ");
            }
        }
        else if (userMenuChoice == "list") {
            unsigned int i;
            for (i = 0; i < allSongs.size(); ++i) {
                allSongs.at(i)->PrintNameAndFirstLine();
                allSongs.at(i)->PrintNumberOfPlays();
                cout << " play(s)." << endl;
            }
        }
        else if (userMenuChoice == "addp") {
            string playListName;
            playListName = GetUserString("Playlist name: ");
            Playlist newPlaylist(playListName);
            allPlaylists.push_back(newPlaylist);
        }
        else if (userMenuChoice == "addsp") {
            int userPlaylistSelection;
            int userSongSelection;
            unsigned int i;
            for (i = 0; i < allPlaylists.size(); ++i) {
                cout << i << ": ";
                allPlaylists.at(i).PrintPlaylists();
            }
            cout << "Pick a playlist index number: " << endl;
            cin >> userPlaylistSelection;
            cin.ignore();
            for (i = 0; i < allSongs.size(); ++i) {
                cout << i << ": " << allSongs.at(i)->GetSongTitle() << endl;
            }
            cout << "Pick a song index number: " << endl;
            cin >> userSongSelection;
            cin.ignore();
            allPlaylists.at(userPlaylistSelection).AddSongToPlaylist(allSongs.at(userSongSelection));
        }
        else if (userMenuChoice == "listp") {
            unsigned int i;
            for (i = 0; i < allPlaylists.size(); ++i) {
                cout << i << ": ";
                allPlaylists.at(i).PrintPlaylists();
            }
        }
        else if (userMenuChoice == "play") {
            int userPlaylistSelection;
            unsigned int i;
            for (i = 0; i < allPlaylists.size(); ++i) {
                cout << i << ": ";
                allPlaylists.at(i).PrintPlaylists();
            }
            cout << "Pick a playlist index number: " << endl;
            cin >> userPlaylistSelection;
            cin.ignore();
            cout << endl << "Playing songs from playlist: " << allPlaylists.at(userPlaylistSelection).GetPlaylistName() << endl;
            allPlaylists.at(userPlaylistSelection).PlayPlaylist();
        }
        else if (userMenuChoice == "remp") {
            int userPlaylistSelection;
            unsigned int i;
            for (i = 0; i < allPlaylists.size(); ++i) {
                cout << i << ": ";
                allPlaylists.at(i).PrintPlaylists();
            }
            cout << "Pick a playlist index number to remove: " << endl;
            cin >> userPlaylistSelection;
            cin.ignore();
            allPlaylists.erase(allPlaylists.begin() + userPlaylistSelection);
        }
        else if (userMenuChoice == "remsp") {
            int userPlaylistSelection;
            int userSongSelection;
            unsigned int i;
            for (i = 0; i < allPlaylists.size(); ++i) {
                cout << i << ": ";
                allPlaylists.at(i).PrintPlaylists();
            }
            cout << "Pick a playlist index number: " << endl;
            cin >> userPlaylistSelection;
            cin.ignore();
            allPlaylists.at(userPlaylistSelection).PrintSongNames();
            cout << "Pick a song index number to remove: " << endl;
            cin >> userSongSelection;
            cin.ignore();
            allPlaylists.at(userPlaylistSelection).RemovePlaylistSong(userSongSelection);
        }
        else if (userMenuChoice == "remsl") {
            unsigned int i;
            unsigned int j;
            int userSelection;
            for (i = 0; i < allSongs.size(); ++i) {
                cout << i << ": " << allSongs.at(i)->GetSongTitle() << endl;
            }
            cout << "Pick a song index number to remove: " << endl;
            cin >> userSelection;
            cin.ignore();
            for (i = 0; i < allPlaylists.size(); ++i) {
                for (j = 0; j < allPlaylists.at(i).ReturnVectorSize(); ++j) {
                    if (allPlaylists.at(i).ReturnSongTitle(j) == allSongs.at(userSelection)->GetSongTitle()) {
                        allPlaylists.at(i).RemovePlaylistSong(j);
                    }
                }
            }
            delete allSongs.at(userSelection);
            allSongs.erase(allSongs.begin() + userSelection);
        }
        else if (userMenuChoice == "options") {
            cout << "add      Adds a list of songs to the library" << endl
                      << "list     Lists all the songs in the library" << endl
                      << "addp     Adds a new playlist" << endl
                      << "addsp    Adds a song to a playlist" << endl
                      << "listp    Lists all the playlists" << endl
                      << "play     Plays a playlist" << endl
                      << "remp     Removes a playlist" << endl
                      << "remsp    Removes a song from a playlist" << endl
                      << "remsl    Removes a song from the library (and all playlists)" << endl
                      << "options  Prints this options menu" << endl
                      << "quit     Quits the program" << endl << endl;
        }
        else if (userMenuChoice == "quit") {
            cout << "Goodbye!" << endl;
            continueMenuLoop = false;
        }
        else {
            cout << "add      Adds a list of songs to the library" << endl
                      << "list     Lists all the songs in the library" << endl
                      << "addp     Adds a new playlist" << endl
                      << "addsp    Adds a song to a playlist" << endl
                      << "listp    Lists all the playlists" << endl
                      << "play     Plays a playlist" << endl
                      << "remp     Removes a playlist" << endl
                      << "remsp    Removes a song from a playlist" << endl
                      << "remsl    Removes a song from the library (and all playlists)" << endl
                      << "options  Prints this options menu" << endl
                      << "quit     Quits the program" << endl << endl;
        }
    }

    for (int i = 0; i < allSongs.size(); i++) {
        delete allSongs.at(i);
    }

    return 0;
}

string GetUserString(const string& prompt) {
    string userAnswer = "none";

    cout << prompt;
    getline(cin, userAnswer);
    cout << endl;
    return userAnswer;
}

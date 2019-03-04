#include "song.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstring>

using namespace std;

  void get_menu(vector<char*> menu){ //Prints menu one line at a time
    for (int i = 0; i < menu.size(); i++){
      cout << menu[i] << endl;
    };
  };//must compile with c++ 11 or later for get_menu to work

  music::music_genre str_toenum(string str) { //real function to take in a string and return an enum genre
   if (str == "blues" || str == "Blues") {
     return music::music_genre::Blues;
   }
   else if (str == "country" || str == "Country") {
     return music::music_genre::Country;
   }
   else if (str == "electronic" || str == "Electronic" || str == "edm" || str == "EDM") {
     return music::music_genre::Electronic;
   }
   else if (str == "folk" || str == "Folk") {
     return music::music_genre::Folk;
   }
   else if (str == "hiphop" || str == "HipHop" || str == "Hip Hop" || str == "hip hop" || str == "Hip-Hop" || str == "rap" || str == "Rap") {
     return music::music_genre::HipHop;
   }
   else if (str == "jazz" || str == "Jazz") {
     return music::music_genre::Jazz;
   }
   else if (str == "latin" || str == "Latin") {
     return music::music_genre::Latin;
   }
   else if (str == "pop" || str == "Pop") {
     return music::music_genre::Pop;
   }
   else if (str == "rock" || str == "Rock"){
     return music::music_genre::Rock;
   }
   else {
     return music::music_genre::fail_case;
   };
 };

 string enum_tostring(music::music_genre genre_index) {
   if (genre_index == 0) {
     cout << "Error: Invalid Genre" << endl;
     return "";
   }
   else if (genre_index == 1) {
     return "Blues";
   }
   else if (genre_index == 2) {
     return "Country";
   }
   else if (genre_index == 3) {
     return "Electronic";
   }
   else if (genre_index == 4) {
     return "Folk";
   }
   else if (genre_index == 5) {
     return "Hip-Hop";
   }
   else if (genre_index == 6) {
     return "Jazz";
   }
   else if (genre_index == 7) {
     return "Latin";
   }
   else if (genre_index == 8) {
     return "Pop";
   }
   else if (genre_index == 9) {
     return "Rock";
   };
 };

  void add_song(music::Song& s){ //reads user input into members of s
    string genre;
    string title;
    string artist;
    string album;
    cout << "Enter song title: ";
    getline(cin, title); //**second parameter must be a string, s.title is a character array** **use string copy function**
    strcpy(music::s.title, title.c_str());
    cout << "Enter artist: ";
    getline(cin, artist);
    strcpy(music::s.artist, artist.c_str());
    cout << "Enter album name: ";
    getline(cin, album);
    strcpy(music::s.album, album.c_str());
    cout << "Enter genre: ";
    getline(cin, genre);
    music::s.genre = str_toenum(genre);
    cout << "Enter track #: ";
    cin >> music::s.track;
    cout << "Enter year: ";
    cin >> music::s.year;
  };

  void save_song(music::Song& s, string fname, int count){ //writes the members of Song s to a file // must declare count before calling func
    ofstream outfile;
    outfile.open(fname, ios::out | ios::app);
    outfile << "Song #: " << count << endl;
    outfile << "  Title: " << music::s.title << endl;
    outfile << "  Artist: " << music::s.artist << endl;
    outfile << "  Album: " << music::s.album << endl;
    outfile << "  Track #: " << music::s.track << endl;
    outfile << "  Year: " << music::s.year << endl;
    outfile << "  Genre: " << enum_tostring(music::s.genre) << "\n\n"; //How do you read data from specific members of enum type???
    outfile.close();
  };

  void list_song(string fname){ //reads contents of file fname into an ifstream named infile
    ifstream infile(fname);
    string line;
    while(getline(infile, line)) //then prints contents from infile to console.
      cout << line << '\n';
  };

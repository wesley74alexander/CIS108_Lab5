#include "MusicDB.h"
#include "song.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

  void get_menu(vector<string> const &menu){ //Prints menu one line at a time
    for (int i = 0; i < menu.size(); i++){
      cout << menu[i];
    }; //When get_menu(menu) is called inside of a main() loop in this file, it works.
  };   // To get it to work in Main.cpp, a namespace should be used for the vector menu
       // OR, menu may have to be defined within Main.cpp, but this seems clunky.
  void add_song(music::Song& s){ //reads user input into members of s
    cout << "Enter song title: ";
    getline(cin,s.title);
    cout << "Enter artist: ";
    getline(cin,s.artist);
    cout << "Enter album name: ";
    getline(cin,s.album)
    cout << "Enter track #: ";
    cin >> s.track;
    cout << "Enter year: ";
    cin >> s.year;
    cout << "Enter genre: ";
    getline(cin,s.genre); //How do you read data into enum type???
  };

  void save_song(music::Song& s, string fname){ //writes the members of Song s to a file
    ofstream outfile;
    outfile.open(fname, ios::out | ios::app);
    outfile << "Title: " << s.title << endl;
    outfile << "Artist: " << s.artist << endl;
    outfile << "Album: " << s.album << endl;
    outfile << "Track #: " << s.track << endl;
    outfile << "Year: " << s.year << endl;
    outfile << "Genre: " << s.genre << endl; //How do you read data from specific members of enum type???
    outfile.close();
  };

  void list_song(string fname){ //reads contents of file fname into an ifstream named infile
    ifstream infile(fname);
    string line;
    while(getline(infile, line)) //then prints contents from infile to console.
      cout << line << '\n';
  };

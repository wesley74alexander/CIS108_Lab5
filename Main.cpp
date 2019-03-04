using namespace std;
#include "MusicDB.h"
#include "song.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main() {

  vector<char*> menu = { //**use an array instead** //or compile with c++ 11 or later to define a vector of static strings
     "===========================================",
     "add : Add a new song to the music database",
     "list : List the songs in the music database",
     "save : Save the music database",
     "help : Display this menu",
     "exit : Exit the Program",
     "===========================================\n"
  };

  get_menu(menu); //Prints the menu line by line when the program first runs.
  string command;
  int count = 1;

  while (true) { //Reads commands from user until a break is encountered.
    cout << "\n> ";
    cin >> command;

      if (command == "add") {
        add_song(music::s);
      }
      //must use cout to prompt user for data
      //use cin to read user entered data from the console
      else if (command == "list") {
        list_song("MusicFile.txt");
      }
      //must use an ifstream to read the contents of the file
      //use cout to print the file from ifstream object to console
      else if (command == "save" && count <= 8) {
        save_song(music::s, "MusicFile.txt", count);
        count += 1;
      }
      else if (command == "save" && count > 8) {
        cout << "Your file is full!";
      }
      //must dump additions from ofstream buffer into a file
      else if (command == "help") {
        get_menu(menu); //Prints menu line by line when user enters "help"
      }

      else if (command == "exit") {
        cout << "Goodbye!";
        break;
      }
      else {
        cout << "Enter one of the following commands!";
        get_menu(menu);
      };
  };
  return 0;
};

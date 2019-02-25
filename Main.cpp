using namespace std;
#include "MusicDB.h"
#include <string>

using namespace std;

int main() {

  vector<string> const &menu = {
     "add : Add a new song to the music database",
     "list : List the songs in the music database",
     "save : Save the music database",
     "help : Display this menu",
     "exit : Exit the Program"
  };

  get_menu(menu); //Prints the menu line by line when the program first runs.

  while (true) { //Reads commands from user until a break is encountered.
    cout << "\n> "
    cin >> string command;

    switch (command) {
      case "add":
      //must use cout to prompt user for data
      //use cin to read user entered data from the console
        add_song(music::Song s); //See MusicDB.cpp for
      case "list":
        list_song("MusicFile.txt")
      //must use an ifstream to read the contents of the file
      //use cout to print the file from ifstream object to console
      case "save":
        save_song(music::Song s, "MusicFile.txt");
      //must dump additions from ofstream buffer into a file
      case "help":
        get_menu(menu); //Prints menu line by line when user enters "help"

      case "exit":
        cout << "Goodbye!";
        break;

      default:
        cout << "Enter one of the following commands!";
        get_menu(menu);
        continue;
    };
  };
  return 0;
};

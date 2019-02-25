#include <string>
#include "song.h"

using namespace std;

string fname;

void get_menu(vector<string> const &menu);

void add_song(music::Song& s);

void save_song(music::Song& s, fname);

void list_song(fname);

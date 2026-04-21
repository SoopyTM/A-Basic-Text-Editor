#include <ncurses.h>
#include "classes-file.h"

void ScreenStuff::StartScreen() {
  initscr();
  raw();
  noecho();
  keypad(stdscr, TRUE);
}

void ScreenStuff::DoBackspace() {
  if (!FileString.empty()) {
    if (FileString.back() != '\n') {
      FileString.pop_back();
      int y, x;
      getyx(stdscr, y, x);
  
      if (x > 0) {
        move(y, x - 1);
        delch();
      }
    }
  }
}

void ScreenStuff::SaveFileIntoFileString(char UserInput) {
  FileString += UserInput;
}

void ScreenStuff::InsertTab() {
  FileString += "  ";
  printw("  ");
}

void ScreenStuff::SaveToFile(std::string WantedFile) {
  std::ofstream file(WantedFile);
  file << FileString;
  file.close();
}

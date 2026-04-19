#include <ncurses.h>
#include "classes-file.h"

void ScreenStuff::LoadFromFile(std::string WantedFile) {
  std::ifstream file(WantedFile);
  FileString = "";
  std::string line;
  while (std::getline(file, line)) {
    FileString += line;
    FileString += '\n';
  }
  file.close();
}

void ScreenStuff::StartScreen() {
  initscr();
  raw();
  noecho();
  keypad(stdscr, TRUE);
}

void ScreenStuff::SaveFileIntoFileString(char UserInput) {
  FileString += UserInput;
}

void ScreenStuff::SaveToFile(std::string WantedFile) {
  std::ofstream file(WantedFile);
  file << FileString;
  file.close();
}

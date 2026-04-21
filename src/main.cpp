#include <iostream>
#include <ncurses.h>
#include <vector>
#include <algorithm>
#include <filesystem>

#include "classes-file.h"

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cout << "Enter the file and only the file you want to create." << std::endl;
    return 0;
  }
  ScreenStuff ScreenObject;

  if (std::filesystem::exists(argv[1])) {
    std::cout << "The file you want to create already exists. Please enter a file that doesn't exist." << std::endl;
    return 0;
  }

  ScreenObject.StartScreen();

  std::vector<int> AllowedSpecialCharacters = {24, 19, 10, 127, 8, 9};

  while (1) {
    int UserInput = getch();

    if (UserInput >= 32 || UserInput == KEY_BACKSPACE || std::find(AllowedSpecialCharacters.begin(), AllowedSpecialCharacters.end(), UserInput) != AllowedSpecialCharacters.end()) {
      switch (UserInput) {
        case 24:
          endwin();
          return 0;
  
        case 19:
          ScreenObject.SaveToFile(argv[1]);
          continue;
     
        case 10:
          ScreenObject.SaveFileIntoFileString('\n');
          printw("\n");
          break;

        case KEY_STAB:
        case 9:
          ScreenObject.InsertTab();
          break;
        
        case KEY_BACKSPACE:
        case 127:
        case 8:
          ScreenObject.DoBackspace();
          break;
  
        default:
          ScreenObject.SaveFileIntoFileString(UserInput);
          printw("%c", UserInput);
          break;
      }
  
      refresh();
    }
  }

  endwin();

  return 0;
}

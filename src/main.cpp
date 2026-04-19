#include <iostream>
#include <ncurses.h>

#include "classes-file.h"

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cout << "Enter the file and only the file you want to create/edit." << std::endl;
    return 0;
  }
  ScreenStuff ScreenObject;

  ScreenObject.LoadFromFile(argv[1]);
  ScreenObject.StartScreen();

  while (1) {
    char UserInput = getch();

    if (UserInput == 24) {
      endwin();
      return 0;
    }

    if (UserInput == 19) {
      ScreenObject.SaveToFile(argv[1]);
      continue;
    }

    if (UserInput == 10) {
      ScreenObject.SaveFileIntoFileString('\n');
      printw("\n");
    } else {
      ScreenObject.SaveFileIntoFileString(UserInput);
      printw("%c", UserInput);
    }

    refresh();
  }

  endwin();

  return 0;
}

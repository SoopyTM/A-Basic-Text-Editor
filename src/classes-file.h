#include <vector>
#include <string>
#include <fstream>

class ScreenStuff {
  private:
    std::string FileString;

  public:
    void StartScreen();
    void DoBackspace();
    void SaveFileIntoFileString(char UserInput);
    void InsertTab();
    void SaveToFile(std::string WantedFile);
};

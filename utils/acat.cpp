#include <fstream>
#include <string>
#include <iostream>

static void printfile(char* filename);

int main(int argc, char *argv[])
{
  for(int i = 1; i < argc; i++)
  {
    printfile(argv[i]);
  }
}

static void printfile(char* filename)
{
  std::ifstream file(filename);
  std::string line;
  while( std::getline(file, line) )
  {
    std::cout << line << "\n";
  }
}

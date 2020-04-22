// countDucks.cpp
// P. Conrad for CS16, Winter 2015
// Example program to read from file and count occurences

#include <iostream> // for printf()
#include <cstdlib> // for exit(), perror()
#include <fstream> // for ifstream
#include <vector> // for vector
using namespace std;

vector<string> lines(istream* ss) {
  string s;
  vector<string> lines;
  while (getline(*ss, s)) {
    lines.push_back(s);
  }

  return lines;
}



int main(int argc, char *argv[])
{
  int animals = 0;
  int not_ducks = 0;

  if (argc!=2) {
    // if argc is not 2, print an error message and exit
    cerr << "Usage: "<< argv[0] << " inputFile" << endl;
    exit(1); // defined in cstdlib
  }
  char* file_name = argv[1];
  ifstream animal_file;
  animal_file.open(file_name);
  vector<string> animal_list = lines(&animal_file);

  animals = animal_list.size();

  for (int i = 0; i < animals; i++) {
    if (animal_list[i] != "duck") {
      not_ducks += 1;
    }
  }

  int ducks = animals - not_ducks;

  cout << "Report for "<< file_name << ":" << endl
       << "   " << "Animals count:" << "   " << animals << endl
       << "   " << "Duck count:" << "      " << ducks << endl
       << "   " << "Non duck count:" << "  " << not_ducks << endl;

  return 0;
}


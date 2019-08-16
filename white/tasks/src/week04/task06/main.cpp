#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
  const string path = "input.txt";
  ifstream input(path);
  int rows = 0, cols = 0;

  input >> rows;
  input.ignore(1);
  input >> cols;
  input.ignore(1);

  string line;
  for (int i = 0; i < rows; i++)
  {
    getline(input, line, '\n');
    istringstream string_stream(line);
    for (int j = 0; j < cols; j++)
    {
      string value;
      getline(string_stream, value, ',');
      cout << setw(10) << setfill(' ') << value;

      if (j < cols - 1)
      {
        cout << ' ';
      }
    }

    if(i < rows - 1)
    {
      cout << '\n';
    }
  }

  return 0;
}

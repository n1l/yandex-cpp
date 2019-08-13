#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
  const string in_path = "input.txt";
  const string out_path = "output.txt";

  ifstream input(in_path);
  ofstream output(out_path);

  if (input.is_open())
  {
    string line;
    while (getline(input, line))
    {
      output << line << endl;
    }
  }
  else
  {
    cout << "error!" << endl;
  }

  return 0;
}

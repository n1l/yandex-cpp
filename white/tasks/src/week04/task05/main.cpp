#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
  const string path = "input.txt";

  ifstream input(path);

  cout << fixed << setprecision(3);

  if (input.is_open())
  {
    double number;
    while (input >> number)
    {
      cout << number << endl;
    }
  }
  else
  {
    cout << "error!" << endl;
  }

  return 0;
}

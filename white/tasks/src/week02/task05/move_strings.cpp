#include <vector>
#include <iostream>

using namespace std;

void MoveStrings(vector<string> &source, vector<string> &destination)
{
  for (string item : source)
  {
    destination.push_back(item);
  }

  source.clear();
}
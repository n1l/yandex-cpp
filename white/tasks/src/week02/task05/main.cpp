#include <iostream>
#include <vector>

using namespace std;

void MoveStrings(vector<string> &source, vector<string> &destination)
{
  for (string item : source)
  {
    destination.push_back(item);
  }

  source.clear();
}

int main()
{
  vector<string> source = {"a", "b", "c"};
  vector<string> destination = {"z"};

  MoveStrings(source, destination);

  for (string item : destination)
  {
    cout << item;
  }

  return 0;
}
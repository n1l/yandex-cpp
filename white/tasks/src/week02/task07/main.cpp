#include <iostream>
#include <vector>

using namespace std;

vector<int> Reversed(const vector<int> &source)
{
  vector<int> result;

  for (int i = source.size() - 1; i >= 0; --i)
  {
    result.push_back(source[i]);
  }

  return result;
}

int main()
{
  vector<int> source = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  vector<int> rev = Reversed(source);

  for (int item : rev)
  {
    cout << item;
  }

  return 0;
}
#include <iostream>
#include <set>

using namespace std;

int main()
{
  int ops;
  set<string> unique_strings;

  cin >> ops;

  for (int i = 0; i < ops; i++)
  {
    string input;
    cin >> input;
    unique_strings.insert(input);
  }

  cout << unique_strings.size() << endl;

  return 0;
}
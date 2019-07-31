#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
  int ops;
  string str1;
  string str2;

  cin >> ops;

  for (int i = 0; i < ops; i++)
  {
    cin >> str1 >> str2;

    map<char, int> first;
    map<char, int> second;

    for (char c : str1)
    {
      first[c]++;
    }

    for (char c : str2)
    {
      second[c]++;
    }

    cout << (first == second ? "YES" : "NO") << endl;
  }

  return 0;
}
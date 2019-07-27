#include <iostream>
#include <algorithm>

using namespace std;

bool IsPalindrom(string s)
{
  string reversed = s;
  reverse(reversed.begin(), reversed.end());

  return reversed == s;
}


int main()
{
  string input;

  cin >> input;

  cout << IsPalindrom(input);

  return 0;
}
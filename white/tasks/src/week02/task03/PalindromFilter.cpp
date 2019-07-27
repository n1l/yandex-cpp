#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool IsPalindrom(string s)
{
  for (size_t i = 0; i < s.size() / 2; ++i)
  {
    if (s[i] != s[s.size() - i - 1])
    {
      return false;
    }
  }
  return true;
}

vector<string> PalindromFilter(vector<string> words, int minLength)
{
  vector<string> result;

  for (string s : words)
  {
    if (IsPalindrom(s) && s.size() >= minLength)
    {
      result.push_back(s);
    }
  }

  return result;
}
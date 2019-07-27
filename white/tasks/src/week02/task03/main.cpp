#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool IsPalindrom(string s)
{
  for (int i = 0; i < s.size() / 2; ++i)
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

int main()
{
  vector<string> prms;
  string input;
  while(cin >> input)
  {
    if(input == "end")
    {
      break;
    }

    prms.push_back(input);
  }
  vector<string> result = PalindromFilter(prms, 2);

  for(string s : result)
  {
    cout << s << " ";
  }
}
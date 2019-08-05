#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class SortedStrings
{
public:
  void AddString(const string &s)
  {
    _values.push_back(s);
    sort(begin(_values), end(_values));
  }

  vector<string> GetSortedStrings()
  {
    return _values;
  }

private:
  vector<string> _values;
};
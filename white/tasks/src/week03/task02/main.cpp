#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int ops;
  cin >> ops;

  vector<string> values(ops);

  for (string &value : values)
  {
    cin >> value;
  }

  sort(begin(values), end(values),
       [](const string &left, const string &right) {
         return lexicographical_compare(
             begin(left), end(left),
             begin(right), end(right),
             [](char c_left, char c_right) { return tolower(c_left) < tolower(c_right); });
       });

  for (string &value : values)
  {
    cout << value << ' ';
  }

  cout << endl;

  return 0;
}
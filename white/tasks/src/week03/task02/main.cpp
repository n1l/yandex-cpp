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
       [](string first, string second) {
         return transform(first.begin(), first.end(), first.begin(), ::tolower) <
                transform(second.begin(), second.end(), second.begin(), ::tolower);
       });

  for (string &value : values)
  {
    cout << value << ' ';
  }

  cout << endl;

  return 0;
}
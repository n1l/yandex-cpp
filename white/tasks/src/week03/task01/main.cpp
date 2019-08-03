#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int ops;
  vector<int> values;

  cin >> ops;

  for (int i = 0; i < ops; i++)
  {
    int value;
    cin >> value;
    values.push_back(value);
  }

  sort(begin(values), end(values),
       [](int first, int second) { return abs(first) < abs(second); });

  for (int i : values)
  {
    cout << i << ' ';
  }

  cout << endl;

  return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int ops;
  cin >> ops;

  vector<int> values(ops);

  for (int &value : values)
  {
    cin >> value;
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
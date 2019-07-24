#include <iostream>

using namespace std;

/*
  10 2 => 5
  3 5 => 0
  11 0 => Impossible
  1000000 1000000 => 1
  0 0 => Impossible
 */


int main()
{
  int a, b;

  cin >> a >> b;

  if (b == 0)
  {
    cout << "Impossible";
  }
  else if (a == 0)
  {
    cout << a;
  }
  else
  {
    cout << a / b;
  }

  return 0;
}
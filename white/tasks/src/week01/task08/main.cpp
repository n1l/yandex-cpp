#include <iostream>

using namespace std;

/*
  25 27 => 1
  12 16 => 4
  13 13 => 13
 */
int main()
{
  int a, b;
  cin >> a >> b;

  while (a > 0 && b > 0)
  {
    if (a > b)
    {
      a %= b;
    }
    else
    {
      b %= a;
    }
  }

  cout << a + b;

  return 0;
}
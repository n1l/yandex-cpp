#include <iostream>

using namespace std;

/*
  25 27 => 1
  12 16 => 4
  13 13 => 13
 */
int main()
{
  int a, b, c;

  cin >> a >> b;

  if(b > a)
  {
    c = b;
    b = a;
    a = c;
  }

  c = 0;

  while (b)
  {
    c = a % b;
    a = b;
    b = c;
  }

  if (a < 0)
  {
    cout << -a;
  }

  cout << a;

  return 0;
}
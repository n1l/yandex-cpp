#include <iostream>

using namespace std;

/*
  1 10 => 2 4 6 8 10
  2 3 => 2
  9 11 => 10
 */
int main()
{
  int low, high;

  cin >> low >> high;

  for (int i = low; i <= high; i++)
  {
    if (i % 2 == 0)
    {
      cout << i << ' ';
    }
  }

  return 0;
}
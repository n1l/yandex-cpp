#include <iostream>

using namespace std;

/*
   cases:
   100 110 120 5 10 => 100
   115 110 120 5 10 => 109.25
   150 110 120 5 12.5 => 131.25
   0 0 0 0 0 => 0
   0 110 120 5 10 => 0
   100 110 120 -5 -10 => 100
   115 110 120 -5 -10 => 120.75
*/
const int ratio = 100;

int main()
{
  double cost, costX, costY, discountX, discountY;

  cin >> cost >> costX >> costY >> discountX >> discountY;

  if (cost > costY && discountY != 0)
  {
    cout << cost - (cost * (discountY / ratio));
  }
  else if (cost > costX && discountX != 0)
  {
    cout << cost - (cost * (discountX / ratio));
  }
  else
  {
    cout << cost;
  }

  return 0;
}
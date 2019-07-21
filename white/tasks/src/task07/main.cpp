#include <iostream>
#include <string>

using namespace std;

const int maxCount = 2;
const char fChar = 'f';
const int fOne = -1;
const int fNothing = -2;

/*
  comfort => -1
  coffee => 3
  car => -2
 */
int main()
{
  string input;

  cin >> input;

  int fCounter = 0;

  for (int i = 0; i < input.length(); i++)
  {
    if (input[i] == fChar)
    {
      fCounter++;

      if (fCounter == maxCount)
      {
        cout << i;
        break;
      }
    }
  }

  if (fCounter == 1)
  {
    cout << fOne;
  }

  if (fCounter == 0)
  {
    cout << fNothing;
  }
}
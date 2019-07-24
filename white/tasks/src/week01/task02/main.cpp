#include <iostream>
#include <string>

using namespace std;

int main()
{
  string first;
  string second;
  string third;

  cin >> first >> second >> third;

  if (first <= second && first <= third)
  {
    cout << first;
  }
  else if (second <= first && second <= third)
  {
    cout << second;
  }
  else
  {
    cout << third;
  }

  return 0;
}
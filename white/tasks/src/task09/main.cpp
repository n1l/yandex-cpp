#include <iostream>
#include <vector>

using namespace std;

/*
  5 => 101
  32 => 100000
  1 => 1
  12 => 1100
  0 => 0
 */
int main()
{
  int input, bit = 0;
  vector<int> body;

  cin >> input;

  if (input == 0)
  {
    cout << 0;
  }

  while (input)
  {
    bit = input % 2;
    body.push_back(bit);
    input = input / 2;
  }

  for (int i = body.size() - 1; i >= 0; i--)
  {
    cout << body[i];
  }

  return 0;
}
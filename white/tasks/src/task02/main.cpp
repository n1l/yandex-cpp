#include<iostream>
#include<string>

using namespace std;

int main()
{
  string first;
  string second;
  string third;

  cin >> first >> second >> third;

  if(first < second && first < third)
  {
    cout << first;
    return 0;
  }
  else if(second < first && second < third)
  {
    cout << second;
    return 0;
  }
  else if(third < first && third < second)
  {
    cout << third;
    return 0;
  }
  else
  {
    cout << first;

    return 0;
  }
}
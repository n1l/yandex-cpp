#include <iostream>
#include <string>
#include <fcntl.h>

using namespace std;

int main()
{
  _setmode(_fileno(stdout), _O_U16TEXT);
  _setmode(_fileno(stdin),  _O_U16TEXT);

  wstring first;
  wstring second;
  wstring third;

  wcin >> first >> second >> third;

  if (first < second && first < third)
  {
    wcout << first;
    return 0;
  }
  else if (second < first && second < third)
  {
    wcout << second;
    return 0;
  }
  else if (third < first && third < second)
  {
    wcout << third;
    return 0;
  }
  else
  {
    wcout << first;
    return 0;
  }
}
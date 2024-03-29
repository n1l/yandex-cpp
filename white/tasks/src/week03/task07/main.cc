#include <iostream>
#include <vector>
#include <map>
#include <set>
#include "person.h"

using namespace std;

int main()
{
  Person person("Polina", "Sergeeva", 1960);
  for (int year : {1959, 1960})
  {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeFirstName(1965, "Appolinaria");
  person.ChangeLastName(1967, "Ivanova");
  for (int year : {1965, 1967})
  {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  return 0;
}
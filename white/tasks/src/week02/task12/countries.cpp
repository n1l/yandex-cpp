#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
  int ops;
  string str1;
  string str2;

  map<string, string> countries;

  cin >> ops;

  for (int i = 0; i < ops; i++)
  {
    string operation;
    cin >> operation;

    if (operation == "CHANGE_CAPITAL")
    {
      string old_capital;
      string country;
      string new_capital;

      cin >> country >> new_capital;

      if (countries.count(country) > 0)
      {
        if (countries[country] == new_capital)
        {
          cout << "Country " << country << " hasn't changed its capital" << endl;
        }
        else
        {
          old_capital = countries[country];
          countries[country] = new_capital;

          cout << "Country " << country << " has changed its capital from " << old_capital << " to " << new_capital << endl;
        }
      }
      else
      {
        countries[country] = new_capital;
        cout << "Introduce new country " << country << " with capital " << new_capital << endl;
      }
    }

    if (operation == "RENAME")
    {
      string old_country_name;
      string new_country_name;

      cin >> old_country_name >> new_country_name;

      if (old_country_name == new_country_name || countries.count(old_country_name) == 0 || countries.count(new_country_name))
      {
        cout << "Incorrect rename, skip" << endl;
      }
      else
      {
        string capital = countries[old_country_name];
        countries.erase(old_country_name);
        countries[new_country_name] = capital;

        cout << "Country " << old_country_name << " with capital " << capital << " has been renamed to " << new_country_name << endl;
      }
    }

    if (operation == "ABOUT")
    {
      string country_name;

      cin >> country_name;

      if (countries.count(country_name) == 0)
      {
        cout << "Country " << country_name << " doesn't exist" << endl;
      }
      else
      {
        cout << "Country " << country_name << " has capital " << countries[country_name] << endl;
      }
    }

    if (operation == "DUMP")
    {
      if (countries.size() == 0)
      {
        cout << "There are no countries in the world" << endl;
      }
      else
      {
        for (auto country : countries)
        {
          cout << country.first << "/" << country.second << " ";
        }

        cout << endl;
      }
    }
  }

  return 0;
}
#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Person
{
public:
  Person(const string &first_name, const string &last_name, int year)
  {
    birth_ = year;
    first_name_history_[birth_] = first_name;
    last_name_history_[birth_] = last_name;
  }

  void ChangeFirstName(int year, const string &first_name)
  {
    if (year < birth_)
    {
      return;
    }

    first_name_history_[year] = first_name;
  }

  void ChangeLastName(int year, const string &last_name)
  {
    if (year < birth_)
    {
      return;
    }

    last_name_history_[year] = last_name;
  }

  string GetFullName(int year) const
  {
    if (year < birth_)
    {
      return "No person";
    }

    string first_name = GetDataForYear(first_name_history_, year),
           last_name = GetDataForYear(last_name_history_, year);

    if (first_name == "" && last_name == "")
    {
      return "Incognito";
    }

    if (first_name != "" && last_name == "")
    {
      return first_name + ' ' + "with unknown last name";
    }

    if (last_name != "" && first_name == "")
    {
      return last_name + ' ' + "with unknown first name";
    }

    return first_name + ' ' + last_name;
  }

  string GetFullNameWithHistory(int year) const
  {
    if (year < birth_)
    {
      return "No person";
    }

    string first_name = GetDataForYearWithHistory(first_name_history_, year),
           last_name = GetDataForYearWithHistory(last_name_history_, year);

    if (first_name == "" && last_name == "")
    {
      return "Incognito";
    }

    if (first_name != "" && last_name == "")
    {
      return first_name + ' ' + "with unknown last name";
    }

    if (last_name != "" && first_name == "")
    {
      return last_name + ' ' + "with unknown first name";
    }

    return first_name + ' ' + last_name;
  }

private:
  string GetDataForYear(const map<int, string> &history, int year) const
  {
    string data = "";
    for (const auto &item : history)
    {
      if (item.first > year)
      {
        return data;
      }

      data = item.second;
    }

    return data;
  }

  string GetDataForYearWithHistory(const map<int, string> &history, int year) const
  {
    vector<string> data_history;
    string data = "";
    string previous_data = "";

    for (const auto &item : history)
    {
      if (item.first <= year)
      {
        data = item.second;
        if (previous_data != "" && previous_data != data)
        {
          data_history.push_back(previous_data);
        }
        previous_data = data;
      }
      else
      {
        break;
      }
    }

    string history_result = "";

    for (int i = data_history.size() - 1; i >= 0; i--)
    {
      if (history_result != "")
      {
        history_result += (", " + data_history[i]);
      }
      else
      {
        history_result += data_history[i];
      }
    }

    if (history_result == "")
    {
      return data;
    }
    else
    {
      return data + " (" + history_result + ')';
    }
  }

private:
  map<int, string> first_name_history_;
  map<int, string> last_name_history_;
  int birth_;
};
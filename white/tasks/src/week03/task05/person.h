#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Person
{
public:
  void ChangeFirstName(int year, const string &first_name)
  {
    first_name_history_[year] = first_name;
  }

  void ChangeLastName(int year, const string &last_name)
  {
    last_name_history_[year] = last_name;
  }

  string GetFullName(int year)
  {
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

  string GetFullNameWithHistory(int year)
  {
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
  string GetDataForYear(const map<int, string> &history, int year)
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

  string GetDataForYearWithHistory(const map<int, string> &history, int year)
  {
    set<string> data_history;
    string data = "";
    string previous_data = "";

    for (const auto &item : history)
    {
      if (item.first <= year)
      {
        if (data != "")
        {
          previous_data = data;
        }
        if (previous_data != "")
        {
          data_history.insert(previous_data);
        }
        data = item.second;
      }
      else
      {
        break;
      }
    }

    string history_result = "";

    for (const string &item : data_history)
    {
      if (history_result != "")
      {
        history_result += (", " + item);
      }
      else
      {
        history_result += item;
      }
    }

    if (data == "" && history_result == "")
    {
      return "";
    }

    return data + " (" + history_result + ')';
  }

private:
  map<int, string> first_name_history_;
  map<int, string> last_name_history_;
};
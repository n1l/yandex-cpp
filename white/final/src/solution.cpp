#include <iostream>
#include <string>
#include <map>
#include <set>
#include <iomanip>

using namespace std;

class Date
{
public:
  Date(int year = 0, int month = 1, int day = 1)
  {
    if (month < 1 || month > 12)
    {
      throw invalid_argument("Month value is invalid: " + to_string(month));
    }

    if (day < 1 || day > 31)
    {
      throw invalid_argument("«Day value is invalid: " + to_string(day));
    }

    year_ = year;
    month_ = month;
    day_ = day;
  }

  int GetYear() const
  {
    return year_;
  }

  int GetMonth() const
  {
    return month_;
  }

  int GetDay() const
  {
    return day_;
  }

private:
  int day_;
  int month_;
  int year_;
};

bool operator<(const Date &left, const Date &right)
{
  if (left.GetYear() < right.GetYear())
  {
    if (left.GetMonth() < right.GetMonth())
    {
      if (left.GetDay() < right.GetDay())
      {
        return true;
      }
      return false;
    }
    return false;
  }
  return false;
}

ostream &operator<<(ostream &stream, const Date &date)
{
  stream << setw(4) << setfill('0') << date.GetYear() << '-';
  stream << setw(2) << setfill('0') << date.GetMonth() << '-';
  stream << setw(2) << setfill('0') << date.GetDay();
  return stream;
}

istream &operator>>(istream &stream, Date &date)
{
  int year, month, day;
  char delimiter;
  string input;

  stream >> input;

  stringstream input_stream(input);
  input_stream >> year >> delimiter >> month >> delimiter >> day;
  if (input_stream && delimiter == '-')
  {
    date = Date(year, month, day);
  }
  else
  {
    throw invalid_argument("Wrong date format: " + input);
  }

  return stream;
}

class Database
{
public:
  void AddEvent(const Date &date, const string &event)
  {
    db_[date].insert(event);
  }

  bool DeleteEvent(const Date &date, const string &event)
  {
    if (db_.count(date) == 0)
    {
      return false;
    }

    set<string> &events = db_[date];
    if (events.count(event) == 0)
    {
      return false;
    }

    events.erase(event);
    return true;
  }

  int DeleteDate(const Date &date)
  {
    int result = 0;
    if (db_.count(date) > 0)
    {
      result = db_[date].size();
      db_.erase(date);
    }

    return result;
  }

  void Find(const Date &date) const
  {
    if (db_.count(date) == 0)
    {
      return;
    }

    set<string> events = db_.at(date);
    for (const string event : events)
    {
      cout << event << endl;
    }
  }

  void Print() const
  {
    for (const auto &event : db_)
    {
      for (const string &event_title : event.second)
      {
        cout << event.first << ' ' << event_title << endl;
      }
    }
  }

private:
  map<Date, set<string>> db_;
};

struct Command
{
  string text;
  string event;
  Date date;
};

istream &operator>>(istream &stream, Command &command)
{
  string command_text, event_title;
  Date date;

  stream >> command_text;
  if (command_text == "")
  {
    command = {command_text};
    return stream;
  }
  if (command_text == "Print")
  {
    command = {command_text};
    return stream;
  }
  stream >> date;
  stream >> event_title;
  if (stream)
  {
    command = {command_text, event_title, date};
  }
  else
  {
    command = {command_text, "", date};
  }

  return stream;
}

/* case #1
Add 0-1-2 event1
Add 1-2-3 event2
Print
*/

/* case #2
Add 0-1-2 event1
Add 1-2-3 event2
Find 0-1-2

Del 0-1-2
Print
Del 1-2-3 event2
Del 1-2-3 event2
*/

/* case #3
Adskjdksjdksjdskd 1-2-3 event2
*/

/* case #4
Add fjdkjfklsdjfkldsjk event1
*/

/* case #5
Del 0-1-2
Find 0-1-2
Add 0-1-2 event1
Add 1-2-3 event2
Find 0-1-2
Del 0-1-2
*/

int main()
{
  Database db;
  Command command;

  string command_text;
  while (getline(cin, command_text))
  {
    try
    {
      stringstream command_stream(command_text);
      command_stream >> command;

      if (command.text == "Add")
      {
        db.AddEvent(command.date, command.event);
      }
      else if (command.text == "Find")
      {
        db.Find(command.date);
      }
      else if (command.text == "Del")
      {
        if (command.event != "")
        {
          if (db.DeleteEvent(command.date, command.event))
          {
            cout << "Deleted successfully" << endl;
          }
          else
          {
            cout << "Event not found" << endl;
          }
        }
        else
        {
          int deleted = db.DeleteDate(command.date);
          cout << "Deleted " << deleted << " events" << endl;
        }
      }
      else if (command.text == "Print")
      {
        db.Print();
      }
      else if (command.text == "")
      {
        continue;
      }
      else
      {
        cout << "Unknown command: " << command.text << endl;
      }
    }
    catch (const exception &e)
    {
      cout << e.what() << endl;
    }
  }

  return 0;
}
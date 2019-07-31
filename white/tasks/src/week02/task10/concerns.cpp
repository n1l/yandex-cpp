#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// test case
// 12
// ADD 5 Salary
// ADD 31 Walk
// ADD 30 WalkPreparations
// NEXT
// DUMP 5
// DUMP 28
// NEXT
// DUMP 31
// DUMP 30
// DUMP 28
// ADD 28 Payment
// DUMP 28

int main()
{
  int ops;
  int month = 0;
  vector<vector<vector<string>>> months{
      vector<vector<string>>(31), // january
      vector<vector<string>>(28), // february
      vector<vector<string>>(31), // march
      vector<vector<string>>(30), // april
      vector<vector<string>>(31), // may
      vector<vector<string>>(30), // june
      vector<vector<string>>(31), // jule
      vector<vector<string>>(31), // august
      vector<vector<string>>(30), // september
      vector<vector<string>>(31), // november
      vector<vector<string>>(30), // october
      vector<vector<string>>(31), // december
  };

  vector<vector<string>> &currentMonth = months[month++];

  cin >> ops;

  for (int i = 0; i < ops; i++)
  {
    string operationCode;
    cin >> operationCode;

    if (operationCode == "ADD")
    {
      int day;
      string task;

      cin >> day >> task;

      currentMonth[day - 1].push_back(task);
    }

    if (operationCode == "NEXT")
    {
      month =  month % 12;
      vector<vector<string>> &next = months[month];

      for (int i = 0; i < currentMonth.size(); i++)
      {
        if (i < next.size())
        {
          next[i] = currentMonth[i];
        }
        else
        {
          next[next.size() - 1]
              .insert(
                  end(next[next.size() - 1]),
                  begin(currentMonth[i]),
                  end(currentMonth[i]));
        }
      }

      currentMonth = next;
      month++;
    }

    if (operationCode == "DUMP")
    {
      int day;
      cin >> day;

      cout << currentMonth[day - 1].size() << " ";

      for (string task : currentMonth[day - 1])
      {
        cout << task << " ";
      }

      cout << endl;
    }
  }

  return 0;
}
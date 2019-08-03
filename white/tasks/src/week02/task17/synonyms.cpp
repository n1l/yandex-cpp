#include <iostream>
#include <map>
#include <set>

using namespace std;

int main()
{
  int ops;
  map<string, set<string>> words;
  map<set<string>, int> queries;

  cin >> ops;

  for (int i = 0; i < ops; i++)
  {
    string command;

    cin >> command;

    if (command == "ADD")
    {
      string first, second;

      cin >> first >> second;

      words[first].insert(second);
      words[second].insert(first);

      set<string> s = {first, second};
      queries[s]++;
    }

    if (command == "COUNT")
    {
      string word;

      cin >> word;

      cout << words[word].size() << endl;
    }

    if (command == "CHECK")
    {
      string first, second;

      cin >> first >> second;

      set<string> s = {first, second};
      string message = queries[s] > 0 ? "YES" : "NO";

      cout << message << endl;
    }
  }

  return 0;
}
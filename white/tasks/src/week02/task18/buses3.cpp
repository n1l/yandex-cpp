#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main()
{
  int ops;
  map<set<string>, int> buses;

  cin >> ops;

  for (int i = 0; i < ops; i++)
  {
    int stops_count;
    cin >> stops_count;

    vector<string> input_stops(stops_count);

    for (string &stop : input_stops)
    {
      cin >> stop;
    }

    set<string> stops(begin(input_stops), end(input_stops));

    if (buses.count(stops) == 0)
    {
      int bus_number = buses.size() + 1;
      buses[stops] = bus_number;
      cout << "New bus " << buses[stops] << endl;
    }
    else
    {
      cout << "Already exists for " << buses[stops] << endl;
    }
  }

  return 0;
}
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
    set<string> stops;

    for (int j = 0; j < stops_count; j++)
    {
      string stop;
      cin >> stop;
      stops.insert(stop);
    }

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
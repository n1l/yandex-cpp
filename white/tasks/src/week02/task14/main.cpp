#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
  int ops;
  map<vector<string>, int> buses;

  cin >> ops;

  for (int i = 0; i < ops; i++)
  {
    int stops_count;
    cin >> stops_count;

    vector<string> stops(stops_count);

    for (string &stop : stops)
    {
      cin >> stop;
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
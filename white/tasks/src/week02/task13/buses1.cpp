#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
  int ops;
  map<string, vector<string>> buses;
  map<string, vector<string>> bus_stops;

  cin >> ops;

  for (int i = 0; i < ops; i++)
  {
    string command;

    cin >> command;

    if (command == "NEW_BUS")
    {
      string bus;
      int stops_count;

      cin >> bus >> stops_count;

      vector<string> stops(stops_count);

      for (string &stop : stops)
      {
        cin >> stop;

        if (stop == "")
        {
          break;
        }

        buses[bus].push_back(stop);
        bus_stops[stop].push_back(bus);
      }
    }

    if (command == "BUSES_FOR_STOP")
    {
      string stop;

      cin >> stop;

      if (bus_stops.count(stop) == 0)
      {
        cout << "No stop" << endl;
      }
      else
      {
        for (string &bus : bus_stops[stop])
        {
          cout << bus << " ";
        }
        cout << endl;
      }
    }

    if (command == "STOPS_FOR_BUS")
    {
      string bus;

      cin >> bus;

      if (buses.count(bus) == 0)
      {
        cout << "No bus" << endl;
      }
      else
      {
        for (string &stop : buses[bus])
        {
          cout << "Stop " << stop << ":";

          if (bus_stops[stop].size() == 1)
          {
            cout << " no interchange";
          }
          else
          {
            for (string &bus_from_stop : bus_stops[stop])
            {
              if (bus_from_stop != bus)
              {
                cout << " " << bus_from_stop;
              }
            }
          }

          cout << endl;
        }
      }
    }

    if (command == "ALL_BUSES")
    {
      if (buses.size() == 0)
      {
        cout << "No buses" << endl;
      }

      for (const pair<string, vector<string>> &bus : buses)
      {
        cout << "Bus " << bus.first << ":";
        for (const string &stop : bus.second)
        {
          cout << " " << stop;
        }

        cout << endl;
      }
    }
  }

  return 0;
}
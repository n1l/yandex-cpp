#include <iostream>
#include <vector>

using namespace std;

int average(const vector<int> &vector)
{
  int sum = 0;
  for (int item : vector)
  {
    sum += item;
  }
  return sum / vector.size();
}

int main()
{
  int n = 0;
  int avg = 0;
  int count = 0;

  cin >> n;

  vector<int> values(n);
  for (int i = 0; i < n; i++)
  {
    cin >> values[i];
  }

  avg = average(values);

  for (int i = 0; i < values.size(); i++)
  {
    if (values[i] > avg)
    {
      count++;
    }
  }

  cout << count << endl;

  for (int i = 0; i < values.size(); i++)
  {
    if (values[i] > avg)
    {
      cout << i << " ";
    }
  }

  return 0;
}
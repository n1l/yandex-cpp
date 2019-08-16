#include <iostream>
#include <vector>

using namespace std;


bool find132pattern(vector<int> &nums)
{
  for (int i = 0; i < nums.size() - 2; i++)
  {
    for (int j = i + 1; j < nums.size() - 1; j++)
    {
      for (int k = j + 1; k < nums.size(); k++)
      {
        if (nums[k] > nums[i] && nums[j] > nums[k])
        {
          cout << nums[i] << ' ' << nums[k] << ' ' << nums[j];
          return true;
        }
      }
    }
  }
  return false;
}

int main()
{
  vector<int> n = {1, 2, 3, 4};
  cout << (find132pattern(n) ? "True" : "False") << endl;

  n = {3, 1, 4, 2};
  cout << (find132pattern(n) ? "True" : "False") << endl;

  n = {-1, 3, 2, 0};
  cout << (find132pattern(n) ? "True" : "False") << endl;

  n = {3, 5, 0, 3, 4};
  cout << (find132pattern(n) ? "True" : "False") << endl;

  return 0;
}
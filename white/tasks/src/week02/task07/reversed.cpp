#include <vector>

using namespace std;

vector<int> Reversed(const vector<int> &source)
{
  vector<int> result;

  for (int i = source.size() - 1; i >= 0; --i)
  {
    result.push_back(source[i]);
  }

  return result;
}
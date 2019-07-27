#include <iostream>
#include <vector>

using namespace std;

// vector<int> Reversed(const vector<int> &source)
// {
//   vector<int> result;

//   for (int i = source.size() - 1; i >= 0; --i)
//   {
//     result.push_back(source[i]);
//   }

//   return result;
// }

vector<int> Reversed(const vector<int> &input)
{
  auto seq = input;
  for (int i = 0; i < seq.size() / 2; ++i)
  {
    auto tmp = seq[i];
    seq[i] = seq[seq.size() - 1 - i];
    seq[seq.size() - 1 - i] = tmp;
  }
  return seq;
}

int main()
{
  vector<int> source = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  vector<int> rev = Reversed(source);

  for (int item : rev)
  {
    cout << item << " ";
  }

  cout << endl;

  for (int item : source)
  {
    cout << item << " ";
  }

  return 0;
}
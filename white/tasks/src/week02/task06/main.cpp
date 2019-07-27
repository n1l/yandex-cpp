#include <iostream>
#include <vector>

using namespace std;

void Reverse(std::vector<int> &source)
{
  for (size_t i = 0; i < source.size() / 2; i++)
  {
    int temp = source[source.size() - i - 1];
    source[source.size() - i - 1] = source[i];
    source[i] = temp;
  }
}

int main()
{
  vector<int> source = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  Reverse(source);

  for (int item : source)
  {
    cout << item;
  }

  return 0;
}
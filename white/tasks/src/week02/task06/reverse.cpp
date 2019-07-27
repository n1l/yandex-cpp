#include <vector>

void Reverse(std::vector<int> &source)
{
  for (size_t i = 0; i < source.size() / 2; i++)
  {
    int temp = source[source.size() - i - 1];
    source[source.size() - i - 1] = source[i];
    source[i] = temp;
  }
}
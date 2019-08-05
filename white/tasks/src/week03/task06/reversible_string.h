#include <iostream>
#include <algorithm>

using namespace std;

class ReversibleString
{
public:
  ReversibleString()
  {
    source_ = "";
  }

  ReversibleString(const string &source)
  {
    source_ = source;
  }

  string ToString() const
  {
    return source_;
  }

  void Reverse()
  {
    reverse(source_.begin(), source_.end());
  }

private:
  string source_;
};
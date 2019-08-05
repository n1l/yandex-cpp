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

int main()
{
  ReversibleString s("live");
  s.Reverse();
  cout << s.ToString() << endl;

  s.Reverse();
  const ReversibleString &s_ref = s;
  string tmp = s_ref.ToString();
  cout << tmp << endl;

  ReversibleString empty;
  cout << '"' << empty.ToString() << '"' << endl;

  return 0;
}

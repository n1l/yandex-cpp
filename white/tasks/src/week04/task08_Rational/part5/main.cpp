#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int CalculateGCD(int numerator, int denominator)
{
  while (numerator > 0 && denominator > 0)
  {
    if (numerator > denominator)
    {
      numerator %= denominator;
    }
    else
    {
      denominator %= numerator;
    }
  }

  return numerator + denominator;
}

class Rational
{
public:
  Rational()
  {
    numerator_ = 0;
    denominator_ = 1;
  }

  Rational(int numerator, int denominator)
  {
    int gcd = CalculateGCD(abs(numerator), abs(denominator));

    numerator /= gcd;
    denominator /= gcd;

    if (!IsPositive(numerator, denominator))
    {
      numerator = -(abs(numerator));
      denominator = abs(denominator);
    }
    else
    {
      numerator = abs(numerator);
      denominator = abs(denominator);
    }

    numerator_ = numerator;
    denominator_ = denominator;
  }

  int Numerator() const
  {
    return numerator_;
  }

  int Denominator() const
  {
    return denominator_;
  }

private:
  bool IsPositive(const int &numerator, const int &denominator)
  {
    return numerator > 0 && denominator > 0 || numerator < 0 && denominator < 0;
  }

  int numerator_;
  int denominator_;
};

bool operator==(const Rational &left, const Rational &right)
{
  return left.Numerator() == right.Numerator() && left.Denominator() == right.Denominator();
}

bool operator<(const Rational &left, const Rational &right)
{
  int leftNumerator = left.Numerator() * right.Denominator();
  int rightNumerator = right.Numerator() * left.Denominator();;
  return leftNumerator < rightNumerator;
}

Rational operator+(const Rational &left, const Rational &right)
{
  int numerator = (left.Numerator() * right.Denominator()) + (right.Numerator() * left.Denominator());
  int denominator = left.Denominator() * right.Denominator();
  return Rational(numerator, denominator);
}

Rational operator-(const Rational &left, const Rational &right)
{
  Rational invertRight(-(right.Numerator()), right.Denominator());

  int numerator = (left.Numerator() * invertRight.Denominator()) + (invertRight.Numerator() * left.Denominator());
  int denominator = left.Denominator() * invertRight.Denominator();
  return Rational(numerator, denominator);
}

Rational operator*(const Rational &left, const Rational &right)
{
  int numerator = left.Numerator() * right.Numerator();
  int denominator = left.Denominator() * right.Denominator();
  return Rational(numerator, denominator);
}

Rational operator/(const Rational &left, const Rational &right)
{
  Rational invertRight(right.Denominator(), right.Numerator());
  int numerator = left.Numerator() * invertRight.Numerator();
  int denominator = left.Denominator() * invertRight.Denominator();
  return Rational(numerator, denominator);
}

istream &operator>>(istream &stream, Rational &destination)
{
  int numerator, denominator;
  char delimiter;
  stream >> numerator >> delimiter >> denominator;
  if (stream && delimiter == '/')
  {
    destination = Rational(numerator, denominator);
  }
  return stream;
}

ostream &operator<<(ostream &stream, const Rational &source)
{
  stream << source.Numerator();
  stream << '/';
  stream << source.Denominator();

  return stream;
}

int main()
{
  {
    const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
    if (rs.size() != 3)
    {
      cout << "Wrong amount of items in the set" << endl;
      return 1;
    }

    vector<Rational> v;
    for (auto x : rs)
    {
      v.push_back(x);
    }
    if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}})
    {
      cout << "Rationals comparison works incorrectly" << endl;
      return 2;
    }
  }

  {
    map<Rational, int> count;
    ++count[{1, 2}];
    ++count[{1, 2}];

    ++count[{2, 3}];

    if (count.size() != 2)
    {
      cout << "Wrong amount of items in the map" << endl;
      return 3;
    }
  }

  cout << "OK" << endl;
  return 0;
}
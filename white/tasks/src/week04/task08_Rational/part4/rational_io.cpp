#include <iostream>
#include <sstream>
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
    ostringstream output;
    output << Rational(-6, 8);
    if (output.str() != "-3/4")
    {
      cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
      return 1;
    }
  }

  {
    istringstream input("5/7");
    Rational r;
    input >> r;
    bool equal = r == Rational(5, 7);
    if (!equal)
    {
      cout << "5/7 is incorrectly read as " << r << endl;
      return 2;
    }
  }

  {
    istringstream input("5/7 10/8");
    Rational r1, r2;
    input >> r1 >> r2;
    bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
    if (!correct)
    {
      cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
      return 3;
    }

    input >> r1;
    input >> r2;
    correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
    if (!correct)
    {
      cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
      return 4;
    }
  }

  cout << "OK" << endl;
  return 0;
}

#include <iostream>
#include <exception>
using namespace std;

int CalculateGCD(int numerator, int denominator)
{
  if (denominator == 0)
  {
    throw invalid_argument("0 is not a valid denominator");
  }

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
    if (denominator == 0)
    {
      throw invalid_argument("0 is not a valid denominator");
    }

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
  int rightNumerator = right.Numerator() * left.Denominator();
  ;
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
  if (right.Numerator() == 0)
  {
    throw domain_error("");
  }
  return left * Rational(right.Denominator(), right.Numerator());
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
  try
  {
    Rational r(1, 0);
    cout << "Doesn't throw in case of zero denominator" << endl;
    return 1;
  }
  catch (invalid_argument &)
  {
  }

  try
  {
    auto x = Rational(1, 2) / Rational(0, 1);
    cout << "Doesn't throw in case of division by zero" << endl;
    return 2;
  }
  catch (domain_error &)
  {
  }

  cout << "OK" << endl;
  return 0;
}

#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <exception>

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
    if (denominator == 0)
    {
      throw invalid_argument("Invalid argument");
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

Rational operator+(const Rational &left, const Rational &right)
{
  return {left.Numerator() * right.Denominator() + right.Numerator() * left.Denominator(),
          left.Denominator() * right.Denominator()};
}

Rational operator-(const Rational &left, const Rational &right)
{
  return {left.Numerator() * right.Denominator() - right.Numerator() * left.Denominator(),
          left.Denominator() * right.Denominator()};
}

Rational operator*(const Rational &left, const Rational &right)
{
  return {left.Numerator() * right.Numerator(),
          left.Denominator() * right.Denominator()};
}

Rational operator/(const Rational &left, const Rational &right)
{
  if (right.Numerator() == 0)
  {
    throw domain_error("Division by zero");
  }

  return left * Rational(right.Denominator(), right.Numerator());
}

bool operator==(const Rational &left, const Rational &right)
{
  return left.Numerator() == right.Numerator() && left.Denominator() == right.Denominator();
}

bool operator<(const Rational &left, const Rational &right)
{
  return (left - right).Numerator() < 0;
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
    char operation;
    Rational left;
    Rational right;

    cin >> left >> operation >> right;

    if (operation == '+')
    {
      cout << left + right;
    }
    else if (operation == '-')
    {
      cout << left - right;
    }
    else if (operation == '*')
    {
      cout << left * right;
    }
    else if (operation == '/')
    {
      cout << left / right;
    }
  }
  catch (const invalid_argument &e)
  {
    cout << e.what();
  }
  catch (const domain_error &e)
  {
    cout << e.what();
  }

  return 0;
}
#include <iostream>
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

int main()
{
  {
    Rational a(2, 3);
    Rational b(4, 3);
    Rational c = a * b;
    bool equal = c == Rational(8, 9);
    if (!equal)
    {
      cout << "2/3 * 4/3 != 8/9" << endl;
      return 1;
    }
  }

  {
    Rational a(5, 4);
    Rational b(15, 8);
    Rational c = a / b;
    bool equal = c == Rational(2, 3);
    if (!equal)
    {
      cout << "5/4 / 15/8 != 2/3" << endl;
      return 2;
    }
  }

  cout << "OK" << endl;
  return 0;
}

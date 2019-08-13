#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class FunctionPart
{
public:
  FunctionPart(char operation, double value)
  {
    operation_ = operation;
    value_ = value;
  }

  double Apply(double value) const
  {
    if (operation_ == '+')
    {
      return value + value_;
    }
    return value - value_;
  }

  void Invert()
  {
    if (operation_ == '+')
    {
      operation_ = '-';
    }
    else
    {
      operation_ = '+';
    }
  }

private:
  char operation_;
  double value_;
};

class Function
{
public:
  void AddPart(char operation, double value)
  {
    parts_.push_back({operation, value});
  }

  double Apply(double value) const
  {
    for (const auto &operation : parts_)
    {
      value = operation.Apply(value);
    }

    return value;
  }

  void Invert()
  {
    for (auto &operation : parts_)
    {
      operation.Invert();
    }

    reverse(begin(parts_), end(parts_));
  }

private:
  vector<FunctionPart> parts_;
};
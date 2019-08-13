#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Image
{
  double quality;
  double freshness;
  double rating;
};

struct Params
{
  double a;
  double b;
  double c;
};

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

Function MakeWeightFunction(const Params &params,
                            const Image &image)
{
  Function function;
  function.AddPart('-', image.freshness * params.a + params.b);
  function.AddPart('+', image.rating * params.c);
  return function;
}

double ComputeImageWeight(const Params &params, const Image &image)
{
  Function function = MakeWeightFunction(params, image);
  return function.Apply(image.quality);
}

double ComputeQualityByWeight(const Params &params,
                              const Image &image,
                              double weight)
{
  Function function = MakeWeightFunction(params, image);
  function.Invert();
  return function.Apply(weight);
}

int main()
{
  Image image = {10, 2, 6};
  Params params = {4, 2, 6};
  cout << ComputeImageWeight(params, image) << endl;
  cout << ComputeQualityByWeight(params, image, 46) << endl;
  return 0;
}
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <exception>

using namespace std;

// Реализуйте здесь
// * класс Matrix
// * оператор ввода для класса Matrix из потока istream
// * оператор вывода класса Matrix в поток ostream
// * оператор проверки на равенство двух объектов класса Matrix
// * оператор сложения двух объектов класса Matrix

class Matrix
{
public:
  Matrix()
  {
    rows_ = 0;
    columns_ = 0;
  }

  Matrix(int num_rows, int num_cols)
  {
    ThrowIfNegative(num_rows, num_cols);

    rows_ = num_rows;
    columns_ = num_cols;

    vector<int> cols(num_cols);
    values_ = vector<vector<int>>(num_rows, cols);
  }

  void Reset(int num_rows, int num_cols)
  {
    ThrowIfNegative(num_rows, num_cols);
    ThrowIfOutOfRange(num_rows, num_cols);

    rows_ = num_rows;
    columns_ = num_cols;
  }

  int At(int num_rows, int num_cols) const
  {
    ThrowIfNegative(num_rows, num_cols);
    ThrowIfOutOfRange(num_rows, num_cols);

    return values_[num_rows][num_cols];
  }

  int &At(int num_rows, int num_cols)
  {
    ThrowIfNegative(num_rows, num_cols);
    ThrowIfOutOfRange(num_rows, num_cols);

    return values_[num_rows][num_cols];
  }

  int GetNumRows() const
  {
    return rows_;
  }

  int GetNumColumns() const
  {
    return columns_;
  }

  bool IsEmpty() const
  {
    return rows_ == 0 && columns_ == 0;
  }

private:
  void ThrowIfNegative(int num_rows, int num_cols) const
  {
    if (num_rows < 0 || num_cols < 0)
    {
      throw out_of_range("Index out of range");
    }
  }

  void ThrowIfOutOfRange(int num_rows, int num_cols) const
  {
    if (num_rows > rows_ || num_cols > columns_)
    {
      throw out_of_range("Index out of range");
    }
  }

  int rows_;
  int columns_;
  vector<vector<int>> values_;
};

istream &operator>>(istream &stream, Matrix &matrix)
{
  int rows, cols;

  stream >> rows >> cols;

  matrix = Matrix(rows, cols);
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      stream >> matrix.At(i, j);
    }
  }

  return stream;
}

ostream &operator<<(ostream &stream, const Matrix &matrix)
{
  int rows = matrix.GetNumRows();
  int cols = matrix.GetNumColumns();

  stream << rows << ' ' << cols;

  for (int i = 0; i < rows; i++)
  {
    cout << endl;
    for (int j = 0; j < cols; j++)
    {
      stream << matrix.At(i, j) << ' ';
    }
  }

  return stream;
}

Matrix operator+(const Matrix &left, const Matrix &right)
{
  bool is_size_equal = left.GetNumRows() == right.GetNumRows() && left.GetNumColumns() == right.GetNumColumns();
  if (!is_size_equal)
  {
    throw invalid_argument("Matrix size is different");
  }

  int rows = left.GetNumRows();
  int cols = left.GetNumColumns();

  Matrix result(rows, cols);

  if (result.IsEmpty())
  {
    return result;
  }

  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      result.At(i, j) = left.At(i, j) + right.At(i, j);
    }
  }

  return result;
}
bool operator==(const Matrix &left, const Matrix &right)
{
  bool is_size_equal = left.GetNumRows() == right.GetNumRows() && left.GetNumColumns() == right.GetNumColumns();
  if (!is_size_equal)
  {
    return false;
  }

  if (left.IsEmpty() && right.IsEmpty())
  {
    return true;
  }

  int rows = left.GetNumRows();
  int cols = left.GetNumColumns();
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      if (left.At(i, j) != right.At(i, j))
      {
        return false;
      }
    }
  }

  return true;
}

int main()
{
  try
  {
    Matrix one;
    Matrix two;

    // cin >> one >> two;

    // cout << endl;
    // cout << one
    //      << endl
    //      << endl;
    // cout << two << endl;

    // cout << endl;
    // cout << (one + two) << endl;

    // cin >> one >> two;
    // cout << (one == two ? "True" : "False") << endl;

    cin >> one;
    cout << one;

    return 0;
  }
  catch (const exception &e)
  {
    cout << e.what() << endl;
  }
}

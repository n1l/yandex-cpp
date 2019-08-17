#include <iostream>
#include <exception>
#include <string>
using namespace std;

string AskTimeServer()
{
  return "10:11:12";
  //throw invalid_argument("");
  //throw system_error(error_code());
}

class TimeServer
{
public:
  string GetCurrentTime()
  {
    try
    {
      LastFetchedTime = AskTimeServer();
      return LastFetchedTime;
    }
    catch (const system_error &e)
    {
      return LastFetchedTime;
    }
  }

private:
  string LastFetchedTime = "00:00:00";
};

int main()
{
  // Меняя реализацию функции AskTimeServer, убедитесь, что это код работает корректно
  TimeServer ts;
  try
  {
    cout << ts.GetCurrentTime() << endl;
  }
  catch (exception &e)
  {
    cout << "Exception got: " << e.what() << endl;
  }
  return 0;
}

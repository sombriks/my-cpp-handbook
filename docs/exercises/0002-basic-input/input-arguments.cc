#include <iostream>

int main(int argc, char **argv)
{
  using namespace std;

  if (argc < 2)
  {
    cout << "usage: " << endl
         << argv[0] << " <your name>" << endl;
    return 1;
  }
  cout << "Hello, " << argv[1] << endl;
  return 0;
}
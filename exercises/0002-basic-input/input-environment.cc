#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char **argv)
{
  if (char *name = getenv("USER"))
  {
    cout << "Hello, " << name << endl;
  }
  else
  {
    cerr << "Variable $USER not set!" << endl;
    return 1;
  }
  return 0;
}
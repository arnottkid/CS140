#include <iostream>
using namespace std;

/* An example of making a mistake testing for the
   end of file.  This is because cin.eof() tells 
   you if your last reading command failed because
   you are at the end of file.  It does not tell
   you whether you are at the end of the file now,
   and your next reading command will fail because
   of that. */

int main()
{
  string s;
  int i;

  i = 0;
  while (!cin.eof()) {
    i++;
    cin >> s;
    cout << "String " << i << " is " << s << endl;
  }
  return 0;
}

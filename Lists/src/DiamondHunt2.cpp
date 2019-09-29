/* This is an implementation of DiamondHunt which uses a list rather than a string.
   It improves the performance drastically, because it is not making those big
   substrings, and it does not perform all of those find operations.  Please read
   the lecture notes for an explanation of the iterators. */

#include <iostream>
#include <list>
#include <string>
using namespace std;

class DiamondHunt {
  public:
    int countDiamonds(string mine);
};

int DiamondHunt::countDiamonds(string mine)
{
  int num_diamonds;
  size_t i;
  list <char> l;
  list <char>::const_iterator left, right, newleft;

  /* Create the list from the string. */

  for (i = 0; i < mine.size(); i++) l.push_back(mine[i]);
  
  num_diamonds = 0;
  left = l.begin();
  while (left != l.end()) {
    if (*left == '>') {
      left++;             // If left is not the beginning of a diamond, move on.
    } else {
      right = left;
      right++;
      if (right == l.end()) return num_diamonds;

      if (*right == '<') {   // If right is not the end of a diamond, move on
        left++;
      } else {            // Otherwise, we've found a diamond.  We need to increment
        num_diamonds++;   // num_diamonds, and set newleft to point to the previous
                          // char, or if left is at the beginning, to the next one.

        if (left == l.begin()) {
          newleft = right;
          newleft++;
        } else {
          newleft = left;
          newleft--;
        }

        l.erase(left);      // Now erase left and right, and set left to newleft.
        l.erase(right);
        left = newleft;
      }
    }
  }
  return num_diamonds;
}

int main()
{
  DiamondHunt d;
  string s;

  while (cin >> s) {
    cout << d.countDiamonds(s) << endl;
  }
  return 0;
}


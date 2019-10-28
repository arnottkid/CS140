#include <string>
#include <deque>

class Towers {
  public:
    Towers(int n);                                  // Constructor - n is the number of disks
    std::string Move(int from, int to, bool print); // Move the disk from tower "from" to tower "to"
                                                    // Returns "" if the move was successful.
                                                    // Otherwise, it returns an error string.
    void Print() const;                             // Print the towers as ASCII art.

  protected:
    std::deque <int> T[3];                // This holds the sizes of the disks on the three towers
};

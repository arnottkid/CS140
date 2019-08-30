#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
using namespace std;

main(int argc, char **argv)
{
  istringstream ss;
  int i, j, n, w;
  string alphabet;

  srand48(time(0));

  if (argc != 3) { cerr << "usage: genlines width nlines\n"; exit(1); }
  ss.str(argv[1]);
  if (!(ss >> n)) { cerr << "usage: genlines width nlines\n"; exit(1); }

  ss.clear();
  ss.str(argv[2]);
  if (!(ss >> w)) { cerr << "usage: genlines width nlines\n"; exit(1); }

  for (i = 'A'; i <= 'Z'; i++) alphabet.push_back(i);
  for (i = 'a'; i <= 'z'; i++) alphabet.push_back(i);

  for (i = 0; i < n; i++) {
    for (j = 0; j < w; j++) printf("%c", alphabet[lrand48()%alphabet.size()]);
    printf("\n");
  }
}

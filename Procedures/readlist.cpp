#include <cstdlib>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

main()
{
  vector <string> songs;
  vector <string> timings;
  string line, s, songname;
  int i;

  while(getline(cin, line)) {
    i = line.find("  ");
    if (i == string::npos) { cerr << "Bad line -- " << line << endl; exit(1); }
    songs.push_back(line.substr(0, i));
    while (line[i] == ' ') i++;
    timings.push_back(line.substr(i));
  }
  for (i = 0; i < songs.size(); i++) {
    printf("Song: %-40s -- Timing %5s\n", songs[i].c_str(), timings[i].c_str());
  }
}

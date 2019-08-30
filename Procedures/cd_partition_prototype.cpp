#include <cstdlib>
#include <cstdio>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

int timing_seconds(string s);

main()
{
  vector <string> songs;
  vector <string> timings;
  string line;
  int i, ttime, cd_number;

  while(getline(cin, line)) {
    i = line.find("  ");
    if (i == string::npos) { cerr << "Bad line -- " << line << endl; exit(1); }
    songs.push_back(line.substr(0, i));
    while (line[i] == ' ') i++;
    timings.push_back(line.substr(i));
  }
 
  cd_number = 0;
  ttime = 0;
  printf("CD %d\n\n", cd_number);
  for (i = 0; i < songs.size(); i++) {
    ttime += timing_seconds(timings[i]);
    if (ttime > 80*60) {
      cd_number++;
      printf("\nCD %d\n\n", cd_number);
      ttime = timing_seconds(timings[i]);
    }
    printf("Song: %-50s   Timing %5s -- Total: %2d:%02d\n", 
           songs[i].c_str(), timings[i].c_str(), 
           ttime/60, ttime%60);
  }
}

int timing_seconds(string s)
{
  int colon;
  istringstream ss;
  int min, sec;

  colon = s.find(':');
  if (colon == string::npos) return -1;
  s[colon] = ' ';
  ss.str(s);
  if (!(ss >> min >> sec)) return -1;
  return sec + min*60;
}


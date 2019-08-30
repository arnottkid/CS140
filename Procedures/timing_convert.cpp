#include <cstdlib>
#include <cstdio>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

main()
{
  vector <string> songs;
  vector <string> timings;
  string line;
  int i, sec, min, colon;
  istringstream ss;

  while(getline(cin, line)) {
    i = line.find("  ");
    if (i == string::npos) { cerr << "Bad line -- " << line << endl; exit(1); }
    songs.push_back(line.substr(0, i));
    while (line[i] == ' ') i++;
    timings.push_back(line.substr(i));
  }
  for (i = 0; i < songs.size(); i++) {
    colon = timings[i].find(':');
    timings[i][colon] = ' ';
    ss.clear();
    ss.str(timings[i]);
    ss >> min >> sec;
    sec += (min * 60); 
    timings[i][colon] = ':';
    
    printf("Song: %-40s -- Timing %5s -- %5d\n", songs[i].c_str(), timings[i].c_str(), sec);
  }
}

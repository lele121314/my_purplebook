#ifndef COMMON_H
#define COMMON_H

#include <map>
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

#define CHECK_OR_HELP(exp) {if(!(exp)){cerr << HELP_MSG << endl;exit(1);}}

map<string,const char*> parseArgs(int argc, char* argv[]);

#endif // COMMON_H
#include "common.h"

map<string,const char*> parseArgs(int argc, char* argv[])
{
    map<string,const char*> args;

    for(int pos=1;pos<argc;)
    {
        if(argv[pos][0] == '-' && pos+1<argc)
        {
            if(argv[pos][1] == '-') {
                args[argv[pos]+2]=argv[pos+1];
            } else {
                args[argv[pos]+1]=argv[pos+1];
            }
            pos += 2;
        } else {
            if(argv[pos][0] == '-')args[argv[pos]+1]=NULL;
            else args[argv[pos]]=NULL;
            pos ++;
        }
    }

    return args;
}
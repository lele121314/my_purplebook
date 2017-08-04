#include "../../../testlib/testlib.h"
#include "common.h"

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

#define HELP_MSG "USAGE: ./random -n n -m m -k k -h h [--seed seed]"

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    map<string, const char*> args = parseArgs(argc, argv);
    CHECK_OR_HELP(args.find("n") != args.end())
    CHECK_OR_HELP(args.find("m") != args.end())
    CHECK_OR_HELP(args.find("k") != args.end())
    CHECK_OR_HELP(args.find("h") != args.end())

    const int N = atoi(args["n"]);
    const int M = atoi(args["m"]);
    const int K = atoi(args["k"]);
    const int H = atoi(args["h"]);

    cout << N << " " << M << " " << K << endl;
    for(int i=1;i<=N;i++)
    {
        cout << rnd.next(1,H);
        if(i<N) cout << " ";
    }
    cout << endl;

    return 0;
}
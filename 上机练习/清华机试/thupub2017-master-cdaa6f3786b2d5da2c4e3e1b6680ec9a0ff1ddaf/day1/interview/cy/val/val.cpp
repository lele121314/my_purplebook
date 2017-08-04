#include "../../../../testlib/testlib.h"
#include "common.h"

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;

#define HELP_MSG "USAGE: ./val.exe -nmin -nmax -mmin -mmax -kmin -kmax -hmin -hmax"

int main(int argc, char* argv[])
{
    registerValidation(argc, argv);
    map<string, const char*> args = parseArgs(argc, argv);
    CHECK_OR_HELP(args.find("nmin") != args.end())
    CHECK_OR_HELP(args.find("nmax") != args.end())
    CHECK_OR_HELP(args.find("mmin") != args.end())
    CHECK_OR_HELP(args.find("mmax") != args.end())
    CHECK_OR_HELP(args.find("kmin") != args.end())
    CHECK_OR_HELP(args.find("kmax") != args.end())
    CHECK_OR_HELP(args.find("hmin") != args.end())
    CHECK_OR_HELP(args.find("hmax") != args.end())

    const int nmin = atoi(args["nmin"]);
    const int nmax = atoi(args["nmax"]);
    const int mmin = atoi(args["mmin"]);
    const int mmax = atoi(args["mmax"]);
    const int kmin = atoi(args["kmin"]);
    const int kmax = atoi(args["kmax"]);
    const int hmin = atoi(args["hmin"]);
    const int hmax = atoi(args["hmax"]);

    int n = inf.readInt(1, 100000);inf.readSpace();
    ensure(nmin <= n && n <= nmax);
    int m = inf.readInt(1, n);inf.readSpace();
    ensure(mmin <= m && m <= mmax);
    int k = inf.readInt(0, 100000);inf.readEoln();
    ensure(kmin <= k && k <= kmax);

    for(int i=1;i<=n;i++)
    {
        int h = inf.readInt(1, 100000);
        ensure(hmin <= h && h <= hmax);
        if(i<n)inf.readSpace();
    }
    inf.readEoln();
    inf.readEof();

    return 0;
}
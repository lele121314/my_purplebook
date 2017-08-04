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

    int *height = new int[N+10];
    int l=rnd.next(1, H-K), r=l+K;
    for(int i=1;i<=M;i++)
    {
        height[i] = (l == r) ? l : rnd.next(l, r);
    }
    for(int i=M+1;i<=N;i++)
    {
        height[i]=rnd.next(1, H);
    }
    for(int i=1;i<=N*10;i++)
    {
        int a=rnd.next(1, N);
        int b=rnd.next(1, N);
        swap(height[a], height[b]);
    }

    cout << N << " " << M << " " << K << endl;
    for(int i=1;i<=N;i++)
    {
        cout << height[i];
        if(i<N) cout << " ";
    }
    cout << endl;

    delete height;

    return 0;
}
#include "../../../../testlib/testlib.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>

#include "common.h"

using namespace std;

#define HELP_MSG "USAGE: ./val.exe -n N -m M -q Q -t type"

int main(int argc, char* argv[])
{
    registerValidation(argc, argv);
    map<string, const char*> args = parseArgs(argc, argv);
    CHECK_OR_HELP(args.find("n") != args.end())
    CHECK_OR_HELP(args.find("m") != args.end())
    CHECK_OR_HELP(args.find("q") != args.end())
    CHECK_OR_HELP(args.find("t") != args.end())

    const int N = atoi(args["n"]);
    const int M = atoi(args["m"]);
    const int Q = atoi(args["q"]);
    const char type = args["t"][0];

    int n = inf.readInt(1, 1000); inf.readSpace();
    ensure(1 <= n && n <= N);
    int m = inf.readInt(1, 1000); inf.readEoln();
    ensure(1 <= m && m <= M);

    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= m; j ++)
        {
            char c = inf.readChar();
            ensure(c == '.' || c == '*');
        }
        inf.readEoln();
    }

    int quit_num = 0;
    int lines = 0;
    while(!inf.eof())
    {
        lines ++;
        // string cmd = inf.readString("(Flag)|(Sweep)|(DSweep)|(Quit)");
        string cmd = "";
        char buf[10];buf[1]='\0';
        while(!isspace(buf[0]=inf.readChar()))cmd+=buf;
        inf.unreadChar(buf[0]);
        ensure(cmd == "Flag" || cmd == "Sweep" || cmd == "DSweep" || cmd == "Quit");
        if (type == 'A') {
            ensure(cmd == "Sweep" || cmd == "Quit");
        } else if (type == 'B') {
            ensure(cmd != "DSweep");
        }
        if (cmd != "Quit") {
            inf.readSpace();
            int x = inf.readInt(1, n);
            inf.readSpace();
            int y = inf.readInt(1, m);
        } else quit_num ++;
        inf.readEoln();
    }
    ensure(quit_num == 1);
    ensure(lines <= Q);
    inf.readEof();

    return 0;
}
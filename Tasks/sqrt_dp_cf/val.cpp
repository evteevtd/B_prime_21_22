// #include "/home/tikhon/Downloads/testlib-master/testlib.h"
#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int N = 30000;

int main(int argc, char** argv){
    registerValidation(argc, argv);

    int n = inf.readInt(1, N, "n");
    inf.readSpace();
    int d = inf.readInt(1, N, "d");
    inf.readEoln();

    vector<int> p;
    for (int i = 0; i < n; i++) {
        p.push_back(inf.readInt(d, N, "p_i"));
        inf.readEoln();
    }
    ensuref(std::is_sorted(p.begin(), p.end()), "p is not sorted");
    inf.readEof();
    return 0;
}

#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;
#define ll long long
#define pii pair<int, int>
#define ld long double
#define all(a) (a).begin(), (a).end()


int n, m;
const int N = 102;
set<int> g[N];


int main(int argc, char* argv[]) {
    // This command initializes checker environment.
    registerTestlibCmd(argc, argv);
    // Now there are three global variables specifying testlib streams:
    // inf - stream with the testdata.
    // ouf - stream with the contestant output.
    // ans - stream with the jury answer.
    // All those streams provide the similar interface for reading data.

    n = inf.readInt();
    m = inf.readInt();
    for (int i = 0; i < m; i++) {
    	int a, b;
    	a = inf.readInt();
    	b = inf.readInt();
    	g[a].insert(b);
    	g[b].insert(a);
    }

    string jans = ans.readString();
    string pans = ouf.readString();
    if (jans != pans) {
    	quitf(_wa, "YES/NO answer is wrong");
    }
    if (jans == "NO") {
    	quitf(_ok, "Correct NO answer");
    }

    int l = ouf.readInt(1, n);
    if (l == 1) {
    	quitf(_wa, "Cycle size is 1");
    }
    if (l % 2 == 0) {
    	quitf(_wa, "Cycle size is even");
    }
    vector<int> v(l);
    for (int i = 0; i < l; i++) {
    	v[i] = ouf.readInt(1, n);
    }
    vector<int> used(n + 1);
    for (int i = 0; i < l; i++) {
    	used[v[i]]++;
    	if (used[v[i]] == 2) {
    		quitf(_wa, "Given sequence contains equal numbers");
    	} 
    	if (g[v[i]].count(v[(i + 1) % l])) {

    	} else {
    		quitf(_wa, "Given sequence is not a cycle");
    	}
    }

    quitf(_ok, "Correct YES ansver and correct cycle"); // This finishes checker with verdit OK.
}

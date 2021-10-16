// #include "/home/tikhon/Downloads/testlib-master/testlib.h"
#include "testlib.h"
// #include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define pii pair<int, int>

map<string, string> params;

int n;
int c;


int main(int argc, char* argv[]){
	registerGen(argc, argv, 1);

	for (int i = 1; i < argc; i++) {
		string s = string(argv[i]);
		if (s.find("=") != string::npos) {
			auto pos = s.find("=");
			params[s.substr(0, pos)] = s.substr(pos + 1);
		}
	}

	n = stoi(params["n"]);
	c = 1e5;
	if (params.count("c")) c = stoi(params["c"]);

	vector<pii> v(n);
	for (int i = 0; i < n; i++) {
		v[i] = {rnd.next(0, c), rnd.next(0, c)};
	}
	v[rnd.next(0, n - 1)].first = 0;
	v[rnd.next(0, n - 1)].first = c;
	v[rnd.next(0, n - 1)].second = 0;
	v[rnd.next(0, n - 1)].second = c;

	for (auto p : v) {
		cout << p.first << ' ' << p.second << '\n';
	}

    return 0;
}

// #include "/home/tikhon/Downloads/testlib-master/testlib.h"
#include "testlib.h"
// #include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define pii pair<int, int>

map<string, string> params;

int n;

string s1;

int mn_len = 1;
int mx_len = 100;

string gen(int len, bool how) {
	string s = "";
	if (how == 0) {
		for (int i = 0; i < len; i++) s += '0' + rnd.next(0, 9);
	} else {
		s = s1;
		for (int i = 0; i < len - mn_len; i++) {
			s += '0' + rnd.next(0, 9);
		}
	}

	return s;
}


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
	if (params.count("mn_len")) mn_len = stoi(params["mn_len"]);
	if (params.count("mx_len")) mx_len = stoi(params["mx_len"]);

	s1 = gen(mn_len, 0);

	// cout << "s1 = " << s1 << '\n';

	vector<string> v(n);
	for (int i = 0; i < n; i++) {
		v[i] = gen(rnd.next(mn_len, mx_len), rnd.next(0, 2));
	}
	v[rnd.next(0, n - 1)][0] = '0' + rnd.next(1, 9);

	for (auto i : v) {
		cout << i << '\n';
	}

    return 0;
}

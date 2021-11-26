// #include "/home/tikhon/Downloads/testlib-master/testlib.h"
#include "testlib.h"
// #include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define pii pair<int, int>

map<string, string> params;

int n;
bool answer;

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
	answer = rnd.next(0, 1);
	if (params.count("ans")) answer = stoi(params["ans"]);

	vector<char> s(n);
	vector<char> t(n);

	for (int i = 0; i < n; i++) {
		s[i] = 'a' + rnd.next(0, 25);
	}
	t = s;
	shuffle(t.begin(), t.end());

	if (answer == 0) {
		for (int i = 0; i < 5; i++) {
			t[rnd.next(0, n - 1)] = 'a' + rnd.next(0, 25);
		}
	}

	for (auto i : s) cout << i;
	cout << '\n';
	for (auto i : t) cout << i;
	cout << '\n';

    return 0;
}

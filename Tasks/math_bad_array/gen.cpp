#include "/home/tikhon/Downloads/testlib-master/testlib.h"
// #include "testlib.h"
// #include <iostream>
#include <bits/stdc++.h>


using namespace std;
#define pii pair<int, int>
#define ll long long

vector<int> gen(int n, int max_a, string mode) {
	vector<int> a(n);

	if (mode == "rand") {
		for (int i = 0; i < n; i++) {
			a[i] = rnd.next(1, max_a);
		}
	}
	if (mode == "every") {
		for (int i = 0; i < n; i++) {
			a[i] = i % max_a + 1;
		}
	}
	if (mode == "start2") {
		int s = round(sqrt(max_a));
		if (s == 0) s = 1;
		for (int i = 0; i < n; i++) {
			a[i] = s * rnd.next(1, max_a / s);
		}
	}
	if (mode == "pw2") {
		int pw2 = 0;
		while ((1 << pw2) <= max_a) pw2++;
		pw2--;
		for (int i = 0; i < n; i++) {
			a[i] = (1 << rnd.next(0, pw2));
		}
	}
	if (mode == "every+pw") {
		for (int i = 0; i < min(n, max_a); i++) {
			a[i] = i + 1;
		}
		int pw2 = 0;
		while ((1 << pw2) <= max_a) pw2++;
		pw2 -= 3;
		for (int i = min(n, max_a); i < n; i++) {
			a[i] = (rnd.next(0, 1000) ? (1 << rnd.next(0, pw2)) : (1 << pw2) * 3);
		}
	}

	return a;
}



map<string, string> params;

int t = 10;

int m_n = -1;
int n = 200000;
int max_a = 200000;
string mode = "rand";

int main(int argc, char* argv[]){
	registerGen(argc, argv, 1);

	for (int i = 1; i < argc; i++) {
		string s = string(argv[i]);
		if (s.find("=") != string::npos) {
			auto pos = s.find("=");
			params[s.substr(0, pos)] = s.substr(pos + 1);
		}
	}

	if (params.count("m_n")) m_n = (ll)stold(params["m_n"]);
	if (params.count("n")) n = (ll)stold(params["n"]);

	if (params.count("t")) t = (ll)stold(params["t"]);
	if (params.count("max_a")) max_a = (ll)stold(params["max_a"]);
	if (params.count("mode")) mode = params["mode"];

	cout << t << '\n';

	for (int i = 0; i < t; i++) {
		if (m_n != -1) n = rnd.next(1, m_n);
		vector<int> a = gen(n, max_a, mode);
		cout << n << '\n';
		for (int i = 0; i < n; i++) {
			assert(0 < a[i] && a[i] <= max_a);
			cout << a[i] << (i == n - 1 ? "" : " ");
		}
		cout << '\n';
	}

    return 0;
}

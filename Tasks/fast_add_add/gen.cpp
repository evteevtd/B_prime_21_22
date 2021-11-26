// #include "/home/tikhon/Downloads/testlib-master/testlib.h"
#include "testlib.h"
// #include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define pii pair<int, int>

map<string, string> params;
vector<string> mods = {"rand", "long"};


int n, m, k;
int c;

string mode;

vector<int> gen_3(int r1) {
	if (r1 == 0) {
		int l = rnd.next(1, n);
		int r = rnd.next(1, n);
		if (l > r) swap(l, r);
		return {l, r, rnd.next(0, c)};
	} else {
		int l = rnd.next(1, (n / 4) + 1);
		int r = rnd.next(n / 4 * 3 + 1, n);
		if (l > r) swap(l, r);
		return {l, r, rnd.next(c / 7 * 6, c)};
	}
}
pii gen_2(int r1) {
	if (r1 == 0) {
		int l = rnd.next(1, m);
		int r = rnd.next(1, m);
		if (l > r) swap(l, r);
		return {l, r};
	} else {
		int l = rnd.next(1, (m / 4) + 1);
		int r = rnd.next(m / 4 * 3 + 1, n);
		if (l > r) swap(l, r);
		return {l, r};
	}
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
	if (params.count("m")) {
		m = stoi(params["m"]);
	} else {
		m = n;
	}
	if (params.count("k")) {
		k = stoi(params["k"]);
	} else {
		k = n;
	}
	if (params.count("c")) {
		c = stoi(params["c"]);
	} else {
		c = 1e5;
	}



	mode = "any";
	if (params.count("mode")) mode = params["mode"];
	if (mode == "any") mode = rnd.any(mods);

	vector<int> a(n);
	vector<vector<int>> add(m);
	vector<pii> q(k);

	if (mode == "rand") {
		for (int i = 0; i < n; i++) a[i] = rnd.next(0, c);
		for (int i = 0; i < m; i++) add[i] = gen_3(0);
		for (int i = 0; i < k; i++) q[i] = gen_2(0);
	} else {
		for (int i = 0; i < n; i++) a[i] = rnd.next(0, c);
		for (int i = 0; i < m; i++) add[i] = gen_3(1);
		for (int i = 0; i < k; i++) q[i] = gen_2(1);
		a[rnd.next(0, n - 1)] = c;
		add[rnd.next(0, m - 1)][0] = 1;
		add[rnd.next(0, m - 1)][1] = n;
		add[rnd.next(0, m - 1)][2] = c;
		q[rnd.next(0, k - 1)].first = 1;
		q[rnd.next(0, k - 1)].second = m;
	}

	cout << n << ' ' << m << ' ' << k << '\n';
	cout << a[0];
	for (int i = 1; i < n; i++) cout << ' ' << a[i];
	cout << '\n';
	for (auto i : add) cout << i[0] << ' ' << i[1] << ' ' << i[2] << '\n';
	for (auto i : q) cout << i.first << ' ' << i.second << '\n';

    return 0;
}

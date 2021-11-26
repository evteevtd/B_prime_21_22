#include "/home/tikhon/Downloads/testlib-master/testlib.h"
// #include "testlib.h"
// #include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define all(a) (a).begin(), (a).end()
map<string, string> params;


vector<string> mods = {"rand", "no_one", "exact", "2_way", "slow_down", "speed_up"/* , "l_k_in_row" */ /*, "dif_intr"*/};

string mode = "any";

int n, d;

vector<int> gen_path(int mn, int mx) {
	int sum = d;
	vector<int> lnh = {d};
	while (1) {
		int d1 = lnh.back();
		if (d1 == 1) {
			d1 = d1 + rnd.next(0, 1);	
		} else {
			d1 = d1 + rnd.next(mn, mx);
		}
		if (sum + d1 > 30000) break;
		sum += d1;
		lnh.push_back(d1);
	}
	for (int i = 1; i < lnh.size(); i++) {
		lnh[i] += lnh[i - 1];
	}
	return lnh;
}

vector<int> gen() {
	vector<int> v(n);
	if (mode == "rand") {
		for (int i = 0; i < n; i++) {
			v[i] = rnd.next(d, 30000);
		}
	}
	if (mode == "no_one") {
		int k = 30000 / (d - 1);
		for (int i = 0; i < n; i++) {
			if (k == 1) {
				v[i] = rnd.next(d, 30000);
			} else {
				v[i] = rnd.next(2, k) * (d - 1);
			}
		}
	}
	if (mode == "exact") {
		auto way = gen_path(-1, 1);
		for (int i = 0; i < n; i++) {
			v[i] = way[i % way.size()];
		}
	}
	if (mode == "2_way") {
		auto way1 = gen_path(-1, 1);
		auto way2 = gen_path(-1, 1);
		for (int i = 0; i < n; i++) {
			int p = rnd.next(0, int(way1.size() + way2.size()) - 1);
			if (p < way1.size()) {
				v[i] = way1[p];
			} else {
				p -= way1.size();
				v[i] = way2[p];
			}
		}
	}
	if (mode == "slow_down") {
		auto way = gen_path(-1, -1);
		for (int i = 0; i < n; i++) {
			v[i] = way[rnd.next(0, int(way.size()) - 1)];
		}
	}
	if (mode == "speed_up") {
		auto way = gen_path(1, 1);
		for (int i = 0; i < n; i++) {
			v[i] = way[rnd.next(0, int(way.size()) - 1)];
		}
	}


	sort(all(v));
	return v;
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
	d = stoi(params["d"]);

	if (params.count("mode")) {
		mode = params["mode"];
	}
	if (mode == "any") {
		mode = rnd.any(mods);
	}

	cout << n << ' ' << d << '\n';
	vector<int> v = gen();
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}

    return 0;
}

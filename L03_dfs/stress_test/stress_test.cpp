#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define ld long double
#define all(a) (a).begin(), (a).end()

int smart(vector<int> v) {
	int n = v.size();
	int s = 0;
	for (int i = 0; i < n; i++) {
		s += v[i] + (v[i] == 0);
	}
	return s;
}

int stupid(vector<int> v) {
	int n = v.size();
	int s = 0;
	for (int i = 0; i < n; i++) {
		s += v[i];
	}
	return s;
}

vector<int> gen(int n, int C) {
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		v[i] = rand() % C;
	}
	return v;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int t = 0; t < 1e6; t++) {
		srand(t);
		vector<int> v = gen(10, 100);
		int out = smart(v);
		int ans = stupid(v);
		if (out == ans) {
			cout << "OK " << t << endl;
		} else {
			cout << "WA " << t << '\n';
			cout << "test :\n";
			for (auto i : v) {
				cout << i << ' ';
			}
			cout << '\n';
			cout << "out = " << out << '\n';
			cout << "ans = " << ans << '\n';
			return 0;
		}
	}

	return 0;
}
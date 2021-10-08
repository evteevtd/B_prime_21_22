#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define ld long double
#define all(a) (a).begin(), (a).end()

// подробная документация ко всем std структурам есть на сайте cppreference.com


void out(vector<int> v, string name) {
	cout << name << " = ";
	for (int i : v) {
		cout << i << ' ';
	}
	cout << '\n';
}

const vector<int> a = {1, 3, 5, 7, 9};



signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<int> b = a;
	out(b, "b");
	for (int i = 0; i < 5; i++) {
		next_permutation(all(b));
		out(b, "next_b");
	}

	cout << '\n';

	auto c = a;
	out(c, "c");
	rotate(c.begin(), c.begin() + 2, c.end());
	out(c, "rotate_c_2");
	rotate(c.begin(), c.begin() + 4, c.end());
	out(c, "rotate_c_4");

	cout << '\n';

	auto d = a;
	out(d, "d");
	d.insert(d.begin() + 2, 6);
	out(d, "ins_6_2");
	d = a;
	out(d, "d");
	d.insert(upper_bound(all(d), 4), 4);
	out(d, "ins 4");

	cout << '\n';

	vector<int> e = {0, 1, 4, 5, 8};
	out(a, "a");
	out(e, "e");
	vector<int> m(a.size() + e.size());
	merge(all(a), all(e), m.begin());
	out(m, "a + e");

	cout << '\n';

	vector<int> s = {1, 4, 2, 3, 4, 2, 3, 2, 2, 3, 3, 2, 6, 2, 1};
	out(s, "s");
	random_shuffle(all(s));
	out(s, "shaffle");
	sort(all(s));
	out(s, "sort");
	unique(all(s));
	out(s, "unique");

	sort(all(s));
	out(s, "sort");
	s.resize(unique(all(s)) - s.begin());
	out(s, "unique2");

	cout << '\n';

	auto f = a;
	out(f, "f");
	reverse(all(f));
	out(f, "rev_f");










	




	return 0;
}
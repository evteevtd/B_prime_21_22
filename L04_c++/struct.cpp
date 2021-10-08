#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define ld long double
#define all(a) (a).begin(), (a).end()

// подробная документация ко всем std структурам есть на сайте cppreference.com


struct test_struct {
	int a;
	vector<int> v;

	test_struct() {}
	test_struct(int a_, int b_, int c_) {
		a = a_;
		v = {b_, c_};
	}
	void out() {
		cout << "(" << a << ' ' << v[0] << ' ' << v[1] << ") ";
	}
};

bool operator<(const test_struct &a, const test_struct &b) {
	// if (a.a == b.a) {
	// 	return a.v[0] < b.v[0];
	// }
	// return a < b;
	return tie(a.a, a.v[0]) < tie(b.a, b.v[0]);
}

// bool cmp(const test_struct &a, const test_struct &b) {
// 	return tie(a.a, a.v[0], a.v[1]) < tie(b.a, b.v[0], b.v[1]);
// }

// #include <type_traits>
// using Cmp = std::integral_constant<decltype(&cmp), &cmp>;


signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int M = 13;

	vector<test_struct> v;
	for (int i = 0; i < M; i++) {
		v.push_back(test_struct(i / 3, i / 2, i));
	}

	for (int i = 0; i < M; i++) {
		v[i].out();
	}
	cout << '\n';

	// set<test_struct> s;
	// for (int i = 0; i < M; i++) {
	// 	s.insert(v[i]);
	// }

	// for (auto x : s) {
	// 	x.out();
	// }
	// cout << '\n';

	// auto it = upper_bound(s.begin(), s.end(), test_struct(2, 2, 8));
	// // s.upper_bound(test_struct(2, 2, 8));
	// auto x = (*it);
	// x.out();
	// it--;
	// x = *it;
	// x.out();
	// cout << '\n';


	// map<test_struct, int> m;
	// for (int i = 0; i < M; i++) {
	// 	m[v[i]] += i;
	// }

	// for (auto p : m) {
	// 	auto x = p.first;
	// 	x.out();
	// 	cout << p.second << '\n';
	// }


	// priority_queue<test_struct> q;
	// for (int i = 0; i < M; i++) {
	// 	q.push(v[i]);
	// }
	// while (!q.empty()) {
	// 	auto x = q.top();
	// 	q.pop();
	// 	x.out();
	// }
	// cout << '\n';

	// set<test_struct> s;
	// for (int i = 0; i < M; i++) {
	// 	s.insert(v[i]);
	// }
	// while (!s.empty()) {
	// 	auto it = (s.end());
	// 	it--;
	// 	auto x = *it;
	// 	s.erase(x);
	// 	x.out();
	// }
	// cout << '\n';








	return 0;
}

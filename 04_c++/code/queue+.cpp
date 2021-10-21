#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define ld long double
#define all(a) (a).begin(), (a).end()

// подробная документация ко всем std структурам есть на сайте cppreference.com


signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cout << "queue:\n";
	queue<int> q;
	for (int i = 0; i < 5; i++) {
		q.push(i);
	}
	for (int i = 0; i < 5; i++) {
		cout << q.front() << ' ';
		q.pop();
	}
	cout << '\n';

	cout << "list:\n";
	list l = {1, 2, 3, 4};
	l.push_back(5);
	l.push_front(0);
	for (auto x : l) {
		cout << x << ' ';
	}
	cout << '\n';
	for (auto it = l.begin(); it != l.end(); it++) {
		cout << *it << ' ';
	}
	cout << '\n';

	auto it = find(all(l), 3);
	l.insert(it, 10);
	l.insert(it, 11);
	it--;
	l.insert(it, 12);

	for (auto x : l) {
		cout << x << ' ';
	}
	cout << '\n';


	cout << "deque:\n";
	deque<int> d;
	for (int i = 0; i < 6; i++) {
		d.push_back(i);
	}
	for (int i = 0; i < 4; i++) {
		d.push_front(i);
	}
	for (int i = 0; i < d.size(); i++) {
		cout << d[i] << ' ';
	}
	cout << '\n';






	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define ld long double
#define all(a) (a).begin(), (a).end()
#define stack st

struct min_queue {
	queue<int> q;
	deque<int> d;
	min_queue() {}

	void push(int x) {
		q.push(x);
		while (!d.empty() && d.back() > x) d.pop_back();
		d.push_back(x);
	}
	void pop() {
		if (d.front() == q.front()) d.pop_front();
		q.pop();
	}
	int get() {
		return d.front();
	}
};


signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	min_queue q;
	q.push(5);
	q.push(7);
	q.push(6);
	cout << q.get() << '\n';
	q.pop();
	cout << q.get() << '\n';
	q.push(4);
	cout << q.get() << '\n';


	return 0;
}
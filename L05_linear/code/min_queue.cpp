#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define ld long double
#define all(a) (a).begin(), (a).end()
#define stack st

struct node	{
	int val;
	int p_min;
	node() {}
	node(int val_, int p_min_) {
		val = val_;
		p_min = p_min_;
	}
};

struct min_queue {
	vector<node> left;
	vector<node> right;
	min_queue() {}

	void push(vector<node> & v, int x) {
		if (v.empty()) {
			v.push_back(node(x, x));		
		} else {
			v.push_back(node(x, min(v.back().p_min, x)));
		}
	}

	void push(int x) {
		push(right, x);
	}
	void pop() {
		if (left.empty()) {
			while (!right.empty()) {
				push(left, right.back().val);
				right.pop_back();
			}
		}
		if (!left.empty()) left.pop_back();
	}
	int get() {
		int ans = 1e9 + 7;
		if (!left.empty()) ans = min(ans, left.back().p_min);
		if (!right.empty()) ans = min(ans, right.back().p_min);
		return ans;
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
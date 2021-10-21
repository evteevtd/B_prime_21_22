#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define ld long double
#define all(a) (a).begin(), (a).end()
#define stack st

struct node {
	int key;
	node* parent;
	node() {
		parent = nullptr;
	}
	node(int key_) {
		key = key_;
		parent = nullptr;
	}
};

struct stack {
	node* root;
	stack() {
		root = nullptr;
	}
	void push(int key) {
		node* n1 = new node(key);
		(*n1).parent = root;
		root = n1;
	}
	void pop() {
		if (root == nullptr) return;
		node* n1 = (*root).parent;
		delete(root);
		root = n1;
	}

	int top() {
		if (root == nullptr) return -1;
		return (*root).key;
	}
};


signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	stack s;
	s.push(5);
	s.push(6);
	cout << s.top() << '\n';
	s.pop();
	cout << s.top() << '\n';

	return 0;
}
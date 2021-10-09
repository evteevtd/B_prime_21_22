#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define ld long double
#define all(a) (a).begin(), (a).end()

int f(vector<int> &v) {
	for (int j = 0; j < 6 /*7*/; j++) {
		v.push_back(0);
	}
	int ans = 0;
	for (auto i : v) {
		ans += i;
	}
	return ans;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<int> a;
	for (int i = 0; i < 10; i++) {
		a.push_back(i);
	}
	cout << "a = ";
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << ' ';
	}
	cout << '\n';

	int* x = &a[0];
	*x = f(a);

	cout << "*x = " << *x << '\n';
	cout << "a[0] = " << a[0] << '\n';

	return 0;
}
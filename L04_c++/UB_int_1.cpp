#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define ld long double
#define all(a) (a).begin(), (a).end()


bool f(int x) {
	return (x + 1) > (x);
}

bool g(int x, int y) {
	return (x > y);
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int x = INT_MAX;
	cout << "x = " << x << '\n';
	cout << "x + 1 = " << x + 1 << '\n';
	cout << "f(x) = " << ' ' << f(x) << '\n';
	cout << "g(x) = " << ' ' << g(x + 1, x) << '\n';

	return 0;
}
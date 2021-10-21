#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define ld long double
#define all(a) (a).begin(), (a).end()

string gen(int n) {
	string s;
	for (int i = 0; i < n; i++) {
		s += ('a' + rand() % 3);
	}
	return s;
}


signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 100; i++) {
		cout << gen(4) << '\n';
	}


	return 0;
}
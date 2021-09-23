#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define ld long double
#define all(a) (a).begin(), (a).end()

vector<int> v;

void quick_sort(int l, int r) {
	if (l + 1 >= r) return;
	int rnd = rand() % (r - l) + l;
	int m = v[rnd];
	int l1 = l;
	int r1 = r - 1;
	while (l1 < r1) {
		while (v[l1] < m) l1++;
		while (v[r1] > m) r1--;
		swap(v[l1], v[r1]);
		l1++, r1--;
	}
	quick_sort(l, r1);
	quick_sort(l1, r);
}


signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int k = 0; k < 10000; k++) {
		int n = 10000;
		v.resize(n);
		for (int i = 0; i < n; i++) {
			v.push_back(rand() % 200);
		}
		quick_sort(0, n);
		for (int i = 1; i < n; i++) {
			if (v[i - 1] > v[i]) {
				cout << "helpppp!\n";
				for (auto j : v) {
					cout << j << ' ';
				}
				cout << '\n';
				return 0;
			}
		}
		cout << "OK " << k << endl;
	}


	return 0;
}
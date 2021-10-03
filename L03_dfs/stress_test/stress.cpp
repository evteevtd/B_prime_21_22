#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define ld long double
#define all(a) (a).begin(), (a).end()
// #define int long long

// корень кубического уравнения
int a, b, c, d;
// abs(a, b, c, d) <= 1000; a != 0;
// a * x^3 + b * x^2 + c * x + d;
// x1  : f(x1) = 0;
ld xeps = 1e-6;

ld f(ld x, int a, int b, int c, int d) {
	return a * x * x * x + b * x * x + c * x + d;
	// a * pow(x, 3);
	// pow(ld, ld);
}

ld solve(int a, int b, int c, int d) {
	ld l = -100;
	ld r = 100;

	for (int i = 0; i < 10; i++) {
		ld m = (l + r) / 2;
		if (f(m, a, b, c, d) < 0) {
			l = m;
		} else {
			r = m;
		}
	}
	return l;
}

// // 
// ld stupid(int a, int b, int c, int d) {
// 	return  ...;
// }


int rnd(int MN, int MX) {
	return MN + rand() % (MX - MN);
}
// RAND_MAX;

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int MN = -1000;
	int MX = 1000;

	for (int t = 0; t < 1e8; t++) {
		// gen test;
		int a = rnd(MN, MX);
		if (a == 0) a = 1;
		int b = rnd(MN, MX);
		int c = rnd(MN, MX);
		int d = rnd(MN, MX);

		ld x = solve(a, b, c, d);

		// ld ans = f(x, a, b, c, d);

		ld ansl = f(x - xeps, a, b, c, d);
		ld ansr = f(x + xeps, a, b, c, d);
		ld ans = f(x, a, b, c, d);

		if (ansl * ansr <= 0 || ans < 1e-15) {
			cout << "OK " << t << endl;
		} else {
			cout << "WA " << t << '\n';
			cout << "test = " << a << ' ' << b << ' ' << c << ' ' << d << '\n';
			cout << "x = " << x << '\n';
			cout << "f(x) = " << ans << '\n';
			return 0;
		}
	}

	return 0;
}

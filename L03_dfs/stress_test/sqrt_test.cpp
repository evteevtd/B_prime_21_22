#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define ld long double
#define all(a) (a).begin(), (a).end()

// abs(a, b, c, d) <= 1000; a != 0;

ld f(int a, int b, int c, int d, ld x) {
	return a * x * x * x + b * x * x + c * x + d;
}

ld solve(int a, int b, int c, int d) {
	if (a < 0) {
		a *= -1;
		b *= -1;
		c *= -1;
		d *= -1;
	}
	ld l = -1000;
	ld r = 1000;
	for (int i = 0; i < 100; i++) {
		ld m = (l + r) / 2;
		if (f(a, b, c, d, m) < 0) {
			l = m;
		} else {
			r = m;
		}
	}
	return l;
}

int rnd(int MN, int MX) {
	return MN + rand() % (MX - MN + 1);
}

int sign(ld x) {
	if (x < 0) return -1;
	return (x > 0);
}


signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int MN = -1000;
	int MX = 1000;

	ld xeps = 1e-6;
	ld anseps = 1e-12;

	int a, b, c, d;

	for (int t = 0; t < 1e8; t++) {
		srand(t);
		a = rnd(MN, MX);
		if (a == 0) a = 1;
		b = rnd(MN, MX);
		c = rnd(MN, MX);
		d = rnd(MN, MX);
		ld x = solve(a, b, c, d);
		if (sign(f(a, b, c, d, x - xeps)) != sign(f(a, b, c, d, x + xeps)) || (abs(f(x, a, b, c, d)) < anseps)) {
			cout << "OK " << t << endl;
		} else {
			cout << "WA " << t << '\n';
			cout << "test = " << a << ' ' << b << ' ' << c << ' ' << d << '\n';
			cout << "ans = " << x << '\n';
			cout << "f(ans) = " << f(a, b, c, d, x) << '\n';
			return 0;
		}
	}

	return 0;
}
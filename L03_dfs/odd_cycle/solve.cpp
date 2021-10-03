#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define ld long double
#define all(a) (a).begin(), (a).end()

const int N = 102;
vector<int> g[N];
int color[N];
int n, m;

vector<int> v;
vector<int> ans;

int dfs(int u, int c) {
	if (color[u]) {
		if (c == color[u]) return 0;
		return u;
	}
	color[u] = c;
	v.push_back(u);
	for (auto i : g[u]) {
		int d = dfs(i, 3 - c);
		if (d == 0) continue;
		if (d == -1) return -1;
		ans.push_back(u);
		if (d == u) return -1;
		return d;
	}
	v.pop_back();
	return 0;
}

void solve() {
	for (int i = 1; i <= n; i++) {
		if (!color[i]) {
			dfs(i, 1);
			if (!ans.empty()) {
				cout << "NO" << '\n';//YES\n";
				// cout << ans.size() << '\n';
				// for (auto j : ans) {
				// 	cout << j << ' ';
				// }
				// cout << '\n';
				return;
			}
		}
	}
	cout << "YES\n";//NO\n";
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	solve();
	return 0;
}
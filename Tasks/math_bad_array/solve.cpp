#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define ld long double
#define all(a) (a).begin(), (a).end()
 
const int A = 2e5 + 1;
 
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> cnt(A);
		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			cnt[a]++;
		}
		vector<int> dp = cnt; // какой максимальной длины последовательность может оканчиваться в этом числе
		for (int i = 1; i < A; i++) {
			if (dp[i] == 0) continue;
			for (int mul = 2; mul * i < A; mul++) {
				dp[i * mul] = max(dp[i * mul], dp[i] + cnt[i * mul]);
			}
		}
		int ans = 0;
		for (int i = 0; i < A; i++) {
			ans = max(ans, dp[i]);
		}

		cout << n - ans << '\n';
	}
 
	return 0;
}
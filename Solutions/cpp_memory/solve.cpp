#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define ld long double
#define all(a) (a).begin(), (a).end()
#define int long long

set<pii> fr; // свободная память в формате {длина, позиция начала}
map<int, int> len; // сколько свободно, начиная я с этой свободной

void add_seg(int pos1, int len1) {
	fr.insert({len1, pos1});
	len[pos1] = len1;
}
void erase_seg(int pos1, int len1) {
	fr.erase({len1, pos1});
	len.erase(pos1);
}

int add(int sz) {
	auto it = fr.lower_bound((pii){sz, -1});
	if (it == fr.end()) {
		return -1;
	} else {
		pii p = *it;
		int ans = p.second;
		int len1 = p.first - sz;
		erase_seg(p.second, p.first);
		if (len1 != 0) {
			add_seg(p.second + sz, len1);
		}
		return ans;
	}
}


void erase(int pos, int len1) {
	if (pos == -1) return;

	int mstart = pos;
	int mfin = pos + len1;

	auto it_next = len.lower_bound(pos);

	if (it_next != len.begin()) {
		auto it_prev = it_next;
		--it_prev;
		pii pl = *it_prev;
		if (pl.first + pl.second == mstart) {
			erase_seg(pl.first, pl.second);
			mstart = pl.first;
		}
	}

	if (it_next != len.end()) {
		pii pr = *it_next;
		if (mfin == pr.first) {
			erase_seg(pr.first, pr.second);
			mfin = mfin + pr.second;
		}
	}
	
	add_seg(mstart, mfin - mstart);
}


signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	add_seg(1, n);

	vector<int> pos(m + 1);
	vector<int> q(m + 1);
	for (int i = 1; i <= m; i++) {
		cin >> q[i];
		assert(q[i] != 0);
		if (q[i] > 0) {
			pos[i] = add(q[i]);
			cout << pos[i] << '\n';
		} else {
			erase(pos[-q[i]], q[-q[i]]);
		}
	}

	return 0;
}
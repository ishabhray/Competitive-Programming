#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265358979323
#define ll long long int
#define vi vector <int>
#define vl vector <ll>
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000007

const ll mod = 1e9 + 7;

ll power(ll a, ll b) { //a^b
	ll res = 1;
	a = a % MOD;
	while (b > 0) {
		if (b & 1) {res = (res * a) % MOD; b--;}
		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}

ll gcd(ll a, ll b) {return (b == 0) ? a : gcd(b, a % b);}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin >> t;
	while (t--) {
		ll n, m;
		cin >> n >> m;
		vector < pair<pair<ll, char>, ll>> v(n);
		for (auto &i : v)
			cin >> i.ff.ff;
		for (auto &i : v)
			cin >> i.ff.ss;
		for (ll i = 0; i < n; i++)
			v[i].ss = i;
		sort(all(v));
		reverse(all(v));
		stack <ll> od;
		stack <ll> ed;
		vl ans(n, -1);
		vl o;
		vl e;
		for (ll i = 0; i < n; i++) {
			if (v[i].ff.ss == 'U') {
				if (i % 2) {
					if (od.empty())
						o.pb(i);
					else {
						ll x = od.top();
						od.pop();
						ll time = v[x].ff.ff - v[i].ff.ff;
						time /= 2;
						ans[v[x].ss] = time;
						ans[v[i].ss] = time;
					}
				}
				else {
					if (ed.empty())
						e.pb(i);
					else {
						ll x = ed.top();
						ed.pop();
						ll time = v[x].ff.ff - v[i].ff.ff;
						time /= 2;
						ans[v[x].ss] = time;
						ans[v[i].ss] = time;
					}
				}
			}
			else {
				if (i % 2)
					od.push(i);
				else
					ed.push(i);
			}
		}
		ll q = o.size();
		for (ll i = 0; i + 1 < q; i += 2) {
			ll time = m - v[o[i]].ff.ff;
			ll coord = v[o[i + 1]].ff.ff + time;
			time = time + (m - coord) / 2;
			ans[v[o[i]].ss] = time;
			ans[v[o[i + 1]].ss] = time;
		}
		q = e.size();
		for (ll i = 0; i + 1 < q; i += 2) {
			ll time = m - v[e[i]].ff.ff;
			ll coord = v[e[i + 1]].ff.ff + time;
			time = time + (m - coord) / 2;
			ans[v[e[i]].ss] = time;
			ans[v[e[i + 1]].ss] = time;
		}
		while ((ll)od.size() >= 2) {
			ll x = od.top();
			od.pop();
			ll y = od.top();
			od.pop();
			ll time = v[x].ff.ff;
			ll coord = v[y].ff.ff - time;
			time = time + coord / 2;
			ans[v[x].ss] = time;
			ans[v[y].ss] = time;
		}
		while ((ll)ed.size() >= 2) {
			ll x = ed.top();
			ed.pop();
			ll y = ed.top();
			ed.pop();
			ll time = v[x].ff.ff;
			ll coord = v[y].ff.ff - time;
			time = time + coord / 2;
			ans[v[x].ss] = time;
			ans[v[y].ss] = time;
		}
		if ((ll)od.size() && (ll)o.size() % 2 == 1) {
			q = o.size();
			ll x = o[q - 1];
			ll y = od.top();
			ll time1 = m - v[x].ff.ff;
			ll time2 = v[y].ff.ff;
			ll time;
			ll c1, c2;
			if (time1 >= time2) {
				time = time1;
				c1 = m;
				c2 = time1 - time2;
			}
			else {
				time = time2;
				c1 = m - (time2 - time1);
				c2 = 0;
			}
			ans[v[x].ss] = time + (c1 - c2) / 2;
			ans[v[y].ss] = time + (c1 - c2) / 2;
		}
		if ((ll)ed.size() && (ll)e.size() % 2 == 1) {
			q = e.size();
			ll x = e[q - 1];
			ll y = ed.top();
			ll time1 = m - v[x].ff.ff;
			ll time2 = v[y].ff.ff;
			ll time;
			ll c1, c2;
			if (time1 >= time2) {
				time = time1;
				c1 = m;
				c2 = time1 - time2;
			}
			else {
				time = time2;
				c1 = m - (time2 - time1);
				c2 = 0;
			}
			ans[v[x].ss] = time + (c1 - c2) / 2;
			ans[v[y].ss] = time + (c1 - c2) / 2;
		}

		for (ll i = 0; i < n; i++)
			cout << ans[i] << " ";
		cout << "\n";
	}
}
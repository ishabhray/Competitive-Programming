#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define vv vector
#define all(v) (v).begin(), (v).end()
#define MOD 1000000007
ll power(ll a, ll b)
{ //a^b
    ll res = 1;
    a = a % MOD;
    while (b > 0)
    {
        if (b & 1)
        {
            res = (res * a) % MOD;
            b--;
        }
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}
ll fermat_inv(ll y) { return power(y, MOD - 2ll); }
int n;
vi t(4000005);
vi s[1000005];
vi dp(1000005), finv(1000005);
void build(int a[], int v, int tl, int tr)
{
    if (tl == tr)
        t[v] = a[tl - 1];
    else
    {
        int tm = (tl + tr) / 2;
        build(a, v * 2, tl, tm);
        build(a, v * 2 + 1, tm + 1, tr);
        t[v] = min(t[v * 2], t[v * 2 + 1]);
    }
}
int sum(int v, int tl, int tr, int l, int r)
{
    if (l > r)
        return 1e8;
    if (l == tl && r == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    return min(sum(2 * v, tl, tm, l, min(r, tm)), sum(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}
ll ans = 1;
void solve(int l, int r)
{
    if (l >= r)
        return;
    int mn = sum(1, 1, n, l, r);
    auto it = lower_bound(all(s[mn]), l);
    auto it1 = upper_bound(all(s[mn]), r);
    int cnt = it1 - it;
    (ans *= dp[cnt]) %= MOD;
    int st=it-s[mn].begin(),e=it1-s[mn].begin();
    solve(l, s[mn][st]-1);
    for (int i = st; i < e-1; i++)
    {
        solve(s[mn][i]+1, s[mn][i+1]-1);
    }
    solve(s[mn][e-1]+ 1, r);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    dp[0]= finv[0] = 1;
    cin >> n;
    int a[n];
    for (int i = 1; i <= 1e6; i++)
        finv[i] = fermat_inv(i);
    for (ll i = 1; i <= n; i++)
    {
        dp[i] = (ll)dp[i - 1] * 2 * i % MOD;
        dp[i] = (ll)dp[i] * (2 * i - 1) % MOD;
        dp[i] = (ll)dp[i] * finv[i + 1] % MOD;
        dp[i] = (ll)dp[i] * finv[i] % MOD;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        s[a[i]].pb(i + 1);
    }
    build(a, 1, 1, n);
    solve(1, n);
    cout << ans << '\n';
}
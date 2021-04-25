#include <bits/stdc++.h>
using namespace std;

#define PI 3.141592653589
#define ll long long int
#define ld long double
#define vi vector<int>
#define vl vector<ll>
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pll pair<ll,ll>
#define vv vector
#define all(v) (v).begin(),(v).end()
int MOD = 1e9 + 7;
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
ll fermat_inv(ll y) {return power(y, MOD - 2);}
ll gcd(ll a, ll b) {return (b == 0) ? a : gcd(b, a % b);}
ll min(ll a, ll b) {return (a > b) ? b : a;}
ll max(ll a, ll b) {return (a > b) ? a : b;}
bool prime[1000001];
vi primes;
void SieveOfEratosthenes(int n)
{
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (int p = 2; p < 1000001; p++)
        if (prime[p])
            primes.pb(p);
}
ll fact[100010];
ll finv[100010];
void factorial(int n) {
    fact[0] = 1;
    finv[0] = 1;
    for (int i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * i, fact[i] %= MOD, finv[i] = fermat_inv(fact[i]);
}
ll ncr(ll n, ll r)
{
    if (n < r)
        return 0;
    else {
        ll x = finv[r] * finv[n - r] % MOD;
        return fact[n] * x % MOD;
    }
}

int solve1(int ar, int as, int ap, int br, int bs, int bp)
{
    int x = ar;
    int ans = 0;
    int t = min(ap, bs);
    ap -= t, bs -= t;
    if (ap) {
        t = min(ap, bp);
        ap -= t, bp -= t;
        if (ap) {
            ans = ap;
            br -= ap;
        }
        else if (bp) {
            t = min(ar, bp);
            ar -= t, bp -= t;
            t = min(ar, br);
            ar -= t;
            br -= t;
            ans += bp;
        }
    }
    else {
        t = min(bs, as);
        as -= t;
        bs -= t;
        ans += bs;
        ar -= bs;
        if (as) {
            t = min(as, br);
            as -= t;
            br -= t;
            ans += as;
        }
    }
    return ans;
}
int solve2(int ar, int as, int ap, int br, int bs, int bp)
{
    int ans = 0;
    int t = min(ar, bs);
    ar -= t, bs -= t;
    ans += t;
    t = min(as, bp);
    as -= t, bp -= t;
    ans += t;
    t = min(ap, br);
    ap -= t, br -= t;
    ans += t;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int te = 1;
    //cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(100005);
    while (te--) {
        int n;
        cin >> n;
        int ar, as, ap, br, bs, bp;
        cin >> ar >> as >> ap;
        cin >> br >> bs >> bp;
        int a1, a2;
        a1 = solve2(ar, as, ap, br, bs, bp);
        a2 = solve1(ar, as, ap, br, bs, bp);
        a2 = min(a2, solve1(ap, ar, as, bp, br, bs));
        a2 = min(a2, solve1(as, ap, ar, bs, bp, br));
        cout << a2 << " " << a1 << "\n";
    }
}
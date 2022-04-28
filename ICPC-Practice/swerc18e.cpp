#include <bits/stdc++.h>
using namespace std;

#define PI 3.141592653589
#define ll long long int
#define ld long double
#define vi vector<int>
#define vl vector<ll>
#define ii pair<int, int>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pll pair<ll, ll>
#define vv vector
#define all(v) (v).begin(), (v).end()
#define MAXN 300005
int MOD = 1e9 + 7;
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
ll fermat_inv(ll y) { return power(y, MOD - 2); }
ll gcd(ll a, ll b) { return (b == 0) ? a : gcd(b, a % b); }
ll min(ll a, ll b) { return (a > b) ? b : a; }
ll max(ll a, ll b) { return (a > b) ? a : b; }
bool prime[1000001];
vi primes;
void SieveOfEratosthenes(int n)
{
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = 0;
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
ll fact[1000010];
ll finv[1000010];
void factorial(int n)
{
    fact[0] = 1;
    finv[0] = 1;
    for (int i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * i, fact[i] %= MOD, finv[i] = fermat_inv(fact[i]);
}
ll ncr(ll n, ll r)
{
    if (n < r)
        return 0;
    else
    {
        ll x = finv[r] * finv[n - r] % MOD;
        return fact[n] * x % MOD;
    }
}
int main()
{

    int te = 1;
    // cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while (te--)
    {
        int n;
        cin >> n;
        string s[n];
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> s[i] >> a[i];
        int sum = 0, cnt100 = 0, cnt0 = 0;
        for (int i : a)
        {
            sum += i;
            if (i == 100)
                cnt100++;
            if (i == 0)
                cnt0++;
        }
        int x[n], y[n];
        bool f = true;
        sum -= 100;
        sum *= 100;
        for (int i = 0; i < n; i++)
        {
            int mn = -50, mx = 49;
            if(a[i]==100) cnt100--,mx=0;
            if(a[i]==0) cnt0--,mn=0;
            for (; mn < 50; mn++)
            {
                if (sum + mn <= 0)
                {
                    if ((n - 1 -cnt100) * 49 + sum + mn >= 0)
                        break;
                }
                else
                {
                    if (sum + mn - (n - 1-cnt0) * 50 <= 0)
                        break;
                }
            }
            if (mn == 50)
            {
                f=false;
                break;
            }
            for (; mx >= -50; mx--)
            {
                if (sum + mx <= 0)
                {
                    if ((n - 1-cnt100) * 49 + sum + mx >= 0)
                        break;
                }
                else
                {
                    if (sum + mx - (n - 1-cnt0) * 50 <= 0)
                        break;
                }
            }
            if (mx == -51)
            {
                f=false;
                break;
            }
            x[i]=mn,y[i]=mx;
            if(a[i]==100) cnt100++;
            if(a[i]==0) cnt0++;
        }
        if (!f)
        {
            cout << "IMPOSSIBLE\n";
            continue;
        }
        for (int i = 0; i < n; i++)
        {
            cout << s[i] << ' ';
            float z = a[i] * 100 + x[i];
            z /= 100;
            printf("%0.2f ", z);
            z = a[i] * 100 + y[i];
            z /= 100;
            printf("%0.2f\n", z);
        }
    }
}

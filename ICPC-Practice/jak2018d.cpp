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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int te = 1;
    //cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while (te--)
    {
        int n, m;
        cin >> n >> m;
        char a[n][m];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> a[i][j];

        int ans = 0;
        if (n == 1 && m == 1)
            ans = 0;
        else if (n == 1)
        {
            for (int i = 1; i < m - 1; i++)
                if (a[0][i] == '.')
                    ans++;
        }
        else if (m == 1)
        {
            for (int i = 1; i < n - 1; i++)
                if (a[i][0] == '.')
                    ans++;
        }
        else
        {
            if (n == 2 && m == 2)
                ans = 0;
            else if (n == 2)
            {
                for (int i = 1; i < m - 1; i++)
                {
                    if (a[0][i] == '.' && a[1][i] == '.')
                        ans++;
                }
            }
            else if (m == 2)
            {
                for (int i = 1; i < n - 1; i++)
                {
                    if (a[i][0] == '.' && a[i][1] == '.')
                        ans++;
                }
            }
            else
            {
                bool b = true;
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < m; j++)
                    {
                        if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
                        {
                            if (i == 0 && j == 0 || i == 0 && j == m - 1 || i == n - 1 && j == 0 || i == n - 1 && j == m - 1)
                                continue;
                            if (a[i][j] == '#')
                                b = false;
                        }
                        else if (a[i][j] == '.')
                            ans++;
                    }
                }
                if (b)
                    ans++;
            }
        }
        cout << ans << '\n';
    }
}
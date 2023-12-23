#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define int long long int
#define f(a, b, c, d) for(int a = b; a < c; a += d)
#define pb push_back
#define pq priority_queue
#define all(x) x.begin(), x.end()
#define MOD 1000000007

typedef tree<int, null_type, less<int>, rb_tree_tag, // or less_equal
        tree_order_statistics_node_update> ordered_set;

void solve()
{
    int n, m;
    cin >> n >> m;
    int a[n], b[m], inita = 0;
    f(i,0,n,1)
    {
        cin >> a[i];
        inita ^= a[i];
    }
    int ball = 0;
    f(i,0,m,1)
    {
        cin >> b[i];
        ball |= b[i];
    }
    if(n % 2)
    {
        int mx = 0;
        f(i,0,n,1)
        {
            a[i] |= ball;
            mx ^= a[i];
        }
        cout << inita << " " << mx << "\n";
    }
    else
    {
        int mn = 0;
        f(i,0,n,1)
        {
            a[i] |= ball;
            mn ^= a[i];
        }
        cout << mn << " " << inita << "\n";
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    f(i, 1, t + 1, 1)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}
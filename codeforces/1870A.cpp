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
    int n, k, x;
    cin >> n >> k >> x;
    if(x == k)
        x--;
        int sum = 0;
    if(n < k || x<k-1)
    {
        cout << "-1\n";
        return;
    }    
    f(i,0,k,1)
    {
        // cout << i << " ";
        sum += i;
    }
    f(i,0,n-k,1)
    {
        // cout << x << " ";
        sum += x;
    }
    cout << sum <<"\n";
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
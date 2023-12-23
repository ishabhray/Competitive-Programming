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

int mex[5001][5001];
void solve()
{
    int n;
    cin >> n ;
    int a[n];
    f(i,0,n,1)
    {
        cin >> a[i];
    }

    f(i,0,n,1)
    {
        int mx=0;
        set<int>s;
        f(j,i,n,1){
            s.insert(a[j]);
            while(s.find(mx)!=s.end())
                mx++;
            mex[i][j]=mx;
        }
    }

    f(i,0,n,1)
    {
        f(j,i,n,1)
        {
            cout << mex[i][j] << " ";
        }
        cout << "\n";
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
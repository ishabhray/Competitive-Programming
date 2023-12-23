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
    int n, k;
    cin >> n >> k;
    int a[n];
    set<int>s;
    vector<int>adj[k+1];
    int mn=n,mx=0;
    f(i,0,n,1)
    {
        cin >> a[i];
        s.insert(a[i]);
        adj[a[i]].pb(i);
    }
    int ans[k+1]={0};
    for(int i=k;i>=1;i--)
    {
        if(s.find(i)==s.end()){
            continue;
        }
        for(auto i:adj[i])
        {
            mn=min(mn,i);
            mx=max(mx,i);
        }
        ans[i]=(mx-mn+1)*2;
    }
    f(i,1,k+1,1)
        cout << ans[i] << " ";
    cout<<'\n';
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
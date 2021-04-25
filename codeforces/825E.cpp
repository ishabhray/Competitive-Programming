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
#define MAXN 300005

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int te=1;
    //cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        int n,m;
        cin>>n>>m;
        int ans[n+1];
        vi adj[n+1];
        map<int,int>deg;
        set<int,greater<int>>z;
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            adj[v].pb(u);
            deg[u]++;
        }
        for(int i=1;i<=n;i++){
            if(!deg[i])
                z.insert(i);
        }
        for(int i=n;i>=1;i--){
            int x=*z.begin();
            z.erase(z.begin());
            ans[x]=i;
            for(int j:adj[x]){
                deg[j]--;
                if(!deg[j])
                    z.insert(j);
            }
        }
        for(int i=1;i<=n;i++)
            cout<<ans[i]<<' ';
    }
}
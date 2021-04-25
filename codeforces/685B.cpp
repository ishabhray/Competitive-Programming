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
int MOD=1e9+7;

ll min(ll a,ll b){return (a>b)?b:a;}
ll max(ll a,ll b){return (a>b)?a:b;}

int n,subtree[300005],cen[300005],par[300005],mxstsz[300005];
vi adj[300005];

void dfs(int a,int p){
    int sz=1;
    for(int i:adj[a]){
        if(i==p)
            continue;
        dfs(i,a);
        sz+=subtree[i];
        mxstsz[a]=max(mxstsz[a],subtree[i]);
    }
    subtree[a]=sz;
    //cout<<a<<' '<<p<<' '<<sz<<' '<<mxstsz[a]<<'\n';
    if(sz==1)
        cen[a]=a;
    else{
        for(int i:adj[a]){
            if(i==p)
                continue;
            if(subtree[i]!=mxstsz[a])
                continue;
            int x=cen[i];
            while(x!=a&&max(mxstsz[x],subtree[a]-subtree[x])>subtree[a]/2)
                x=par[x];
            if(max(mxstsz[x],subtree[a]-subtree[x])<=subtree[a]/2){
                cen[a]=x;
                break;
            }
        }
    }
}

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
    //factorial(100005);
    while(te--){
        int q;
        cin>>n>>q;
        for(int i=2;i<=n;i++){
            int p;
            cin>>p;
            par[i]=p;
            adj[i].pb(p);
            adj[p].pb(i);
        }
        dfs(1,-1);
        while(q--){
            int x;
            cin>>x;
            cout<<cen[x]<<'\n';
        }
    }
}
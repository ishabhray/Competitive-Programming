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
ll power(ll a, ll b){//a^b
    ll res=1;
    a=a%MOD;
    while(b>0){
        if(b&1){res=(res*a)%MOD;b--;}
        a=(a*a)%MOD;
        b>>=1;
    }
    return res;
}
ll fermat_inv(ll y){return power(y,MOD-2);}
ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}
ll min(ll a,ll b){return (a>b)?b:a;}
ll max(ll a,ll b){return (a>b)?a:b;}
int p[200005],dep[200005],tin[200005],tout[200005],T=0;
void dfs(int x,vi adj[]){
    tin[x]=T++;
    for(int i:adj[x]){
        if(p[x]==i)
            continue;
        p[i]=x;
        dep[i]=dep[x]+1;
        dfs(i,adj);
    }
    tout[x]=T++;
}
bool comp(const int l,const int r){
    return dep[l]<dep[r];
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
        int n,m;
        cin>>n>>m;
        vi adj[n+1];
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        p[1]=1;
        dfs(1,adj);
        while(m--){
            int k;
            cin>>k;
            int a[k];
            for(int i=0;i<k;i++)
                cin>>a[i];
            sort(a,a+k,comp);
            int t1=0,t2=T;
            bool ans=true;
            for(int i=0;i<k;i++){
                if(tin[p[a[i]]]<t1||tout[p[a[i]]]>t2){
                    ans=false;
                    break;
                }
                else
                    t1=tin[p[a[i]]],t2=tout[p[a[i]]];
            }
            if(ans)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
    }
}
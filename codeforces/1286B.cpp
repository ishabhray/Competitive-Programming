#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

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
ordered_set s;
void dfs(int a,int p,vi adj[],int ss[]){
    ss[a]=1;
    for(int i:adj[a]){
        if(i==p)
            continue;
        dfs(i,a,adj,ss);
        ss[a]+=ss[i];
    }
}
void dfs1(int a,int p,vi adj[],int ans[],int c[]){
    ans[a]=*(s.find_by_order(c[a]));
    s.erase(s.find(ans[a]));
    for(int i:adj[a]){
        if(i==p)
            continue;
        dfs1(i,a,adj,ans,c);
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
        int n;
        cin>>n;
        int c[n+1];
        vi adj[n+1];
        int root;
        for(int i=1;i<=n;i++){
            int p;
            cin>>p>>c[i];
            if(p){
                adj[i].pb(p);
                adj[p].pb(i);
            }
            else
                root=i;
        }
        int ss[n+1]={0};
        dfs(root,root,adj,ss);
        bool b=true;
        for(int i=1;i<=n;i++){
            if(c[i]>=ss[i]){
                b=false;
                break;
            }
        }
        if(!b){
            cout<<"NO";
            return 0;
        }
        
        for(int i=1;i<=n;i++)
            s.insert(i);
        int ans[n+1];
        dfs1(root,root,adj,ans,c);
        cout<<"YES\n";
        for(int i=1;i<=n;i++)
            cout<<ans[i]<<' ';
    }
}
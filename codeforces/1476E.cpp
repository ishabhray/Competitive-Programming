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

bool iscyclic(int a,vi adj[],int vis[],int cyc[]){
    vis[a]=1;
    cyc[a]=1;
    bool ans=false;
    for(int i:adj[a]){
        if(cyc[i]||ans)
            return true;
        if(vis[i])
            continue;
        ans|=iscyclic(i,adj,vis,cyc);
    }
    cyc[a]=0;
    return ans;
}
void topo(int a,vi adj[],int vis[],stack<int>&s){
    vis[a]=1;
    for(int i:adj[a]){
        if(vis[i])
            continue;
        topo(i,adj,vis,s);
    }
    s.push(a);
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
    //factorial(1000005);
    while(te--){
        int n,m,k;
        cin>>n>>m>>k;
        string p[n+1];
        map<string,int>mp;
        for(int i=1;i<=n;i++){
            cin>>p[i];
            mp[p[i]]=i;
        }
        string a[m];
        int mt[m];
        bool ans=true;
        for(int i=0;i<m;i++){
            cin>>a[i]>>mt[i];
            for(int j=0;j<k;j++){
                if(p[mt[i]][j]!=a[i][j]&&p[mt[i]][j]!='_')
                    ans=false;
            }
        }
        if(!ans){
            cout<<"NO";
            return 0;
        }
        vi adj[n+1];
        for(int i=0;i<m;i++){
            for(int j=0;j<(1<<k);j++){
                string curr;
                for(int x=0;x<k;x++){
                    if(j&(1<<x))
                        curr+=a[i][x];
                    else
                        curr+='_';
                }
                if(curr==p[mt[i]])
                    continue;
                if(mp.find(curr)!=mp.end()){
                    adj[mt[i]].pb(mp[curr]);
                }
            }
        }
        int vis[n+1]={0},cyc[n+1]={0};
        ans=false;
        for(int i=1;i<=n;i++){
            if(vis[i])
                continue;
            ans|=iscyclic(i,adj,vis,cyc);
        }
        if(ans){
            cout<<"NO";
            return 0;
        }
        memset(vis,0,sizeof(vis));
        stack<int>st;
        for(int i=1;i<=n;i++){
            if(vis[i])
                continue;
            topo(i,adj,vis,st);
        }
        cout<<"YES\n";
        while(st.size()){
            cout<<st.top()<<' ';
            st.pop();
        }
    }
}
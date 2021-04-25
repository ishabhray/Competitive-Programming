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

bool dfs(int a,int p,int vis[],vi adj[],int &st,int &end,int c){
    vis[a]=c;
    for(int j:adj[a]){
        if(j==p)
            continue;
        if(vis[j]){
            st=a;
            end=j;
            return true;
        }
        if(dfs(j,a,vis,adj,st,end,-c))
            return true;
    }
    return false;
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
        vi adj[n+1];
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        int vis[n+1]={0},st,end;
        bool cyc=dfs(1,0,vis,adj,st,end,1);
        //cout<<cyc<<' '<<st<<' '<<end<<'\n';
        if(cyc){
            queue<int>q;
            int d[n+1],back[n+1];
            memset(d,-1,sizeof(d));
            d[st]=0;
            for(int i:adj[st]){
                if(i!=end){
                    q.push(i);
                    d[i]=1,back[i]=st;
                }
            }
            while(q.size()){
                int x=q.front();
                q.pop();
                if(x==end)
                    break;
                for(int j:adj[x]){
                    if(d[j]!=-1)
                        continue;
                    else{
                        d[j]=d[x]+1,back[j]=x;
                        q.push(j);
                    }
                }
            }
            int j=end;
            vi v;
            v.pb(end);
            while(j!=st){
                j=back[j];
                v.pb(j);
            }
            if(v.size()<=k){
                cout<<"2\n"<<v.size()<<'\n';
                for(int i:v)
                    cout<<i<<' ';
            }
            else{
                cout<<"1\n";
                for(int i=0;i<(k+1)/2;i++)
                    cout<<v[2*i]<<' ';
            }
        }
        else{
            cout<<"1\n";
            vi x,y;
            for(int i=1;i<=n;i++){
                if(vis[i]==1)
                    x.pb(i);
                else
                    y.pb(i);
            }
            if(x.size()>=y.size()){
                for(int i=0;i<(k+1)/2;i++)
                    cout<<x[i]<<' ';
            }
            else{
                for(int i=0;i<(k+1)/2;i++)
                    cout<<y[i]<<' ';
            }
        }
    }
}
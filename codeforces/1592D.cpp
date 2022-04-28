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

int n,l,timer;
vv<vi>adj(1005);
vi tin,tout,dist;

void dfs(int a,int p){
    tin[a]=++timer;
    for(int i:adj[a]){
        if(i!=p){
            dist[i]=dist[a]+1;
            dfs(i,a);
        }
    }
}

void preprocess(int root){
    tin.resize(n+1);
    tout.resize(n+1);
    dist.resize(n+1);
    timer=0;
    dfs(root,root);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int te=1;
    // cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        cin>>n;
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        preprocess(1);
        int a[timer+1];
        for(int i=1;i<=n;i++)
            a[tin[i]]=i,a[tout[i]]=i;
        int l=2,r=timer,ans,x;
        cout<<"? "<<n<<' ';
        for(int i=1;i<=n;i++) cout<<i<<' ';
        cout<<endl;
        cin>>x;
        while(l<=r){
            int mid=(l+r)/2;
            set<int>s;
            for(int i=1;i<=mid;i++){
                s.insert(a[i]);
            }
            cout<<"? "<<s.size()<<' ';
            for(int i:s) cout<<i<<' ';
            cout<<endl;
            int y;
            cin>>y;
            if(y==x) ans=a[mid],r=mid-1;
            else l=mid+1;
        }
        int p;
        for(int i:adj[ans]){
            if(dist[i]<dist[ans]) p=i;
        }
        cout<<"! "<<p<<' '<<ans<<'\n';
    }
}
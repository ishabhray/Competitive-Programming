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

bool comp(ii &l,ii &r){
    if(l.ss!=r.ss)
        return l.ss<r.ss;
    else
        return l.ff<r.ff;
}
struct comp1{
    bool operator()(ii const& l,ii const& r){
        if(l.ss!=r.ss)
            return l.ss>r.ss;
        else
            return l.ff<r.ff;
    }
};
void disp(priority_queue<ii,vv<ii>,comp1>q){
    while(!q.empty()){
        auto i=q.top();
        q.pop();
        cout<<i.ff<<' '<<i.ss<<'\n';
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
        int n,m,sx,sy,fx,fy;
        cin>>n>>m>>sx>>sy>>fx>>fy;
        map<ii,int>hash;
        hash[{sx,sy}]++,hash[{fx,fy}]++;
        ii a[m];
        for(int i=0;i<m;i++){
            cin>>a[i].ff>>a[i].ss;
            hash[a[i]]++;
        }
        int c=1;
        for(auto i:hash)
            hash[i.ff]=c++;
        vv<ii> adj[c];
        int start=hash[{sx,sy}],end=hash[{fx,fy}];
        adj[start].pb({end,abs(sx-fx)+abs(sy-fy)});
        for(int i=0;i<m;i++){
            int d1=min(abs(a[i].ff-sx),abs(a[i].ss-sy));
            int d2=abs(a[i].ff-fx)+abs(a[i].ss-fy);
            adj[start].pb({hash[a[i]],d1});
            adj[hash[a[i]]].pb({end,d2});
        }
        sort(a,a+m);
        for(int i=0;i<m-1;i++){
            int d=abs(a[i+1].ff-a[i].ff);
            adj[hash[a[i]]].pb({hash[a[i+1]],d});
            adj[hash[a[i+1]]].pb({hash[a[i]],d});
        }
        sort(a,a+m,comp);
        for(int i=0;i<m-1;i++){
            int d=abs(a[i+1].ss-a[i].ss);
            adj[hash[a[i]]].pb({hash[a[i+1]],d});
            adj[hash[a[i+1]]].pb({hash[a[i]],d});
        }
        priority_queue<ii,vv<ii >,comp1>q;
        q.push({start,0});
        int vis[c];
        memset(vis,-1,sizeof(vis));
        vis[start]=0;
        while(!q.empty()){
            //disp(q);
            auto x=q.top();
            q.pop();
            if(x.ss>vis[x.ff])
                continue;
            for(auto i:adj[x.ff]){
                if(vis[i.ff]==-1||vis[i.ff]>x.ss+i.ss){
                    q.push({i.ff,x.ss+i.ss});
                    vis[i.ff]=x.ss+i.ss;
                }
            }
        }
        cout<<vis[end]<<'\n';
    }
}
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
#define MAXN 400005
int n,l,timer;
vv<vi>adj(300005);
vi tin,tout,dist;
vv<vi>dep(300005);
void dfs(int a,int p){
    tin[a]=++timer;
    dep[dist[a]].pb(tin[a]);
    for(int i:adj[a]){
        if(i!=p){
            dist[i]=dist[a]+1;
            dfs(i,a);
        }
    }
    tout[a]=++timer;
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
    int te=1;
    //cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(100005);
    while(te--){
        int q;
        cin>>n;
        for(int i=2;i<=n;i++){
            int u;
            cin>>u;
            adj[u].pb(i);
        }
        preprocess(1);
        cin>>q;
        for(int i=0;i<q;i++){
            int u,d;
            cin>>u>>d;
            int l=tin[u],r=tout[u];
            // for(int i:dep[d])
            //     cout<<i<<' ';
            // cout<<'\n'<<l<<' '<<r<<'\n';
            auto it=lower_bound(all(dep[d]),l);
            if(it==dep[d].end()){
                cout<<"0\n";
                continue;
            }
            auto it1=lower_bound(all(dep[d]),r);
            if(it1==dep[d].end()||*it1>r){
                if(it1==dep[d].begin()){
                    cout<<"0\n";
                    continue;
                }
                it1--;
            }
            cout<<it1-it+1<<'\n';
        }
    }
}
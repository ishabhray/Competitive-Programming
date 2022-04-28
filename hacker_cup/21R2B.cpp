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

int n;
vv<vi>adj(800005);
map<int,int>s[800005];
map<int,int>tot;
int v[800005];
int ans; 
void dfs(int a,int p){
    int mx=0,b=-1;
    for(int i:adj[a]){
        if(i!=p){
            dfs(i,a);
            if(s[i].size()>mx){
                mx=s[i].size();
                b=i;
            }
        }
    }
    if(a==1) return;
    if(b==-1){
        if(tot[v[a]]==1) ans++;
        else s[a][v[a]]++;
        return;
    }
    swap(s[a],s[b]);
    s[a][v[a]]++;
    if(s[a][v[a]]==tot[v[a]]) s[a].erase(v[a]);
    for(int i:adj[a]){
        if(i==p||i==b)
            continue;
        for(auto j:s[i]){
            s[a][j.ff]+=j.ss;
            if(s[a][j.ff]==tot[j.ff]) s[a].erase(j.ff);
        }
    }
    if(s[a].empty()) ans++;
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
    cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    for(int T=1;T<=te;T++){
        cin>>n;
        tot.clear();
        for(int i=1;i<=n;i++){
            adj[i].clear();
            s[i].clear();
        }
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        for(int i=1;i<=n;i++){
            cin>>v[i];
            tot[v[i]]++;
        }
        ans=0;
        dfs(1,0);
        cout<<"Case #"<<T<<": "<<ans<<'\n';
    }
}
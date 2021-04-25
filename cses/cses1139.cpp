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
#define MAXN 200005
int n;
vv<vi>adj(300005);
vi ans(300005),sz(300005);
set<int>s[300005];
int v[300005];

void dfs(int a,int p){
	sz[a]=1;
	int mx=0,b=-1;
    for(int i:adj[a]){
        if(i!=p){
            dfs(i,a);
            sz[a]+=sz[i];
            if(sz[i]>mx){
            	mx=sz[i];
            	b=i;
            }
        }
    }
    if(b==-1){
    	s[a].insert(v[a]);
    	ans[a]=1;
    	return;
    }
    swap(s[a],s[b]);
    s[a].insert(v[a]);
    for(int i:adj[a]){
    	if(i==p||i==b)
    		continue;
    	for(auto j:s[i])
    		s[a].insert(j);
    }
    ans[a]=s[a].size();
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
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>v[i+1];
        for(int i=2;i<=n;i++){
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        dfs(1,0);
        for(int i=1;i<=n;i++)
        	cout<<ans[i]<<' ';
    }
}
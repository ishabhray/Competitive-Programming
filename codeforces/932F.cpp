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

struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	static const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {//add lines of the form kx+m
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};
ll a[100005],b[100005],dp[100005]={0},sz[100005]={0};
vl adj[100005];
LineContainer lc[100005];
void dfs(ll x,ll p){
	int mx=0,big_child=-1;
	sz[x]=1;
	for(int i:adj[x]){
		if(i==p)
			continue;
		dfs(i,x);
		sz[x]+=sz[i];
		if(sz[i]>mx)
			mx=sz[i],big_child=i;
	}
	if(sz[x]==1){
		lc[x].add(-b[x],0);
		return;
	}
	swap(lc[x],lc[big_child]);
	for(int i:adj[x]){
		if(i==p||i==big_child)
			continue;
		for(auto line:lc[i])
			lc[x].add(line.k,line.m);
	}
	dp[x]=-lc[x].query(a[x]);
	lc[x].add(-b[x],-dp[x]);
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
    	ll n;
    	cin>>n;
    	for(int i=0;i<n;i++)
    		cin>>a[i+1];
    	for(int i=0;i<n;i++)
    		cin>>b[i+1];
    	for(int i=1;i<n;i++){
    		int u,v;
    		cin>>u>>v;
    		adj[u].pb(v);
    		adj[v].pb(u);
    	}
    	dfs(1,0);
    	for(int i=1;i<=n;i++)
    		cout<<dp[i]<<' ';
    }
}
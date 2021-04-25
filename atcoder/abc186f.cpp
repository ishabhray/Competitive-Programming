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
ll t[4*MAXN];
void build(int a[],int v,int tl,int tr)
{
	if(tl==tr)
		t[v]=a[tl];
	else{
		int tm=(tl+tr)/2;
		build(a,v*2,tl,tm);
		build(a,v*2+1,tm+1,tr);
		t[v]=t[v*2]+t[v*2+1];
	}
}
ll sum(int v,int tl,int tr,int l,int r)
{
	if(l>r)
		return 0;
	if(l==tl&&r==tr)
		return t[v];
	int tm=(tl+tr)/2;
	return sum(v*2,tl,tm,l,min(r,tm))+sum(v*2+1,tm+1,tr,max(l,tm+1),r);
}
void update(int v,int tl,int tr,int pos,int new_val)
{
	if(tl==tr)
		t[v]=new_val;
	else{
		int tm=(tl+tr)/2;
		if(pos<=tm)
			update(2*v,tl,tm,pos,new_val);
		else
			update(2*v+1,tm+1,tr,pos,new_val);
		t[v]=t[2*v]+t[2*v+1];
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
	//factorial(1000005);
	while(te--){
		int h,w,m;
		cin>>h>>w>>m;
		int hor[h+1],ver[w+1];
		vi obs[h+1];
		for(int i=0;i<=h;i++)
			hor[i]=w+1;
		for(int i=0;i<=w;i++)
			ver[i]=h+1;
		for(int i=0;i<m;i++){
			int x,y;
			cin>>x>>y;
			hor[x]=min(hor[x],y);
			ver[y]=min(ver[y],x);
			obs[x].pb(y);
		}
		ll ans=0;
		for(int i=1;i<hor[1];i++)
			ans+=ver[i]-1;
		for(int i=hor[1];i<=w;i++)
			update(1,1,w,i,1);
		for(int i=1;i<ver[1];i++){
			ans+=sum(1,1,w,1,hor[i]-1);
			for(int j:obs[i])
				update(1,1,w,j,1);
		}
		cout<<ans<<'\n';
	}
}
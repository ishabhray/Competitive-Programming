#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pll pair<ll,ll>
#define vv vector

struct cmp {
	bool operator() (const pair<int, int> &a, const pair<int, int> &b) const {
		int lena = a.second - a.first + 1;
		int lenb = b.second - b.first + 1;
		if (lena == lenb) return a.first < b.first;
		return lena > lenb;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int t=1;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		set<ii, cmp>segs;
		segs.insert({0,n-1});
		int a[n];
		for(int i=1;i<=n;i++){
			ii cur=*(segs.begin());
			segs.erase(segs.begin());
			int id=(cur.ff+cur.ss)/2;
			a[id]=i;
			if(cur.ff<id)
				segs.insert({cur.ff,id-1});
			if(cur.ss>id)
				segs.insert({id+1,cur.ss});
		}
		for(int i=0;i<n;i++)
			cout<<a[i]<<' ';
		cout<<'\n';
	}
}
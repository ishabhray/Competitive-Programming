#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pint pair<int,int>
#define vv vector
#define C 1000000007

typedef struct{
	int h,w;
}doll;

bool sorter(doll const& l,doll const& r){
	if(l.h!=r.h)
		return l.h<r.h;
	else
		return l.w>r.w;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		doll ds[n];
		for(int i=0;i<n;i++)
			cin>>ds[i].w>>ds[i].h;
		sort(ds,ds+n,&sorter);
		multiset<int>s;
		s.insert(ds[0].w);
		for(int i=1;i<n;i++){
			int wt=ds[i].w;
			auto it=lower_bound(s.begin(),s.end(),wt);
			if(it==s.begin())
				s.insert(wt);
			else{
				s.insert(--it,wt);
				s.erase(it);
			}
			
		}
		cout<<s.size()<<'\n';
	}
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int n;
	long long int w,l;
	cin>>n>>w>>l;
	int h[n],r[n];
	vector<pair<long long int,int> >v(n);
	for(int i=0;i<n;i++){
		cin>>h[i]>>r[i];
		long long int m=l-h[i];
		if(m<=0)
			m=0;
		else
			m=m/r[i]+(m%r[i]!=0);
		v[i]={m,i};
	}
	sort(v.begin(),v.end());
	long long int s=0ll,sh=0ll,sr=0ll;
	int x=0;
	for(int i=0;i<n;i++){
		x=v[i].first;
		sh+=h[v[i].second];
		sr+=r[v[i].second];
		s=sh+x*sr;
		if(s>=w)
			break;
	}
	if(s>=w)
		cout<<x;
	else{
		while(s<w){
			x++;
			s=sh+x*sr;
		}
		cout<<x;
	}
}
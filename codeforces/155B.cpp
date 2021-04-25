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

bool sorter(ii const& l,ii const& r){
	if(l.ss!=r.ss)
		return l.ss>r.ss;
	else
		return l.ff>r.ff;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;
	vv<ii > v(n);
	for(int i=0;i<n;i++)
		cin>>v[i].ff>>v[i].ss;
	sort(v.begin(),v.end(),&sorter);
	int cnt=1;
	int sum=0;
	for(int i=0;i<n&&cnt>0;i++){
		sum+=v[i].ff;
		cnt+=v[i].ss-1;
	}
	cout<<sum;
}
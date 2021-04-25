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

	cout<<setprecision(16);
	int n,l;
	cin>>n>>l;
	set<int>s;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		s.insert(x);
	}
	double max=(*s.begin()>l-*(--s.end()))? *s.begin():(l-*(--s.end()));
	int a=*s.begin();
	s.erase(s.begin());
	for(auto it=s.begin();it!=s.end();it++){
		if(max<(*it-a)/2.0)
			max=(*it-a)/2.0;
		a=*it;
	}
	cout<<max;
}
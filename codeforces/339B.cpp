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

	int n,m;
	cin>>n>>m;
	deque<int>d;
	for(int i=0;i<m;i++){
		int x;
		cin>>x;
		if(d.empty())
			d.push_back(x);
		else if(d.back()!=x)
			d.push_back(x);
	}
	long long int c=0;
	int i=1;
	for(auto it:d){
		c+=(it-i>=0)?it-i:n+it-i;
		i=it;
	}
	cout<<c;
}
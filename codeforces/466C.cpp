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
	ll a[n],p[n+1]={0};
	for(int i=0;i<n;i++){
		cin>>a[i];
		p[i+1]=a[i]+p[i];
	}
	if(p[n]%3!=0)
		cout<<"0\n";
	else{
		ll c=0;
		queue<int>q;
		for(int i=0;i<n;i++)
			if(p[n]-p[i]==p[n]/3)
				q.push(i);
		for(int i=0;i<n;i++){
			if(q.empty())
				break;
			if(p[i+1]==p[n]/3){
				while(q.front()<=i+1){
					q.pop();
					if(q.empty())
						break;
				}
				c+=q.size();
			}
		}
		cout<<c;
	}
}
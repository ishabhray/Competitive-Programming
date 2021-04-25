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

	int x1,x2,y1,y2;
	cin>>x1>>y1>>x2>>y2;
	if(x1==x2)
		cout<<x1+y1-y2<<' '<<y1<<' '<<x1+y1-y2<<' '<<y2;
	else if(y1==y2)
		cout<<x1<<' '<<y1+x1-x2<<' '<<x2<<' '<<y2+x1-x2;
	else if(abs(x1-x2)==abs(y1-y2))
		cout<<x1<<' '<<y2<<' '<<x2<<' '<<y1;
	else
		cout<<-1;
}
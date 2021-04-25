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

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		sort(a,a+n);
		int cnt=1,x=0;
		for(int i=0;i<n;i++){
			if(cnt+x>=a[i])
				cnt+=x+1,x=0;
			else
				x++;
		}
		//int cnt=1,x=a[0],y=1;
		//bool b=true;
		//for(int i=1;i<n;i++){
		//	cout<<cnt<<' '<<x<<' '<<y<<'\n';
		//	if(a[i]==x)
		//		y++;
		//	else if(y+cnt-1>=x)
		//		cnt+=y,x=a[i],y=1;
		//	else{
		//		b=false;
		//		break;
		//	}
		//}
		//if(b&&cnt+y-1>=x)
		//	cnt+=y;
		cout<<cnt<<'\n';
	}
}
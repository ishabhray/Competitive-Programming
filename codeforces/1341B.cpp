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
		int n,k;
		cin>>n>>k;
		int a[n],b[n]={0};
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=1;i<n-1;i++){
			if(a[i]>a[i-1]&&a[i]>a[i+1])
				b[i]=1;
		}
		int cnt=0;
		for(int i=0;i<k-1;i++){
			if(b[i]==1)
				cnt++;
		}
		int max=cnt,pos=0;
		for(int i=1;i<n-k+1;i++){
			if(b[i]==1)
				cnt--;
			if(b[i+k-2]==1)
				cnt++;
			if(cnt>max)
				max=cnt,pos=i;
		}
		if(max==0)
			cout<<"0 "<<pos+1<<'\n';
		else
			cout<<max+1<<' '<<pos+1<<'\n';
	}
}
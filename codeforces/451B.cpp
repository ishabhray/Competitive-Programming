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
	int n;
	cin>>n;
	int a[n];
	cin>>a[0];
	int c=0,l=1,r=1;
	
	bool b=true;
	for(int i=2;i<=n;i++){
		cin>>a[i-1];
		if(a[i-1]<a[i-2]){
			if(b)
				b=false,c++,l=i-1;
		}
		else{
			if(!b)
				b=true,r=i-1;
		}
	}
	if(b==false)
		r=n;
	if(c>1)
		cout<<"no";
	else{
		if(l==1&&r==n)
			cout<<"yes\n"<<l<<' '<<r;
		else if(l==1&&a[r]>a[l-1])
			cout<<"yes\n"<<l<<' '<<r;
		else if(r==n&&a[l-2]<a[r-1])
			cout<<"yes\n"<<l<<' '<<r;
		else if(a[r]>a[l-1]&&a[l-2]<a[r-1])
			cout<<"yes\n"<<l<<' '<<r;
		else
			cout<<"no";
	}
}

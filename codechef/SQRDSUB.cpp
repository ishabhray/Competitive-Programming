#include <bits/stdc++.h>
using namespace std;

long long int findcount1(int a[],int l, int r,int mid)
{
	//for(int j=l;j<=r;j++)
	//	cout<<a[j]<<' ';
	//cout<<'\n';
	long long int x0=0,x1=0,x2=0,y0=0,y1=0,y2=0;
	long long int s=0;
	for(int i=mid;i>=l;i--){
		s+=a[i];
		if(s==0)
			x0++;
		else if(s==1)
			x1++;
		else
			x2++;
	}
	s=0;
	for(int i=mid+1;i<=r;i++){
		s+=a[i];
		if(s==0)
			y0++;
		else if(s==1)
			y1++;
		else
			y2++;
	}
	//cout<<x0<<' '<<x1<<' '<<x2<<' '<<y0<<' '<<y1<<' '<<y2<<'\n';
	return x0*y0+x0*y2+x1*y1+x1*y2+x2*y0+x2*y1+x2*y2;
}

long long int findcount(int a[],int l,int r)
{
	//for(int j=l;j<=r;j++)
	//	cout<<a[j]<<' ';
	//cout<<'\n';
	if(l>r)
		return 0;
	else if(l==r){
		if(a[l]==0||a[l]>1)
			return 1;
		else
			return 0;
	}
	else{
		long long int count=0,mid=(l+r)/2;
		count+=findcount(a,l,mid);
		//cout<<count<<"#####\n";
		count+=findcount(a,mid+1,r);
		//cout<<count<<"#####\n";
		count+=findcount1(a,l,r,mid);
		//cout<<count<<"#####\n";
		return(count);
	}
}

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
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			if(x%4==0)
				a[i]=2;
			else if(x%2==0)
				a[i]=1;
			else
				a[i]=0;
		}
		long long int count;
		count=findcount(a,0,n-1);
		cout<<count<<'\n';
	}
}
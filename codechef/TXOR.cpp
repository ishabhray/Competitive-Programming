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

	int t;
	cin>>t;
	while(t--){
		int n,x,i,a=0,b=0;
		cin>>n>>x;
		while(n--){
			i=x/pow(10,n);
			x=x%(int)pow(10,n);
			a*=10,b*=10;
			if(i==1){
				if(a>b)
					b+=1;
				else
					a+=1;
			}
			else if(i==2){
				if(a>b)
					b+=2;
				else if(b>a)
					a+=2;
				else
					a+=1,b+=1;
			}
		}
		cout<<a<<'\n'<<b<<'\n';
	}
}
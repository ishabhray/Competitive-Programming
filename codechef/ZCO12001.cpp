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

	int n;
	cin>>n;
	stack<int>s;
	int d=0,di=0,m=0,mi=0,x=0,y=0,yi=0;
	for(int i=0;i<n;i++){
		int j;
		cin>>j;
		if(y==0)
			yi=i;
		y++;
		if(j==1){
			s.push(1);
			x=i;
		}
		else{
			if(s.size()>d)
				d=s.size(),di=x;
			s.pop();
			if(s.empty()){
				if(y>m)
					m=y,mi=yi;
				y=0;
			}
		}
	}
	cout<<d<<' '<<di+1<<' '<<m<<' '<<mi+1;
}
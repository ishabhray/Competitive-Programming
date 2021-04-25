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

int check(int a, int p, int b, int q)
{
	if(a-p==b-q)
		return 1;
	else if(p!=0&&q!=0){
		if(a/p==b/q){
			if(a%p==0&&b%q==0)
				return 1;
			else
				return 2;
		}
	}
	else
		return 2;
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
		int a,b,c,p,q,r;
		cin>>p>>q>>r>>a>>b>>c;
		int e= (p==a) + (q==b) +(c==r);
		
		if(e==3)
			cout<<"0\n";
		else if(e==2)
			cout<<"1\n";
		else if(e==1){
			if(a==p)
				cout<<check(b,q,c,r)<<'\n';
			else if(b==q)
				cout<<check(a,p,c,r)<<'\n';
			else
				cout<<check(a,p,b,q)<<'\n';
		}
		else{
			if(a-p==b-q&&b-q==c-r)
				cout<<"1\n";
			else if(p!=0&&q!=0&&r!=0&&a/p==b/q&&b/q==c/r&&a%p==b%q&&c%r==b%q){
				if(a%p==0)
					cout<<"1\n";
				else
					cout<<"2\n";
			}
			else if((a-p==b-q)||(b-q==c-r)||(a-p==c-r))
				cout<<"2\n";
			else if((p!=0&&q!=0&&a/p==b/q&&a%p==b%q&&(a%p==0||a%p==))||()||())
			
		}
	}
}
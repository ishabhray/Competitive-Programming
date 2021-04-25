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

int gcd(int a,int b){return (b)?gcd(b,a%b):a;}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int n,m,s,f;
	cin>>n>>m>>s>>f;
	map<int, ii >M;
	for(int i=0;i<m;i++){
		int t,l,r;
		cin>>t>>l>>r;
		M[t]={l,r};
	}
	for(int i=1;;i++){
		if(f>s){
		if(s>=M[i].ff-1&&s<=M[i].ss)
			cout<<'X';
		else{
			cout<<'R';
			s++;
		}}
		else{
			if(s<=M[i].ss+1&&s>=M[i].ff)
				cout<<'X';
			else{
				cout<<'L';
				s--;
			}
		}
		if(s==f)
			break;
	}
}
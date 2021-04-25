#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pint pair<int,int>
#define vv vector
#define C 1000000007
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
	ll sf=0,ss=0;
	vi f,s;
	string y;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		if(x>0){
			sf+=x;
			f.pb(x);
			y="first";
		}
		else{
			ss-=x;
			s.pb(-x);
			y="second";
		}
	}
	if(sf>ss)
		cout<<"first";
	else if(ss>sf)
		cout<<"second";
	else{
		int i;
		for(i=0;i<min(f.size(),s.size());i++){
			if(f[i]>s[i]){
				cout<<"first";
				break;
			}
			else if(s[i]>f[i]){
				cout<<"second";
				break;
			}
		}
		if(i==min(f.size(),s.size())){
			if(f.size()==s.size())
				cout<<y;
			else
				cout<<(f.size()>s.size())?"first":"second";
		}
	}
}
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

	int n;
	cin>>n;
	bool b= false;
	for(int i=1;i*(i+1)<2*n;i++){
		int j=i*(i+1)/2;
		int k=sqrt(2*(n-j));
		if(k*(k+1)/2==n-j){
			b=true;
			break;
		}
	}
	if(b)
		cout<<"YES";
	else
		cout<<"NO";
}
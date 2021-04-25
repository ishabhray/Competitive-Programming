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

	ll p,d;
	cin>>p>>d;
	ll temp=p;
	ll cnt=0;
	int j=0;
	while(cnt<d&&p>0){
		if(p%10!=9){
			if(cnt+((p%10)+1)*(ll)pow(10,j)<=d){
				cnt+=((p%10)+1)*(ll)pow(10,j);
				p/=10;
				p--;
				j++;
			}
			else
				break;
		}
		else{
			p/=10;
			j++;
		}
	}
	cout<<temp-cnt;
}
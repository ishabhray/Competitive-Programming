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

	int n;
	cin>>n;
	int size=(log10(n)+1);
	if(size%2==0){
		ll sum=0;
		for(int i=0;i<size;i++)
			sum+=pow(10,i)*((i<size/2)?4:7);
		//cout<<sum<<' ';
		if(n>sum)
		size+=1;
	}
	if(size%2){
		for(int i=0;i<(size+1)/2;i++)
			cout<<4;
		for(int i=0;i<(size+1)/2;i++)
			cout<<7;
		cout<<'\n';
	}
	else{
		int a[size],b[size];
		for(int i=size-1;i>=0;i--)
			b[i]=n%10,n/=10;
		int c4=0,c7=0,i;
		for(i=0;i<size-1;i++){
			int dig1=b[i];
			int dig2=b[i+1];
			//cout<<dig1<<' '<<dig2<<'\n';
			if(dig1<4){
				a[i]=4;
				c4++;
				break;
			}
			if(dig1==4&&dig2<=7)
				a[i]=4,c4++;
			else if(dig1==4&&dig2>7||dig1<7){
				a[i]=7;
				c7++;
				break;
			}
			else
				a[i]=7,c7++;
			if(c4==size/2||c7==size/2)
				break;
		}
		for(i+=1;i<size;i++){
			if(c4!=size/2)
				a[i]=4,c4++;
			else
				a[i]=7,c7++;
		}
		for(int i=0;i<size;i++)
			cout<<a[i];
	}
}
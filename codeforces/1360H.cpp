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

ll binaryToDecimal(string n) 
{ 
    string num = n; 
    ll dec_value = 0; 
  
    // Initializing base value to 1, i.e 2^0 
    ll base = 1; 
  
    int len = num.length(); 
    for (int i = len - 1; i >= 0; i--) { 
        if (num[i] == '1') 
            dec_value += base; 
        base = base * 2; 
    } 
  
    return dec_value; 
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
		int n,m;
		cin>>n>>m;
		string a[n];
		set<ll> b,x;
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n;i++)
			b.insert(binaryToDecimal(a[i]));
		int r=1;
		ll median=(ll)(pow(2,m-1))-1;
		for(auto it:b){
			//for(int i=m-1;i>=0;i--){
			//	ll k=median>>i;
			//	if(k&1)
			//		cout<<'1';
			//	else
			//		cout<<'0';
			//}
			//cout<<' ';
			if(it>=median){
				if(r==0){
					do{
						median--;
					}while(x.find(median)!=x.end());
					r=1;
				}
				else{
					r=0;
					if(it==median){
						do{
							median++;
						}while(x.find(median)!=x.end());
					}					
				}
			}
			else{
				if(r==0)
					r=1;
				else{
					r=0;
					do{
						median++;
					}while(x.find(median)!=x.end());
				}
			}
			x.insert(it);
		}
		for(int i=m-1;i>=0;i--){
			ll k=median>>i;
			if(k&1)
				cout<<'1';
			else
				cout<<'0';
		}
		cout<<'\n';
	}
}
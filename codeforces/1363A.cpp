#include <bits/stdc++.h>
using namespace std;

#define PI 3.141592653589
#define ll long long int
#define ld long double
#define vi vector<int>
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pll pair<ll,ll>
#define vv vector
int MOD=1e9+7;
ll power(ll a, ll b){//a^b
    ll res=1;
    a=a%MOD;
    while(b>0){
        if(b&1){res=(res*a)%MOD;b--;}
        a=(a*a)%MOD;
        b>>=1;
    }
    return res;
}
ll fermat_inv(ll y){return power(y,MOD-2);}
ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int t=1;
	cin>>t;
	    while(t--){
        ll n,x;
        cin>>n>>x;
        ll a[n],e=0,o=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]%2==0)
                e++;
            else
                o++;
        }
        bool b=true;
        //cout<<e<<' '<<o<<'\n';
        for(ll i=1;i<=o;i+=2){
        	if(e>=x-i&&x-i>=0){
        		cout<<"Yes\n";
        		b=false;
        		break;
        	}
        }
        if(b)
        	cout<<"No\n";
    }
}
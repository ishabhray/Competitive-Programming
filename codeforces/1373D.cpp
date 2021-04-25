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
int MOD=998244353;
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
ll min(ll a,ll b){return (a>b)?b:a;}
ll max(ll a,ll b){return (a>b)?a:b;}

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
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        ll ans=0;
        for(int i=0;i<n;i+=2)
            ans+=a[i];
        vi v1,v2;
        for(int i=0;i<n-1;i+=2)
            v1.pb(a[i+1]-a[i]);
        for(int i=1;i<n-1;i+=2)
            v2.pb(a[i]-a[i+1]);
        n=v1.size();
        ll mx=0,sum=0;
        for(int i=0;i<n;i++){
            sum+=v1[i];
            if(sum<0)
                sum=0;
            mx=max(mx,sum);
        }
        sum=0;
        n=v2.size();
        for(int i=0;i<n;i++){
            sum+=v2[i];
            if(sum<0)
                sum=0;
            mx=max(mx,sum);
        }
        cout<<ans+mx<<'\n';
    }
}
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
	//cin>>t;
    while(t--){
        ll k;
        cin>>k;
        int a[10];
        for(int i=0;i<10;i++)
            a[i]=1;
        ll cnt=1;
        while(cnt<k){
            for(int i=0;i<10;i++){
                cnt/=a[i];
                a[i]++;
                cnt*=a[i];
                if(cnt>=k)
                    break;
            }
        }
        //for(int i=0;i<10;i++)
        //    cout<<a[i]<<' ';
        //cout<<'\n';
        string s="codeforces";
        for(int i=0;i<10;i++){
            for(int j=0;j<a[i];j++)
                cout<<s[i];
        }
    }
}
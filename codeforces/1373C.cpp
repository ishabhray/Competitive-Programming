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
        string s;
        cin>>s;
        ll n=s.size();
        int a[n]={0};
        for(int i=0;i<n;i++){
            if(s[i]=='-')
                a[i]=(i==0)?-1:a[i-1]-1;
            else
                a[i]=(i==0)?1:a[i-1]+1;
        }
        /*for(int i=0;i<n;i++)
            cout<<a[i]<<' ';
        cout<<'\n';*/
        ll res=0,init=0,cur=0;
        for(int i=0;i<n;i++){
            //cout<<init<<' '<<cur<<' '<<res<<'\n';
            res+=1;
            if(s[i]=='-')
                cur--;
            else
                cur++;
            if(cur+init<0)
                res+=i+1,++init;
        }

        cout<<res<<'\n';
    }
}
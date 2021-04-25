#include <bits/stdc++.h>
using namespace std;

#define PI 3.141592653589
#define ll double
#define ld long double
#define vi vector<int>
#define vl vector<ll>
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pll pair<ll,ll>
#define vv vector
int MOD=1e9+7;

bool check(ll k,vl &v,ll d,ll n){
    ll t=v[0];
    for(ll i=1;i<n;i++){
        if(t+k>v[i]+d)
            return false;
        t=max(t+k,v[i]);
    }
    return true;
}

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
    //SieveOfEratosthenes(1000000);
    //factorial(100005);
    while(t--){
        ll n,d;
        cin>>n>>d;
        vl v(n);
        for(ll i=0;i<n;i++)
            cin>>v[i];
        sort(v.begin(),v.end());
        ll cnt=0;
        ll l=1,r=1e15,ans;
        while(cnt++<100){
            ld mid=(l+r)/2;
            //cout<<l<<' '<<r<<' '<<mid<<'\n';
            if(check(mid,v,d,n))
                ans=mid,l=mid+1;
            else r=mid-1;
        }
        cout<<setprecision(15)<<ans<<'\n';
    }
}
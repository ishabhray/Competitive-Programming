#include <bits/stdc++.h>
using namespace std;

#define PI 3.141592653589
#define ll long long int
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
#define all(v) (v).begin(),(v).end()
#define MAXN 300005

ll f(ll x,ll n){
    ll cnt=0;
    for(int i=1;i<=n;i++)
        cnt+=min(n,x/i);
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int te=1;
    //cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        ll n;
        cin>>n;
        ll l=1,r=n*n,ans;
        while(l<=r){
            ll mid=(l+r)/2;
            if(f(mid,n)<=n*n/2)
                l=mid+1,ans=mid;
            else
                r=mid-1;
        }
        cout<<ans+1;
    }
}
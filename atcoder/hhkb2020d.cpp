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
int MOD=1e9+7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ll te=1;
    cin>>te;
    while(te--){
        ll n,a,b;
        cin>>n>>a>>b;
        if(n<a+b){
            cout<<"0\n";
            continue;
        }
        ll alpha=(n-a+1)%MOD,beta=(n-b+1),gamma=(n-a-b+1);
        ll ans=alpha*alpha%MOD*beta%MOD*beta%MOD;
        ll v=(alpha*beta%MOD)-(gamma*(gamma+1)%MOD);
        v=(v+MOD)%MOD;
        v=v*v%MOD;
        ans=(ans%MOD-v+MOD)%MOD;
        cout<<ans<<'\n';
    }
}
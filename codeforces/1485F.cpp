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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int te=1;
    cin>>te;
    int MOD=1e9+7;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        ll n;
        cin>>n;
        ll a[n+1],dp1[n+1]={0},dp2[n+1]={0};
        for(int i=1;i<=n;i++)
            cin>>a[i];
        map<ll,ll>m;
        ll pre=0;
        m[0]=0;
        dp1[0]=1,dp2[0]=1;
        for(int i=1;i<=n;i++){
            dp1[i]=(2*dp1[i-1]%MOD-dp2[i-1]+MOD)%MOD;
            dp2[i]=0;
            pre+=a[i];
            if(m.find(pre)!=m.end())
                dp2[i]=dp1[m[pre]];
            m[pre]=i;
        }
        cout<<dp1[n]<<'\n';
    }
}
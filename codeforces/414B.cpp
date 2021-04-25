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
int MOD=1e9+7;

ll min(ll a,ll b){return (a>b)?b:a;}
ll max(ll a,ll b){return (a>b)?a:b;}

ll dp[2005][2005];

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
    
    //factorial(100005);
    while(t--){
        ll n,k;
        cin>>n>>k;
        for(int i=1;i<=k;i++){
            for(int j=1;j<=n;j++){
                if(i==1)
                    dp[i][j]=1;
                for(int c=j;c<=n;c+=j){
                    dp[i+1][c]+=dp[i][j];
                    dp[i+1][c]%=MOD;
                }
            }
        }
        ll ans=0;
        for(int i=1;i<=n;i++)
            ans+=dp[k][i],ans%=MOD;
        cout<<ans<<'\n';
    }
}
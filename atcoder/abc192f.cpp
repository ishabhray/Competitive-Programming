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
ll dp[101][101][101],temp[101][101][101];
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
        ll n,x;
        cin>>n>>x;
        ll a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            memset(temp,-1,sizeof(temp));
            for(int j=1;j<=n;j++)
                temp[1][j][a[i]%j]=a[i];
            for(int j=0;j<=n;j++){
                for(int k=0;k<=n;k++){
                    for(int m=0;m<=n;m++){
                        if(dp[j][k][m]==-1)
                            continue;
                        temp[j+1][k][(m+a[i])%k]=max(dp[j][k][m]+a[i],temp[j+1][k][(m+a[i])%k]);
                    }
                }
            }
            for(int j=0;j<=n;j++)
                for(int k=0;k<=n;k++)
                    for(int m=0;m<=n;m++)
                        dp[j][k][m]=max(dp[j][k][m],temp[j][k][m]);
        }
        ll ans=LLONG_MAX;
        for(ll i=1;i<=n;i++){
            if(dp[i][i][x%i]==-1)
                continue;
            ans=min(ans,(x-dp[i][i][x%i])/i);
        }
        cout<<ans;
    }
}
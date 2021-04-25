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
int MOD=998244353;

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
        int n;
        cin>>n;
        int a[n+1];
        for(int i=0;i<n;i++)
            cin>>a[i];
        ll dp[205][2];
        memset(dp,0,sizeof(dp));
        if(a[0]!=-1)
            dp[a[0]][0]=1;
        else{
            for(int i=1;i<=200;i++)
                dp[i][0]=1;
        }
        for(int i=1;i<n;i++){
            ll temp[205][2];
            memset(temp,0,sizeof(temp));
            if(a[i]!=-1){
                for(int j=1;j<a[i];j++)
                    (temp[a[i]][0]+=dp[j][0]+dp[j][1])%=MOD;
                (temp[a[i]][1]+=dp[a[i]][0]+dp[a[i]][1])%=MOD;
                for(int j=a[i]+1;j<=200;j++)
                    (temp[a[i]][1]+=dp[j][1])%=MOD;
            }
            else{
                ll pre[205][2];
                memset(pre,0,sizeof(pre));
                for(int i=1;i<=200;i++){
                    (pre[i][0]=dp[i][0]+pre[i-1][0])%=MOD;
                    (pre[i][1]=dp[i][1]+pre[i-1][1])%=MOD;
                }
                for(int i=1;i<=200;i++){
                    (temp[i][0]=pre[i-1][0]+pre[i-1][1])%=MOD;
                    (temp[i][1]=MOD+dp[i][0]+dp[i][1]+pre[200][1]-pre[i][1])%=MOD;
                }
            }
            for(int j=1;j<=200;j++)
                dp[j][0]=temp[j][0],dp[j][1]=temp[j][1];
        }
        ll ans=0;
        for(int i=1;i<=200;i++)
            (ans+=dp[i][1])%=MOD;
        cout<<ans;
    }
}
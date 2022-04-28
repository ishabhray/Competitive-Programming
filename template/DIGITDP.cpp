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

ll dp[10000][100][2];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int te=1;
    // cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        string k;
        int d;
        cin>>k>>d;
        int n=k.size();
        for(int i=0;i<n;i++){
            int c=k[i]-'0';
            for(int j=0;j<10;j++){
                if(i==0){
                    if(j>c) break;
                    else if(j==c) dp[0][j%d][0]++;
                    else dp[0][j%d][1]++;
                    continue;
                }
                // cout<<j<<'\n';
                for(int k=0;k<d;k++){
                    if(j>c) (dp[i][(k+j)%d][1]+=dp[i-1][k][1])%=MOD;
                    else if(j==c){
                        (dp[i][(k+j)%d][1]+=dp[i-1][k][1])%=MOD;
                        (dp[i][(k+j)%d][0]+=dp[i-1][k][0])%=MOD;
                    }
                    else{
                        (dp[i][(k+j)%d][1]+=dp[i-1][k][1])%=MOD;
                        (dp[i][(k+j)%d][1]+=dp[i-1][k][0])%=MOD;
                    }
                }
                // for(int k=0;k<d;k++) cout<<dp[i][k][0]<<' '<<dp[i][k][1]<<'\n';
            }
            // cout<<'\n';
        }
        cout<<(dp[n-1][0][0]+dp[n-1][0][1]-1+MOD)%MOD<<'\n';
    }
}
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
int dp[1000005][21][2];
ll f(int n,int x,int y){
    int z=(1<<x);
    if(y)
        z*=3;
    return n/z;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int te=1,MOD=1e9+7;
    //cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        int n;
        cin>>n;
        int x=log2(n);
        dp[1][x][0]=1;
        if((1<<(x-1))*3<=n)
            dp[1][x-1][1]=1;
        for(int i=1;i<n;i++){
            for(int j=x;j>=0;j--){
                for(int k=1;k>=0;k--){
                    dp[i+1][j][k]=(dp[i+1][j][k]+(ll)dp[i][j][k]*(f(n,j,k)-i))%MOD;
                    if(j)
                        dp[i+1][j-1][k]=(dp[i+1][j-1][k]+(ll)dp[i][j][k]*(f(n,j-1,k)-f(n,j,k)))%MOD;
                    if(k)
                        dp[i+1][j][k-1]=(dp[i+1][j][k-1]+(ll)dp[i][j][k]*(f(n,j,k-1)-f(n,j,k)))%MOD;
                }
            }
        }
        cout<<dp[n][0][0];
    }
}
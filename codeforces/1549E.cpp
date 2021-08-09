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
#define MOD 1000000007
int power(int a, int b){//a^b
    int res=1;
    while(b>0){
        if(b&1){res=((ll)res*a)%MOD;b--;}
        a=((ll)a*a)%MOD;
        b>>=1;
    }
    return res;
}
int fermat_inv(int y){return power(y,MOD-2);}
int fact[3000010];
int finv[3000010];
void factorial(int n){
    fact[0]=1;
    finv[0]=1;
    for(int i=1;i<=n;i++)
        fact[i]=((ll)fact[i-1]*(ll)i)%MOD,finv[i]=fermat_inv(fact[i]);
}
int ncr(int n,int r)
{
    if(n<r)
        return 0;
    else{
        ll x=finv[r];
        x*=finv[n-r];
        x%=MOD;
        x*=fact[n];
        return x%MOD;
    }
}
ll dp[3000005][3];
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
    factorial(3000005);
    while(te--){
        ll n,q;
        cin>>n>>q;
        dp[0][0]=dp[0][1]=dp[0][2]=n;
        for(int i=1;i<=3*n;i++){
            dp[i][0]=(ncr(3*n,i+1)-2*dp[i-1][0]-dp[i-1][1])%MOD;
            dp[i][0]+=MOD;
            dp[i][0]%=MOD;
            (dp[i][0]*=fermat_inv(3))%=MOD;
            dp[i][1]=(dp[i-1][0]+dp[i][0])%MOD;
            dp[i][2]=(dp[i-1][1]+dp[i][1])%MOD;
            // cout<<dp[i][0]<<' '<<dp[i][1]<<' '<<dp[i][2]<<'\n';
        }
        for(int i=0;i<q;i++){
            int x;
            cin>>x;
            ll ans=(dp[x][0]+ncr(3*n,x))%MOD;
            cout<<ans<<'\n';
        }
    }
}
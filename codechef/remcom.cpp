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
ll power(ll a, ll b,ll MOD){//a^b
    ll res=1;
    a=a%MOD;
    while(b>0){
        if(b&1){res=(res*a)%MOD;b--;}
        a=(a*a)%MOD;
        b>>=1;
    }
    return res;
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
    //cin>>t;
    //SieveOfEratosthenes(1000000);
    //factorial(1000);
    while(t--){
        string s;
        cin>>s;
        ll n=s.size();
        ll dp[n][13];
        reverse(s.begin(),s.end());
        for(ll i=0;i<n;i++){
            for(ll j=0;j<13;j++){
                dp[i][j]=0;
                if(!i&&(s[i]=='?'&&j<10||s[i]!='?'&&j==s[i]-48))
                    dp[i][j]++;
            }
        }
        for(ll i=1;i<n;i++){
            for(ll j=0;j<13;j++){
                if(s[i]=='?'){
                    for(ll k=0;k<10;k++){
                        dp[i][(k*power(10,i,13)+j)%13]+=dp[i-1][j];
                        dp[i][(k*power(10,i,13)+j)%13]%=MOD;
                    }
                }
                else{
                    dp[i][((s[i]-48)*power(10,i,13)+j)%13]+=dp[i-1][j];
                    dp[i][((s[i]-48)*power(10,i,13)+j)%13]%=MOD;
                }
            }
        }
        cout<<dp[n-1][5];
    }
}
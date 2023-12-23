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
int dp[2005][2005],n;
string s;
// 1 if Alice
// 0 if Draw
// -1 if Bob
int f(int i,int j){
    if(j==i+1){
        if(s[i]==s[j]) return dp[i][j]=0;
        else return dp[i][j]=1;
    }
    if(dp[i][j]!=-2) return dp[i][j];
    int x=f(i+2,j),y=f(i+1,j-1),z=f(i,j-2);
    if(x==0){
        if(s[i]<s[i+1]) x=1;
        else if(s[i]>s[i+1]) x=-1;
    }
    if(z==0){
        if(s[j]<s[j-1]) z=1;
        else if(s[j]>s[j-1]) z=-1;
    }
    if(y==-1) return dp[i][j]=-1;
    if(y==1){
        return dp[i][j]=max(x,z);
    }
    if(y==0){
        int p=0,q=0;
        if(s[i]<s[j]) p=1,q=-1;
        else if(s[i]>s[j]) p=-1,q=1;
        if(p==-1&&q==-1) return dp[i][j]=-1;
        if(p==-1) return dp[i][j]=min(q,z);
        if(q==-1) return dp[i][j]=min(p,x);
        if(x==-1&&z==-1) return dp[i][j]=-1;
        if(x==-1) return dp[i][j]=min(z,q);
        if(y==-1) return dp[i][j]=min(x,p);
        if(p&&x) return dp[i][j]=1;
        if(q&&y) return dp[i][j]=1;
        return dp[i][j]=0;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int te=1;
    cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        cin>>s;
        n=s.size();
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) dp[i][j]=-2;
        int x=f(0,n-1);
        if(x==1) cout<<"Alice\n";
        else if(x==0) cout<<"Draw\n";
        else cout<<"Bob\n";
    }
}
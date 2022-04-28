#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000007
#define MAXN 305
struct mi {
 	int v; explicit operator int() const { return v; } 
	mi():v(0) {}
	mi(ll _v):v(int(_v%MOD)) { v += (v<0)*MOD; }
};
mi& operator+=(mi& a, mi b) { 
	if ((a.v += b.v) >= MOD) a.v -= MOD; 
	return a; }
mi& operator-=(mi& a, mi b) { 
	if ((a.v -= b.v) < 0) a.v += MOD; 
	return a; }
mi operator+(mi a, mi b) { return a += b; }
mi operator-(mi a, mi b) { return a -= b; }
mi operator*(mi a, mi b) { return mi((ll)a.v*b.v); }
mi& operator*=(mi& a, mi b) { return a = a*b; }
mi pow(mi a, ll p) { assert(p >= 0); // won't work for negative p
	return p==0?1:pow(a*a,p/2)*(p&1?a:1); }
mi inv(mi a) { assert(a.v != 0); return pow(a,MOD-2); }
mi operator/(mi a, mi b) { return a*inv(b); }
bool operator==(mi a, mi b) { return a.v == b.v; }

mi c[MAXN][MAXN];
mi f[MAXN];
mi fn(int n,int m,int l){
    mi dp[n+5][n+5];
    mi finv=inv(mi(2));
    for(int i=0;i<=n;i++) for(int j=0;j<=m;j++) dp[i][j]=0;
    dp[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<=m;j++){
            dp[i+1][j]+=dp[i][j];
            if(2<=l&&i+2<=n&&j+2<=m) dp[i+2][j+2]+=dp[i][j]*(n-i-1);
            for(int k=3;k<=l&&i+k<=n&&j+k<=m;k++) dp[i+k][j+k]+=dp[i][j]*c[n-i-1][k-1]*f[k-1]*finv;
            for(int k=2;k<=l&&i+k<=n&&j+k-1<=m;k++) dp[i+k][j+k-1]+=dp[i][j]*c[n-1-i][k-1]*f[k]*finv;
        }
    }
    return dp[n][m];
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
    // cin>>te;
    //SieveOfEratosthenes(1000000);
    while(te--){
        c[0][0]=1;
        f[0]=1;
        for(int i=1;i<MAXN-1;i++) f[i]=mi(i)*f[i-1];
        for(int i=0;i<MAXN-1;i++){
            for(int j=0;j<MAXN-1;j++) c[i+1][j]+=c[i][j],c[i+1][j+1]+=c[i][j];
        }
        int n,m,l;
        cin>>n>>m>>l;
        cout<<(fn(n,m,l)-fn(n,m,l-1)).v<<'\n';
    }
}
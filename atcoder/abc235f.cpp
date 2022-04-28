#include <bits/stdc++.h>
using namespace std;

#define PI 3.141592653589
#define ll long long int
#define ld long double
#define vi vector<int>
#define vl vector<mi>
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


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int te=1;
    while(te--){
        string k;
        int m;
        cin>>k>>m;
        int flag[10]={0};
        vv<vl>dp(1025,vl(2,0));
        vv<vl>cnt(1025,vl(2,0));
        for(int i=0;i<m;i++){
            int x;
            cin>>x;
            flag[x]++;
        }
        int n=k.size();
        for(int i=0;i<n;i++){
            int c=k[i]-'0';
            vv<vl>ndp(1025,vl(2,0));
            vv<vl>ncnt(1025,vl(2,0));
            for(int j=0;j<10;j++){
                if(i==0){
                    if(j>c) break;
                    else if(j==c) ndp[(1<<j)][0]+=j,ncnt[(1<<j)][0]+=1;
                    else if(j) ndp[(1<<j)][1]+=j,ncnt[(1<<j)][1]+=1;
                    else ncnt[0][1]+=1;
                    continue;
                }
                for(int k=0;k<(1<<10);k++){
                    if(j==0&&k==0) {ncnt[0][1]+=1; continue;}
                    int z=(k|(1<<j));
                    if(j>c) ndp[z][1]+=dp[k][1]*10+j*cnt[k][1],ncnt[z][1]+=cnt[k][1];
                    else if(j==c){
                        ndp[z][1]+=dp[k][1]*10+j*cnt[k][1],ncnt[z][1]+=cnt[k][1];
                        ndp[z][0]+=dp[k][0]*10+j*cnt[k][0],ncnt[z][0]+=cnt[k][0];
                    }
                    else{
                        ndp[z][1]+=dp[k][1]*10+j*cnt[k][1],ncnt[z][1]+=cnt[k][1];
                        ndp[z][1]+=dp[k][0]*10+j*cnt[k][0],ncnt[z][1]+=cnt[k][0];
                    }
                }
            }
            swap(dp,ndp);
            swap(cnt,ncnt);
            // for(int j=0;j<(1<<3);j++){
            //     cout<<dp[j][0]<<' '<<dp[j][1]<<' '<<cnt[j][0]<<' '<<cnt[j][1]<<'\n';;
            // }
            // cout<<'\n';
        }
        int mask=0;
        for(int i=0;i<10;i++){
            if(flag[i]) mask|=(1<<i);
        }
        mi ans=0;
        for(int i=0;i<(1<<10);i++){
            if((i&mask)==mask) ans+=dp[i][0]+dp[i][1];
        }
        cout<<ans.v<<'\n';
    }
}
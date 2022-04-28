#include <bits/stdc++.h>
using namespace std;

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
using cd = complex<double>;
const double PI = acos(-1);
 
void fft(vector<cd> & a, bool invert) {
    int n = a.size();
 
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;
 
        if (i < j)
            swap(a[i], a[j]);
    }
 
    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }
 
    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}
void fft2d(vv<vv<cd>>&a,bool inv){
    for(auto &i:a) fft(i,inv);
    for(int j=0;j<a[0].size();j++){
        vv<cd>col;
        for(int i=0;i<a.size();i++) col.pb(a[i][j]);
        fft(col,inv);
        for(int i=0;i<a.size();i++) a[i][j]=col[i];
    }
}
vv<vv<cd>> mult(vv<vv<cd>> &a,vv<vv<cd>> &b){
    int n=1,m=1;
    while(n<2*max(a.size(),b.size())) n<<=1;
    while(m<2*max(a[0].size(),b[0].size())) m<<=1;
    a.resize(n);
    b.resize(n);
    for(auto &i:a) i.resize(m);
    for(auto &i:b) i.resize(m);
    fft2d(a,0);
    fft2d(b,0);
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) a[i][j]*=b[i][j];
    fft2d(a,true);
    return a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    int te=1;
    while(te--){
        int n,m,r,c,l=0;
        cin>>n>>m;
        string s[n];
        for(int i=0;i<n;i++) cin>>s[i];
        cin>>r>>c;
        string t[r];
        for(int i=0;i<r;i++) cin>>t[i];
        vv<vv<cd>>a(n+r,vv<cd>(m+c,0)),b(r,vv<cd>(c,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                double theta=2*PI/26*(s[i][j]-'a'+1);
                a[i][j]=cd(cos(theta),sin(theta));
                for(int x=i;x<n+r;x+=n) for(int y=j;y<m+c;y+=m) a[x][y]=a[i][j];
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(t[i][j]=='?') continue;
                l++;
                double theta=2*PI/26*(t[i][j]-'a'+1);
                b[r-i-1][c-1-j]=cd(cos(theta),-sin(theta));
            }
        }
        // if(s[0][0]=='l') cout<<l<<'\n';
        auto res=mult(a,b);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                double x=res[r+i-1][c+j-1].real(),y=0;
                if(abs(x-l)<1e-6) y=1;
                // if(s[0][0]=='l') cout<<x<<' ';
                // else cout<<y;
                cout<<y;
            }
            cout<<'\n';
        }
    }
}

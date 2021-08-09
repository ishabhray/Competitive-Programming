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
 
vi mult(vi &a,vi &b){
    int n=1;
    while(n<2*max(a.size(),b.size())) n<<=1;
    vv<cd>A(all(a)),B(all(b));
    A.resize(n);
    B.resize(n);
    fft(A,false);
    fft(B,false);
    vv<cd>C(n);
    for(int i=0;i<n;i++) C[i]=A[i]*B[i];
    fft(C,true);
    vi ans(n);
    for(int i=0;i<n;i++) ans[i]=round(C[i].real());
    return ans;
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
        int n;
        string s;
        cin>>n>>s;
        vi a(n),b(n),c(n),d(n);
        for(int i=0;i<n;i++){
            if(s[i]=='V')
                a[i]=c[n-i-1]=1;
            else if(s[i]=='K')
                d[i]=b[n-i-1]=1;
        }
        vi x=mult(a,b);
        vi y=mult(c,d);
        vi ans;
        for(int i=1;i<=n;i++){
            bool f=true;
            for(int j=i;j<=n;j+=i){
                if(x[j+n-1]||y[j+n-1]){
                    f=false;
                    break;
                }
            }
            if(f)
                ans.pb(i);
        }
        cout<<ans.size()<<'\n';
        for(int i:ans)
            cout<<i<<' ';
        cout<<'\n';
    }
}
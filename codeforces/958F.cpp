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

vl mult(vl &a,vl &b){
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
    vl ans(n);
    for(int i=0;i<n;i++) ans[i]=(ll)round(C[i].real())%1009;
    return ans;
}
bool comp(const vl &l,const vl &r){
    if(l.size()>r.size())
        return 1;
    return 0;
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
    //factorial(1000005);
    while(te--){
        int n,m,k;
        cin>>n>>m>>k;
        int cnt[m+1]={0};
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            cnt[x]++;
        }
        // priority_queue<vl,vv<vl>,decltype(&comp)>q(comp);
        queue<vl>q;
        for(int i=1;i<=m;i++){
            if(cnt[i]){
                vl v(cnt[i]+1,1);
                q.push(v);
            }
        }
        while(q.size()>1){
            vl a=q.front();
            q.pop();
            vl b=q.front();
            q.pop();
            q.push(mult(a,b));
        }
        cout<<q.front()[k]%1009<<'\n';
    }
}
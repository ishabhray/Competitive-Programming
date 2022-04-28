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
#define MAXN 1000005

vv<vi>s,h;
int p[MAXN],sz[MAXN],mx[MAXN],n,m;
int get(int a){
    return p[a]=(p[a]==a)? a:get(p[a]);
}
void uni(int a,int b,bool f){
    a=get(a);
    p[b]=a;
    sz[a]+=1;
    if(f) mx[a]=max(mx[a],mx[b]);
}
void uni(int x,int y,int a,int b){
    x=get(x*m+y);
    if(mx[x]>=h[a][b]) return;
    if(s[a][b]>=h[a][b]){
        uni(x*m+y,a*m+b,0);
    }
    else{

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
    for(int T=1;T<=te;T++){
        cin>>n>>m;
        s.assign(n,vi(m));
        h.assign(n,vi(m));
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>h[i][j];
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>s[i][j];
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) p[i*m+j]=i*m+j,sz[i*m+j]=1,mx[i*m+j]=s[i][j];
        int x=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(s[i][j]<h[i][j]) x++;
                if(i) uni(i-1,j,i,j);
                if(j) uni(i,j-1,i,j);
            }
        }
        set<int>y;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(s[i][j]<h[i][j]){
                    x++;
                    y.insert(get(i*m+j));
                }
            }
        }
        cout<<"Case #"<<T<<": "<<x<<' '<<y.size()<<'\n';
    }
}
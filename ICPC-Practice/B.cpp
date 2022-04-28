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
char ans[25][25];
int n,m;
void fill12(int i,int j){
    char c='A';
    set<char>s;
    if(j){
        s.insert(ans[i][j-1]);
    }
    if(j+2<m){
        s.insert(ans[i][j+2]);
    }
    if(i){
        s.insert(ans[i-1][j]);
        s.insert(ans[i-1][j+1]);
    }
    if(i+1<n){
        s.insert(ans[i+1][j]);
        s.insert(ans[i+1][j+1]);
    }
    while(s.find(c)!=s.end()) c++;
    ans[i][j]=ans[i][j+1]=c;
}
void fill21(int i,int j){
    char c='A';
    set<char>s;
    if(j){
        s.insert(ans[i][j-1]);
        s.insert(ans[i+1][j-1]);
    }
    if(j+1<m){
        s.insert(ans[i][j+1]);
        s.insert(ans[i+1][j+1]);
    }
    if(i){
        s.insert(ans[i-1][j]);
    }
    if(i+2<n){
        s.insert(ans[i+2][j]);
    }
    while(s.find(c)!=s.end()) c++;
    ans[i][j]=ans[i+1][j]=c;
}
void fill13(int i,int j){
    char c='A';
    set<char>s;
    if(j){
        s.insert(ans[i][j-1]);
    }
    if(j+3<m){
        s.insert(ans[i][j+3]);
    }
    if(i){
        s.insert(ans[i-1][j]);
        s.insert(ans[i-1][j+1]);
        s.insert(ans[i-1][j+2]);
    }
    if(i+1<n){
        s.insert(ans[i+1][j]);
        s.insert(ans[i+1][j+1]);
        s.insert(ans[i+1][j+2]);
    }
    while(s.find(c)!=s.end()) c++;
    ans[i][j]=ans[i][j+1]=ans[i][j+2]=c;
}
void fill31(int i,int j){
    char c='A';
    set<char>s;
    if(j){
        s.insert(ans[i][j-1]);
        s.insert(ans[i+1][j-1]);
        s.insert(ans[i+2][j-1]);
    }
    if(j+1<m){
        s.insert(ans[i][j+1]);
        s.insert(ans[i+1][j+1]);
        s.insert(ans[i+2][j+1]);
    }
    if(i){
        s.insert(ans[i-1][j]);
    }
    if(i+3<n){
        s.insert(ans[i+3][j]);
    }
    while(s.find(c)!=s.end()) c++;
    ans[i][j]=ans[i+1][j]=ans[i+2][j]=c;
}
void fill_row(int i,int j,int x){
    if((x-j+1)%2==0){
        for(int k=j;k<x;k+=2) fill12(i,k);
    }
    else{
        fill13(i,j);
        j+=3;
        for(int k=j;k<x;k+=2) fill12(i,k);
    }
}
void fill_col(int i,int j,int x){
    if((x-i+1)%2==0){
        for(int k=i;k<x;k+=2) fill21(k,j);
    }
    else{
        fill31(i,j);
        i+=3;
        for(int k=i;k<x;k+=2) fill21(k,j);
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
        int x,y;
        cin>>n>>m>>x>>y;
        x--,y--;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) ans[i][j]='$';
        }
        ans[x][y]='*';
        if(!y||y==m-1){
            for(int i=0;i<n;i++){
                if(i==x) continue;
                fill_row(i,0,m-1);
            }
            if(!y) fill_row(x,1,m-1);
            else fill_row(x,0,m-2);
        }
        else if(!x||x==n-1){
            for(int i=0;i<m;i++){
                if(i==y) continue;
                fill_col(0,i,n-1);
            }
            if(!x) fill_col(1,y,n-1);
            else fill_col(0,y,n-2);
        }
        else{
            for(int i=0;i<x;i++) fill_row(i,0,y);
            for(int i=y+1;i<m;i++) fill_col(0,i,x);
            for(int i=x+1;i<n;i++) fill_row(i,y,m-1);
            for(int i=0;i<y;i++) fill_col(x,i,n-1);
        }
        cout<<"YES\n";
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<ans[i][j];
            }
            cout<<'\n';
        }
    }
}
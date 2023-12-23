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
#define MAXN 1005

int p[MAXN];
int get(int a){
    if(p[a]==a) return a;
    if(p[a]<0) return p[a]=-get(-p[a]);
    return p[a]=get(p[a]);
}
bool uni(int a,int b){
    a=get(a);
    b=get(b);
    if(a==b) return true;
    if(a==-b) return false;
    if(a<0) p[-a]=-b;
    else p[a]=b;
    return true;
}
bool disuni(int a,int b){
    a=get(a);
    b=get(b);
    if(a==b) return false;
    if(a==-b) return true;
    if(a<0) p[-a]=b;
    else p[a]=-b;
    return true;
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
        cin>>n;
        int a[n][n];
        for(int i=0;i<n;i++) p[i]=i;
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>a[i][j];
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(a[i][j]==a[j][i]) continue;
                else if(a[i][j]<a[j][i]){
                    if(!uni(i,j)) swap(a[i][j],a[j][i]);
                }
                else{
                    if(disuni(i,j)) swap(a[i][j],a[j][i]);
                }
                // cout<<i<<' '<<j<<": ";
                // for(int k=0;k<n;k++) cout<<p[k]<<' ';
                // cout<<'\n';
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) cout<<a[i][j]<<' ';
            cout<<'\n';
        }
    }
}
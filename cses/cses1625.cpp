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
string s;
int vis[7][7];
int mvR(int i,int j,int c){
    if(j==6||vis[i][j+1]||i&&!vis[i-1][j]&&i<6&&!vis[i+1][j])
        return 0;
    if()
}

int solve(int i,int j,int c){
    int ans=0;
    if(i==6&&j==0){
        if(c!=48)
            return 0;
        else
            return 1;
    }
    vis[i][j]=1;
    if(s[c]=='R'||s[c]=='?')
        ans+=mvR(i,j,c);
    if(s[c]=='L'||s[c]=='?')
        ans+=mvL(i,j,c);
    if(s[c]=='U'||s[c]=='?')
        ans+=mvU(i,j,c);
    if(s[c]=='D'||s[c]=='?')
        ans+=mvD(i,j,c);
    vis[i][j]=0;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int te=1;
    //cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        cin>>s;
    }
}
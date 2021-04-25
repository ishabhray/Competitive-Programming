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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t=1;
    //cin>>t;
    //SieveOfEratosthenes(1000000);
    //factorial(1000);
    while(t--){
        ll n,m,p;
        cin>>n>>m>>p;
        int ans[n][m],s[p+1];
        for(int i=1;i<=p;i++)
            cin>>s[i];
        queue<pair<ii,int> >q[p+1];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                char ch;
                cin>>ch;
                if(ch=='#')
                    ans[i][j]=-1;
                else if(ch=='.')
                    ans[i][j]=0;
                else
                    ans[i][j]=ch-48;
                if(ans[i][j]>0)
                    q[ans[i][j]].push({{i,j},s[ans[i][j]]});
            }
        }
        queue<pair<ii,int> >t;
        while(1){
            bool b=true;
            for(int i=1;i<=p;i++){
                //cout<<i<<'\n';
                if(!q[i].empty())
                    b=false;
                
                while(!q[i].empty()){
                    auto a=q[i].front();
                    q[i].pop();
                    int x=a.ff.ff,y=a.ff.ss,r=a.ss;
                    //cout<<x<<' '<<y<<' '<<r<<'\n';
                    if(r==0){
                        t.push({{x,y},s[i]});
                        continue;
                    }
                    if(x>0&&!ans[x-1][y]){
                        ans[x-1][y]=i;
                        q[i].push({{x-1,y},r-1});
                    }
                    if(x<n-1&&!ans[x+1][y]){
                        ans[x+1][y]=i;
                        q[i].push({{x+1,y},r-1});
                    }
                    if(y>0&&!ans[x][y-1]){
                        ans[x][y-1]=i;
                        q[i].push({{x,y-1},r-1});
                    }
                    if(y<m-1&&!ans[x][y+1]){
                        ans[x][y+1]=i;
                        q[i].push({{x,y+1},r-1});
                    }
                }
                while(!t.empty()){
                    q[i].push(t.front());
                    t.pop();
                }
            }
            if(b)
                break;
        }
        map<int,int>k;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                k[ans[i][j]]++;
        for(int i=1;i<=p;i++)
            cout<<k[i]<<' ';
    }
}
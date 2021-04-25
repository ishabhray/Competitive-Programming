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
int MOD=1e9+7;

ll min(ll a,ll b){return (a>b)?b:a;}
ll max(ll a,ll b){return (a>b)?a:b;}

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
    //factorial(100005);
    while(te--){
        int n,m;
        cin>>n>>m;
        int sx,sy;
        int vis[n][m][4];
        char a[n][m];
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                for(int k=0;k<4;k++)
                    vis[i][j][k]=100;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
                if(a[i][j]=='S')
                    sx=i,sy=j;
            }
        }
        ii moves[4]={{1,0},{-1,0},{0,1},{0,-1}};
        ii notposs[4]={{0,1},{1,0},{2,3},{3,2}};
        vis[sx][sy][0]=vis[sx][sy][1]=vis[sx][sy][2]=vis[sx][sy][3]=0;
        queue< pair<ii,int> >q;
        q.push({{sx,sy},0});
        q.push({{sx,sy},1});
        q.push({{sx,sy},2});
        q.push({{sx,sy},3});
        while(!q.empty()){
            auto b=q.front();
            q.pop();
            int x=b.ff.ff,y=b.ff.ss,dir=b.ss;
            //cout<<x<<' '<<y<<' '<<dir<<' '<<vis[x][y]<<'\n';
            if(a[x][y]=='T'){
                cout<<"YES";
                return 0;
            }
            for(int i=0;i<4;i++){
                bool b=false;
                for(auto j:notposs){
                    if(dir==j.ff&&i==j.ss){
                        b=true;
                        break;
                    }
                }
                if(b)
                    continue;
                int dx=moves[i].ff,dy=moves[i].ss;
                if(x+dx<0||x+dx>=n||y+dy<0||y+dy>=m||a[x+dx][y+dy]=='*')
                    continue;
                if(dir==i){
                    if(vis[x+dx][y+dy][i]>vis[x][y][dir]){
                        vis[x+dx][y+dy][i]=vis[x][y][dir];
                        q.push({{x+dx,y+dy},i});
                    }
                }
                else if(vis[x][y][dir]<2){
                    if(vis[x+dx][y+dy][i]>vis[x][y][dir]+1){
                        vis[x+dx][y+dy][i]=vis[x][y][dir]+1;
                        q.push({{x+dx,y+dy},i});
                    }
                }
            }
        }
        cout<<"NO";
    }
}
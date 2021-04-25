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
 
ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}
ll min(ll a,ll b){return (a>b)?b:a;}
ll max(ll a,ll b){return (a>b)?a:b;}
 
int dist[1005][1005],vis[1005][1005];
char back[1005][1005];
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
        queue<ii>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
            	dist[i][j]=vis[i][j]=1e7;
            	char a;
                cin>>a;
                if(a=='A')
                    sx=i,sy=j;
                else if(a=='M'){
                    q.push({i,j});
                    dist[i][j]=0;
                }
                else if(a=='#')
                    dist[i][j]=0;
            }
        }
        ii moves[4]={{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty()){
            auto a=q.front();
            q.pop();
            for(auto i:moves){
                int x=a.ff+i.ff,y=a.ss+i.ss,d=dist[a.ff][a.ss];
                if(x<0||x>=n||y<0||y>=m||dist[x][y]<=d+1)
                    continue;
                dist[x][y]=d+1;
                q.push({x,y});
            }
        }
        int fx=-1,fy=-1;
        q.push({sx,sy});
        vis[sx][sy]=0;
        
        while(!q.empty()){
            auto a=q.front();
            int x=a.ff,y=a.ss;
            q.pop();
            if(x==0||x==n-1||y==0||y==m-1){
                fx=x,fy=y;
                break;
            }
            for(auto i:moves){
                int dx=x+i.ff,dy=y+i.ss;
                if(dx<0||dx>=n||dy<0||dy>=m||dist[dx][dy]<=vis[x][y]+1||vis[dx][dy]<=vis[x][y]+1)
                    continue;
                if(i.ff==1)
                    back[dx][dy]='D';
                if(i.ff==-1)
                    back[dx][dy]='U';
                if(i.ss==1)
                    back[dx][dy]='R';
                if(i.ss==-1)
                    back[dx][dy]='L';
                vis[dx][dy]=vis[x][y]+1;
                q.push({dx,dy});
            }
        }
        if(fx==-1&&fy==-1)
            cout<<"NO";
        else{
            cout<<"YES\n";
            int x=fx,y=fy;
            deque<char>ans;
            while(x!=sx||y!=sy){
                ans.push_front(back[x][y]);
                if(back[x][y]=='D')
                    x--;
                else if(back[x][y]=='U')
                    x++;
                else if(back[x][y]=='R')
                    y--;
                else
                    y++;
            }
            cout<<ans.size()<<'\n';
            for(auto i:ans)
                cout<<i;
        }
    }
}
#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define pii pair<int, int>
#define vi vector<int>
#define mii map<int, int>
#define mod7 1000000007
#define test(t) int t; cin>>t; while(t--)
#define setp(x, y) fixed << setprecision(y) << x
#define fast_io std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
int n,e;
int vis[1005];
vi ad[1005];
int low[1005];
int in[1005];
int timer;
set<int>s;
void dfs(int u,int p){
    in[u]=low[u]=timer++;
    vis[u]=1;
    int child=0;
    for(auto i:ad[u]){
        if(i==p){
            continue;
        }
        if(vis[i]){
            low[u]=min(low[u],in[i]);
        }
        else{
            dfs(i,u);
            low[u]=min(low[u],low[i]);
            if(low[i]>=in[u] && p!=-1){
                s.insert(u);
            }
            child++;
        }
    }
    if(p==-1 && child>1){
        s.insert(u);
    }
}
signed main()
{
    fast_io;
    cin>>n>>e;
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        ad[x].pb(y);
        ad[y].pb(x);
    }
    dfs(1,-1);
    for(auto i:s){
        cout<<i<<endl;
    }
    
   
    
    



}
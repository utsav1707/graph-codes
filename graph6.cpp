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
int vis[10005];
vi ad[10005];
int dis,mxn;
void dfs(int u,int d){
vis[u]=1;
if(d>dis){
    dis=d;
    mxn=u;
}
for(auto i: ad[u]){
    if(!vis[i]){
        dfs(i,1+d);
    }
}	
}
signed main()
{
    fast_io;
    cin>>n;
    e=n-1;
    for(int i=0;i<e;i++){
    	int x,y;
    	cin>>x>>y;
    	ad[x].pb(y);
    	ad[y].pb(x);
    }
    dis=-1;
    dfs(1,0);
    for(int i=0;i<=n;i++){
        vis[i]=0;
    }
    dfs(mxn,0);
    cout<<dis<<endl;
    



}
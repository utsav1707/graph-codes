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
vector<int>ad[1005];
int h[1005];
int par[1005];
int vis[1005];
void dfs(int u,int v){
h[u]=1+h[v];
par[u]=v;
for(auto i:ad[u]){
if(i!=v){
dfs(i,u);
}
}
}
int lca(int a,int b){
	if(h[a]<h[b]){
		swap(a,b);
	}
	int d=h[a]-h[b];
	while(d){
		a=par[a];
		d--;
	}
	while(a!=b){
		a=par[a];
		b=par[b];
	}
	return a;
}
signed main()
{
    fast_io;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
    	int x,y;
    	cin>>x>>y;
    	ad[x].pb(y);
    	ad[y].pb(x);
    }
    dfs(1,0);
    cout<<lca(4,6);


}
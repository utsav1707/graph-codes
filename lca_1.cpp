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
int lev[1005];
const int mxn=10;
int lca[1005][mxn+1];
vector<int>ad[1005];
void dfs(int u,int lvl,int p){
	lev[u]=lvl;
	lca[u][0]=p;
	for(auto i:ad[u]){
		if(i!=p){
			dfs(i,lvl+1,u);
		}
	}
}
void build(int n){
	dfs(1,0,-1);
	for(int i=1;i<=mxn;i++){
		for(int j=1;j<=n;j++){
			if(lca[j][i-1]!=-1){
				int node=lca[j][i-1];
				lca[j][i]=lca[node][i-1];
			}
		}
	}

}
int getlca(int a,int b){
	if(lev[a]<lev[b]){
		swap(a,b);
	}
	int d=lev[a]-lev[b];
	while(d>0){
		int jump=log2(d);
		a=lca[a][jump];
		d-=1<<jump;
	}
	if(a==b) return a;
	for(int i=mxn;i>=0;i--){
		if(lca[a][i]!=-1 && (lca[a][i]!=lca[b][i])){
			a=lca[a][i];
			b=lca[b][i];
		}
	}
	return lca[a][0];
}
int dist(int a,int b){
	int lc=getlca(a,b);
	return lev[a]+lev[b]-2*lev[lc];
}
signed main()
{
    fast_io;
    int n;cin>>n;
    for(int i=1;i<=n-1;i++){
    	int x,y;
    	cin>>x>>y;
    	ad[x].pb(y);
    	ad[y].pb(x);
    }
    for(int i=0;i<=mxn;i++){
    	for(int j=0;j<=n;j++){
    		lca[j][i]=-1;
    	}
    }
    build(n);

    int q;cin>>q;
    while(q--){
    	int x,y;
    	cin>>x>>y;
    	cout<<getlca(x,y)<<" ";
    	cout<<dist(x,y)<<endl;
    }



}
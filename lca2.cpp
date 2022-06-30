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
void dfs(int u,int v){
	lc[u][0]=v;
	for(int i:ad[u]){
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
		int jump=log2(d);
		a=lc[a][jump];
		d-=(1<<jump);
	}
	for(int i=mxn;i>=0;i--){
		if(lc[a][i]!=-1 && lc[a][i]!=lc[b][i]){
			a=lc[a][i];
			b=lc[b][i];
		}
	}
	return lc[a][0];
}
void buil(){
	dfs(1,-1);
	for(int j=1;j<=mxn;j++){
		for(int i=1;i<=n;i++){
			if(lca[i][j-1]!=-1){
				int nod=lca[i][j-1];
				lc[i][j]=lc[nod][j-1];
			}
		}
	}
}
signed main()
{
    fast_io;



}
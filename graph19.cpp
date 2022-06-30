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
vi ad[1005];
int lev[1005];
int mx=10;
int lca[1005][11];
void dfs(int u,int h,int p){
	lev[u]=h;
	lca[u][0]=p;
	for(auto i:ad[u]){
		if(i!=p){
			dfs(i,h+1,u);
		}
	}
}
void init(int n){
	dfs(1,0,-1);
	for(int i=1;i<=mx;i++){
		for(int j=1;j<=n;j++){
			if(lca[j][i-1]!=-1){
				int par=lca[j][i-1];
				lca[j][i]=lca[par][i-1];
			}
		}

	}
}
int getlca(int a,int b){
	if(lev[b]<lev[a]){
		swap(a,b);
	}
	int d=lev[b]-lev[a];
	while(d>0){
		int i=log2(d);
		b=lca[b][i];
		d-=1<<i;

	}
	if(a==b){
		return a;
	}
	for(int i=mx;i>=0;i--){
		if(lca[a][i]!=-1 && lca[a][i]!=lca[b][i]){
			a=lca[a][i];
			b=lca[b][i];
		}
	}
	return lca[a][0];
}

int getdis(int a,int b){
	int lca=getlca(a,b);
	return lev[a]+lev[b]-2*lev[lca]; 
}


signed main()
{
    fast_io;
    memset(lca,-1,sizeof(lca));
    int n,a,b;
    cin>>n;
    for(int i=1;i<n;i++){
    	cin>>a>>b;
    	ad[a].pb(b);
    	ad[b].pb(a);
    }
    init(n);
    test(t){
    	int x,y;
    	cin>>x>>y;
    	cout<<getdis(x,y)<<endl;
    }



}
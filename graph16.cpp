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
int par[100005];
vector<pair<pair<int,int>,int>>v;
bool camp(pair<pair<int,int>,int>p1,pair<pair<int,int>,int>p2){
return p1.ss<p2.ss;
}
int find(int a){
    if(par[a]==-1) return a;
    return par[a]=find(par[a]);
}
void merge(int a,int b){
    par[a]=b;
}
signed main()
{
    fast_io;
    int n,m,a,b,w;
    cin>>n>>m;
    for(int i=0;i<m;i++){
    	cin>>a>>b>>w;
    	v.pb({{a,b},w});
    }
    sort(all(v),camp);
    int sum=0;
    for(int i=1;i<=n;i++){
        par[i]=-1;
    }
    for(int i=0;i<m;i++){
    a=find(v[i].ff.ff);
    b=find(v[i].ff.ss);
    if(a!=b){
        sum+=v[i].ss;
        merge(a,b);
    }
    }
    cout<<sum<<endl;




}
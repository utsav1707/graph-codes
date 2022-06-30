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
const int N=100005;
const int M=17;
int a[N];
int m[N][M];
int lk[N];
int query(int l,int r){
	int len=r-l+1;
	int k=lk[len];
	return min(m[l][k],m[r-(1<<k)+1][k]);
}
signed main()
{
    fast_io;
    int n;cin>>n;
    lk[1]=0;
    for(int i=2;i<=n;i++){
    	lk[i]=lk[i/2]+1;
    }
    for(int i=0;i<n;i++){
    	cin>>a[i];
    	m[i][0]=a[i];
    }
    for(int k=1;k<M;k++) {
		for(int i=0;i+(1<<k)-1<n;i++) {
			m[i][k]=min(m[i][k-1],m[i+(1<<(k-1))][k-1]);
		}
	}
    int q;cin>>q;
    while(q--){
    	int l,r;
    	cin>>l>>r;
    	cout<<query(l,r)<<endl;
    }



}
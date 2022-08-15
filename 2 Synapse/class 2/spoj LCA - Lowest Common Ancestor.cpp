//***********************Bismillah-ir-Rahman-ir-Rahim******************************\
//In the Name of Allah
//La ilaha illallah Muhammadur Rasulullah
//Rabbir Hamhuma Kama Rabba Yani Sagheera

#include<bits/stdc++.h>
using namespace std;

#define Alhamdulillah ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define vi vector<int>
#define vll vector<ll>
#define vs vector<string>
#define pll pair<ll,ll>
#define vp vector<pair<ll,ll>>
#define pb push_back
#define ff first
#define ss second
#define pi acos(-1.0)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define EPS 1e-9

ll ceilAB(ll a, ll b) { return (a + b - 1) / b; }
ll Pow(ll c, ll d) {return d == 0 ? 1 : c * pow(c, d - 1);}
ll gcd(ll a, ll b) {return b == 0 ? a : gcd(b, a % b);}
ll lcm(ll a, ll b) {return ((a * b) / gcd(a, b));}

const int mx = 1e6;
int a[mx];


const int MAX_N = 1010;
const int LOG = 14;
vector<int> children[MAX_N];
int up[LOG][MAX_N]; // up[j][v] is 2^j-th ancestor of v
int depth[MAX_N];

void dfs(int a) {
	for (int b : children[a])
	{
		depth[b] = depth[a] + 1;
		up[0][b] = a; // a is parent of b
		for (int j = 1; j < LOG; j++)
		{
			up[j][b] = up[j - 1][up[j - 1][b]];
		}
		dfs(b);
	}
}

int get_lca(int a, int b) { // O(log(N))
	if (depth[a] < depth[b]) {
		swap(a, b);
	}
	// 1) Get same depth.
	int k = depth[a] - depth[b];
	for (int j = LOG - 1; j >= 0; j--) {
		if (k & (1 << j)) {
			a = up[j][a]; // parent of a
		}
	}
	// 2) if b was ancestor of a then now a==b
	if (a == b) {
		return a;
	}
	// 3) move both a and b with powers of two
	for (int j = LOG - 1; j >= 0; j--) {
		if (up[j][a] != up[j][b]) {
			a = up[j][a];
			b = up[j][b];
		}
	}
	return up[0][a];
}


void solve()
{
	int t, tc = 0;
	cin >> t;
	while (t--)
	{
		tc++;
		cout << "Case " << tc << ": " << endl;
		int i, j, k , n, m, x, y, z, c = 0, cnt = 0;
		string s;
		cin >> n;
		for (int v = 1; v <= n; ++v) {
			// read children of v
			int cnt;
			cin >> cnt;
			children[v].clear();
			for (int i = 0; i < cnt; i++)
			{
				int c;
				cin >> c;
				children[v].push_back(c);
			}
		}
		dfs(1);
		int q;
		cin >> q;
		for (int i = 0; i < q; i++)
		{
			int a, b;
			cin >> a >> b;
			cout << get_lca(a, b) << "\n";
		}

	}























}



int main()
{

	Alhamdulillah;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	solve();
	return 0;

}
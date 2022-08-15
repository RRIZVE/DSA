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

vector<int>table[20], v;

void build_sparse_table(int n)
{
	int i, j;
	for (i = 1; i <= n; i++)
	{
		table[0][i] = v[i - 1];
	}
	for (i = 1; i < 20; i++)
	{
		for (j = 1; j + (1 << i) - 1 <= n; j++)
		{
			table[i][j] = min(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
		}
	}

}
int min_query(int l, int r)
{
	int length = r - l + 1;
	int i = 0, k = 1;
	for ( ; k <= length; i++) k = k * 2;
	k = i - 1;
	return min(table[k][l], table[k][r - (1 << k) + 1]);
}

void solve()
{
	int t, tc = 0;
	cin >> t;
	while (t--)
	{

		tc++;
		cout << "Case " << tc << ": " << endl;
		int i, j, k , n, m, x, y, z, c = 0, cnt = 0, q;
		string s;
		cin >> n >> q;
		for ( i = 0; i < 20; i++)
		{
			table[i].clear(), table[i].resize(n + 5);

		}

		v.resize(n + 5);
		for ( i = 0; i < n ; i++)
		{
			cin >> v[i];

		}

		build_sparse_table(n);
		while (q--)
		{
			int l, r;
			cin >> l >> r;
			cout << min_query(l, r) << endl;
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
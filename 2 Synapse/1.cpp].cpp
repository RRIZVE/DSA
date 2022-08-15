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

const int N = 1e6;
int a[N];
int lazy[4 * N];
int ans[4 * N];
int n;

void build(int v, int tl, int tr)
{
	lazy[v] = 0;
	if (tl == tr)
	{
		ans[v] = a[tl];
		return ;
	}

	int tm = (tl + tr) / 2;
	build(v << 1, tl, tm);
	build(v << 1 | 1, tm + 1, tr);

	ans[v] = ans[v << 1] + ans[v << 1 | 1];

}

void pushdown(int v, int tl, int tr)
{
	int tm = (tl + tr) / 2;

	lazy[v << 1] += lazy[v];
	ans[v << 1] += lazy[v] * (tm - tl + 1);

	lazy[v << 1 | 1] += lazy[v];
	ans[v << 1 | 1] += lazy[v] * (tr - tm);


	lazy[v] = 0;

}

void pullup(int v, int tl, int tr)
{
	ans[v] = ans[v << 1] + ans[v << 1 | 1];
}

void update(int v, int tl, int tr, int l, int r, int x)
{
	if (tr < l or r < tl)
		return;

	if (l <= tl and tr <= r)
	{
		lazy[v] += x;
		ans[v] += x;
		return;
	}

	//propagation
	pushdown(v, tl, tr);

	int tm = (tl + tr) / 2;
	update(v << 1, tl, tm, l, r, x);
	update(v << 1 | 1, tm + 1, tr, l, r, x);

	pullup(v, tl, tr);


}

int query(int v, int tl, int tr, int l, int r)
{
	if (tr < l or r < tl)
		return 0;

	if (l <= tl and tr <= r)
	{
		return ans[v];
	}

	pushdown(v, tl, tr);

	int tm = (tl + tr) / 2;
	int left_ans = query(v << 1, tl, tm, l, r);
	int right_ans = query(v << 1 | 1, tm + 1, tr, l, r);

	//ans[v] = ans[v << 1] + ans[v << 1 | 1];

	return left_ans + right_ans;
}




void solve()
{
	int t;
	cin >> t;

	int i, j, k , m, x, y, z, c = 0, cnt = 0;
	string s;
	cin >> n;
	int q;
	cin >> q;
	for ( i = 1; i <= n ; i++)
	{
		//cin >> a[i];
		a[i] = 0;

	}

	build(1, 1, n);


	while (q--)
	{
		int type;
		cin >> type;
		if (type == 0)
		{
			//cout << "YES" << endl;
			int l, r, x;
			cin >> l >> r >> x;
			update(1, 1, n, l, r, x);
		}
		else
		{
			int l, r;
			cin >> l >> r;
			cout << query(1, 1, n, l, r) << endl;


		}

	}

	/*

	8
	1 2 3 4 5 6 7 8
	7
	1 1 4 1
	1 1 2 4
	2 1 4
	2 1 2
	1 1 8 5
	2 1 4
	2 1 8

	7
	7
	12
	13


	*/

















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
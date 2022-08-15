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
int st[4 * N];
int n;

void build(int v, int tl, int tr)
{
	if (tl == tr)
	{
		st[v] = a[tl];
		return ;
	}

	int tm = (tl + tr) / 2;
	build(v << 1, tl, tm);
	build(v << 1 | 1, tm + 1, tr);

	st[v] = 0;

}

void update(int v, int tl, int tr, int l, int r, int x)
{
	if (tr < l or r < tl)
		return;

	if (l <= tl and tr <= r)
	{
		st[v] += x;
		return;
	}

	int tm = (tl + tr) / 2;
	update(v << 1, tl, tm, l, r, x);
	update(v << 1 | 1, tm + 1, tr, l, r, x);
}

int query(int v, int tl, int tr, int id)
{
	if (tl == tr)
		return st[v];

	int tm = (tl + tr) / 2;
	if (id <= tm) return query(v << 1, tl, tm, id) + st[v];
	else return query(v << 1 | 1, tm + 1, tr, id) + st[v];
}




void solve()
{

	int i, j, k , m, x, y, z, c = 0, cnt = 0;
	string s;
	cin >> n;
	for ( i = 1; i <= n ; i++)
	{
		cin >> a[i];

	}

	build(1, 1, n);

	int q;
	cin >> q;
	while (q--)
	{
		int type;
		cin >> type;
		if (type == 1)
		{
			int l, r, x;
			cin >> l >> r >> x;
			update(1, 1, n, l, r, x);
		}
		else
		{
			int idx;
			cin >> idx;
			cout << query(1, 1, n, idx) << endl;


		}

	}

	/*

	7
	1 2 3 4 5 6 7
	5
	1 1 5 3
	1 1 2 5
	2 1
	2 2
	2 7


	9
	10
	7
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
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
int n;
int a[N];
int tree[4 * N];

void build(int ti, int tl, int tr)
{
	if (tl == tr)
	{
		tree[ti] = a[tl];
		return;
	}
	int tm = (tl + tr) / 2;
	build(ti << 1, tl, tm);
	build(ti << 1 | 1, tm + 1, tr);
	tree[ti] = tree[ti << 1] + tree[ti << 1 | 1];

}

void update(int ti, int tl, int tr, int pos, int val)
{
	if (tl == tr)
	{
		a[pos] = val;
		tree[ti] = val;
		return;
	}

	int tm = (tl + tr) / 2;
	if (pos <= tm)
		update(ti << 1, tl, tm, pos, val);
	else
		update(ti << 1 | 1, tm + 1, tr, pos, val);

	tree[ti] = tree[ti << 1] + tree[ti << 1 | 1];
}

ll query(int ti, int tl, int tr, int ql, int qr)
{
	if (tr < ql or qr < tl)return 0; //no intersection
	if (ql <= tl and tr <= qr)return tree[ti] ;//completely intersection

	int tm = (tl + tr) / 2;
	ll res_l = query(ti << 1, tl, tm, ql, qr);
	ll res_r = query(ti << 1 | 1, tm + 1, tr, ql, qr);

	return res_l + res_r;

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
			int pos, val;
			cin >> pos >> val;
			update(1, 1, n, pos, val);

		}
		else
		{
			int l, r;
			cin >> l >> r;
			cout << query(1, 1, n, l, r) << endl;
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
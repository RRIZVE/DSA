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

#define mx 100000

ll a[mx + 5];
vector <ll> segment[4 * mx + 5];


vector<ll> cal(vector<ll>&left, vector<ll>&right)
{
	vll v;
	for ( auto u : left)v.pb(u);
	for ( auto u : right)v.pb(u);
	sort(v.begin(), v.end());
	return v;

}


void build(int ti, int tl, int tr)
{
	if (tl == tr)
	{

		segment[ti].pb(a[tl]);
		return;
	}
	int tm = (tl + tr) >> 1;

	build(ti << 1, tl, tm);
	build(ti << 1 | 1, tm + 1, tr);

	segment[ti] = cal(segment[ti << 1], segment[ti << 1 | 1]);



}




int query(int ti, int tl, int tr, int ql, int qr, int qk)
{
	if (tl > qr || tr < ql)
		return 0;

	if (tl >= ql && tr <= qr)
	{
		int upper = upper_bound(segment[ti].begin(), segment[ti].end(), qk) - segment[ti].begin();

		return segment[ti].size() - upper;
	}

	int tm = (tl + tr) / 2;

	return query(2 * ti, tl, tm, ql, qr, qk) + query(2 * ti + 1, tm + 1, tr, ql, qr, qk);





}



void solve()
{

	ll i, j, k, m, x, y, z, c = 0, cnt = 0, n;

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

		ll l, r, k;
		cin >> l >> r >> k;
		cout << query(1, 1, n, l, r, k) << endl;



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
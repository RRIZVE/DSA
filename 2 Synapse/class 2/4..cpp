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

#define fraction() cout.unsetf(ios::floatfield); cout.precision(12); cout.setf(ios::fixed,ios::floatfield);

const int mx = 1e5 + 100;
int a[mx];

vector<ll>table1[20], v;
vector<ll>table2[20];

void build_sparse_table(int n)
{
	int i, j;
	for (i = 1; i <= n; i++)
	{
		table1[0][i] = v[i - 1];
		table2[0][i] = v[i - 1];
	}
	for (i = 1; i < 20; i++)
	{
		for (j = 1; j + (1 << i) - 1 <= n; j++)
		{
			table1[i][j] = min(table1[i - 1][j], table1[i - 1][j + (1 << (i - 1))]);
			table2[i][j] = max(table2[i - 1][j], table2[i - 1][j + (1 << (i - 1))]);
		}
	}

}
int min_query(int l, int r)
{
	int length = r - l + 1;
	int i = 0, k = 1;
	for ( ; k <= length; i++) k = k * 2;
	k = i - 1;
	return min(table1[k][l], table1[k][r - (1 << k) + 1]);
}
int max_query(int l, int r)
{
	int length = r - l + 1;
	int i = 0, k = 1;
	for ( ; k <= length; i++) k = k * 2;
	k = i - 1;
	return max(table2[k][l], table2[k][r - (1 << k) + 1]);
}

void solve()
{

	int i, j, k , n, m, x, y, z, c = 0, cnt = 0;
	string s;
	cin >> n;
	for ( i = 0; i < 20; i++)
	{
		table1[i].clear(), table1[i].resize(n + 5);
		table2[i].clear(), table2[i].resize(n + 5);

	}


	v.resize(n + 5);
	for ( i = 0; i < n ; i++)
	{
		cin >> v[i];

	}

	build_sparse_table(n);
	int q;
	cin >> q;
	while (q--)
	{

		int l, r;
		cin >> l >> r;
		l++;
		r++;
		fraction();
		ll mnind = min_query(l, r);
		ll mxind = max_query(l, r);
		ll extra = (mxind - mnind) / 2;

		ll mxout1 = 0.0;
		ll mxout2 = 0.0;
		if (l - 1 >= 1)
		{
			mxout1 = max_query(1, l - 1);
		}
		if (r + 1 <= n)
		{
			mxout2 = max_query(r + 1, n);
		}
		ll mxout = max(mxout1, mxout2);


		cout << mnind  << endl;
		cout << mxind  << endl ;
		cout << extra  << endl << endl;

		cout << mxout1  << endl;
		cout << mxout2  << endl;
		cout << mxout  << endl;


		// cout << endl << endl;

		cout << mnind + max(mxout, extra) << endl;




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
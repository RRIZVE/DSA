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

struct Query
{
	int l, r;
	int ans;
	Query() {}
	Query(int _l, int _r)
	{
		l = _l;
		r = _r;
	}


};

int n;
int a[N];
int q;
Query query[N];
int range_ans;

void include(int id)
{
	range_ans = range_ans + a[id];
}
void remove(int id)
{
	range_ans = range_ans - a[id];
}

int get_ans()
{
	return range_ans;
}




void solve()
{

	int i, j, k , n, m, x, y, z, c = 0, cnt = 0;
	cin >> n;
	for ( i = 0; i < n ; i++)
	{
		cin >> a[i];

	}
	cin >> q;
	for ( i = 0; i < q ; i++)
	{
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		query[i] = Query(l, r);

	}

	int L = 0, R = -1;

	for ( i = 0; i < q ; i++)
	{
		int ql = query[i].l;
		int qr = query[i].r;


		while (L > ql)
		{
			L--;
			include(L);
		}
		while (R < qr)
		{
			R++;
			include(R);
		}

		while (L < ql)
		{
			remove(L);
			L++;
		}
		while (R > qr)
		{
			remove(R);
			R--;
		}

		query[i].ans = get_ans();

	}

	for ( i = 0; i < q ; i++)
	{
		cout << query[i].ans << endl;



	}

	/*

	9
	5 2 5 7 3 9 7 4 1
	5
	1 5
	3 8
	5 8
	2 9
	7 9



	22
	35
	23
	38
	12


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
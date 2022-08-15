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
int bit[mx];
int n;

int query(int pos)
{
	int res = 0;
	while (pos)
	{
		res += bit[pos];
		pos -= pos & -pos;

	}
	return res;
}

//update a[pos]+=val;
void update(int pos, int val)
{
	while (pos <= n)
	{
		bit[pos] += val;
		pos += pos & -pos;

	}


}




void solve()
{

	int i, j, k , m, x, y, z, c = 0, cnt = 0;
	string s;
	cin >> n;
	for ( i = 1; i <= n ; i++)
	{
		cin >> a[i];
		update(i, a[i]);

	}
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
			val =  val - a[pos];
			//cout << val << endl;
			update(pos, val);

		}
		else
		{
			int l, r;
			cin >> l >> r;
			cout << query(r) - query(l - 1) << endl;
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

/*
9
1 2 3 4 5 6 7 8 9
5
2 2 7
3 3 5
1 3 1
2 2 7
2 3 5

27
12
29
14



*/
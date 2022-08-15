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

const int N = 1e5 + 5;

int n;
int a[N];
int q;
int block_size;
int distinct_numbers;
int freq[N];
int ans[N];

struct Query
{
	int id;
	int l, r;
	int ans;
	Query() {}
	Query(int _id, int _l, int _r)
	{
		id = _id;
		l = _l;
		r = _r;
	}

	bool operator<(Query &other)const
	{
		int curr_block = l / block_size;
		int other_block = other.l / block_size;

		if (curr_block != other_block)
		{
			return curr_block < other_block;
		}
		else
		{
			return r < other.r;
		}


	}


} query[N];

void include(int id)
{
	freq[a[id]]++;
	if (freq[a[id]] == 1)
	{
		distinct_numbers++;
	}
}

void remove(int id)
{
	freq[a[id]]--;
	if (freq[a[id]] == 0)
	{
		distinct_numbers--;
	}
}

int get_ans()
{
	return distinct_numbers;
}

void reset()
{
	distinct_numbers = 0;
	for (int i = 0; i < N ; i++)
	{
		freq[i] = 0;
	}
}



void solve()
{
	int t, tc = 0;
	cin >> t;
	while (t--)
	{
		reset();

		int i ;
		string s;
		cin >> s;
		int len = s.size();
		n = len;
		for ( i = 0; i < len ; i++)
		{
			int x = s[i] - 'x';
			a[i] = x;


		}


		block_size = sqrt(n);

		for ( i = 0; i < q ; i++)
		{
			int l, r;
			cin >> l >> r;
			l--;
			r--;
			query[i] = Query(i, l, r);

		}

		sort(query, query + q);

		int L = 0, R = -1;

		for ( i = 0; i < q ; i++)
		{
			int ql = query[i].l;
			int qr = query[i].r;

			while (R < qr)
			{
				R++;
				include(R);
			}
			while (L > ql)
			{
				L--;
				include(L);
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
			ans[query[i].id] = query[i].ans;


		}
		for ( i = 0; i < q ; i++)
		{
			cout << ans[i] << endl;

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
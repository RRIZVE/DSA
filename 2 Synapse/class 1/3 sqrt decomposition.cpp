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
int block_size;
int block_ans[N];



void solve()
{

	int i, j, k , n, m, x, y, z, c = 0, cnt = 0;
	string s;
	cin >> n;
	for ( i = 0; i < n ; i++)
	{
		cin >> a[i];

	}
	block_size = sqrt(n);

	int total_block = ceilAB(n, block_size);

	for ( int block_id = 0; block_id < total_block ; block_id++)
	{
		int l = block_id * block_size;
		int r = min(n, (block_id + 1) * block_size);

		for ( i = l; i < r ; i++)
		{
			block_ans[block_id] += a[i];
		}

		//cout << block_id << "    " << block_ans[block_id]  << endl;
	}

	int q;
	cin >> q;

	while (q--)
	{
		int l, r;
		cin >> l >> r;
		l--, r--;

		int ans = 0;

		int block_l = l / block_size;
		int block_r = r / block_size;

		if (block_l == block_r)
		{
			for ( i = l; i <= r ; i++)
			{
				ans += a[i];
			}
		}
		else
		{
			for ( i = l; i < (block_l + 1)*block_size ; i++)
			{
				//cout << i << "  ";
				ans += a[i];
			}
			for ( i = block_r * block_size; i <= r ; i++)
			{
				//cout << i << "  ";
				ans += a[i];
			}
			for ( int block_id = block_l + 1; block_id < block_r  ; block_id++)
			{
				ans += block_ans[block_id];
			}

		}

		cout << ans << endl;
	}

	/*

	10
	2 4 5 3 9 8 3 5 7 1
	5
	1 4
	5 8
	3 5
	3 7
	1 9

	14
	25
	17
	28
	46
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
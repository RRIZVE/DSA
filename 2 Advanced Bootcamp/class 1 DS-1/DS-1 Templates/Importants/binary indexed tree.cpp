const int M = 1000005;
int  bit[M+2];
 
///set a[idx]+=val;
void update(int idx,int  val)
{
    while(idx < M){
        bit[idx] += val;
        idx += (idx&-idx);
    }
}
///returns the prefix sum from 0 to idx
int  qry(int idx)
{
    int  ret = 0;
    while(idx > 0){
        ret += bit[idx];
        idx -= (idx&-idx);
    }
    return ret;
}

///some variations : for max just insert max instead of +=

///set a[idx]+=val;

void update(int idx,int  val)
{
    while(idx >0){
        bit[idx] += val;
        idx -= (idx&-idx);
    }
}

///returns the suffix sum from idx to M-1

int  qry(int idx)
{
    int  ret = 0;
    while(idx<M){
        ret += bit[idx];
        idx += (idx&-idx);
    }
    return ret;
}

const int N = 1e5 + 5;

struct BIT
{
	int N;
	vector<int> bit;

	void init(int n)
	{
		N = n;
		bit.assign(n + 1, 0);
	}
        //Update always 1 based index e hobe 
	void update(int idx, int val)
	{
		while(idx <= N)
		{
			bit[idx] += val;
			idx += idx & -idx;
		}
	}

	void updateMax(int idx, int val)
	{
		while(idx <= N)
		{
			bit[idx] = max(bit[idx], val);
			idx += idx & -idx;
		}
	}

	int pref(int idx)
	{
		int ans = 0;
		while(idx > 0)
		{
			ans += bit[idx];
			idx -= idx & -idx;
		}
		return ans;
	}

	int rsum(int l, int r)
	{
		return pref(r) - pref(l - 1);
	}

	int prefMax(int idx)
	{
		int ans = -2e9;
		while(idx > 0)
		{
			ans = max(ans, bit[idx]);
			idx -= idx & -idx;
		}
		return ans;
	}
   //Template from Ashishgup 
};











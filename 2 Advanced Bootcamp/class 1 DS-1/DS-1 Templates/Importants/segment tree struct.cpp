Sample 1 : 
class segmentTree{
public:

    vector <ll> tr , lazy ;
    int n ;

    segmentTree(){}
    void init( int _n )
    {
        tr = vector <ll>(4*(_n+1+3)) ;
        lazy = vector <ll>(4*(_n+1+3)) ;
        n = _n ;
        build(1,1,n) ;
    }
    void build(int cn, int b, int e)
    {
        lazy[cn] = -1 ;
        if( b>e ) return ;
        if( b==e )
        {
            tr[cn] = 0 ;
            return ;
        }
        int l = cn*2 , r = cn*2+1 , m = (b+e)/2 ;
        build(l,b,m) ;
        build(r,m+1,e) ;
        tr[cn] = tr[l]+tr[r] ;
    }
    void relax( int cn, int b, int e )
    {
        tr[cn] =  (1LL*(e-b+1)*lazy[cn])%mod ;
        if( b!=e )
        {
            int l = cn*2 , r = cn*2+1 ;
            lazy[l] = lazy[cn] ;
            lazy[r] = lazy[cn] ;
        }
        lazy[cn] = -1 ;
    }
    void update(int cn, int b, int e ,int left , int right, ll val)
    {
        if( b>e ) return ;
        if(lazy[cn]!=-1) relax(cn,b,e) ;
        if( e<left || b>right ) return ;
        if( b>= left && e<=right )
        {
            lazy[cn] = val ;
            relax(cn,b,e) ;
            return ;
        }
        int l = cn*2 , r = cn*2+1 , m = (b+e)/2 ;
        update(l,b,m,left,right,val) ;
        update(r,m+1,e,left,right,val) ;
        tr[cn] = (tr[l]+tr[r])%mod ;
    }
    ll query(int cn, int b, int e ,int left,int right)
    {
        if(b>e) return 0LL ;
        if(lazy[cn]!=-1) relax(cn,b,e) ;
        if( b>right || e<left ) return 0 ;
        if( b>= left && e<=right ) return tr[cn] ;
        int l = cn*2 , r = cn*2+1 , m = (b+e)/2 ;
        return ( query(l,b,m,left,right) + query(r,m+1,e,left,right) )%mod ;
    }
    void Update(int left, int right, ll val){update(1,1,n,left,right,val) ;}
    ll Query(int left, int right){ return query(1,1,n,left,right) ; } ;
};
segmentTree s;

...........................................................
Sample 2 : Ashisgup seg struct

const int N = 1e6 + 5;
 
struct data
{
	//Use required attributes
	int mn;
 
	//Default Values
	data() : mn(1e9) {};
};
 
int store[N];
 
struct SegTree
{
	int N;
	vector<data> st;
	vector<bool> cLazy;
	vector<int> lazy;
 
	void init(int n)
	{
		N = n;
		st.resize(4 * N + 5);
		cLazy.assign(4 * N + 5, false);
		lazy.assign(4 * N + 5, 0);
	}
 
	//Write reqd merge functions
	void merge(data &cur, data &l, data &r) 
	{
		cur.mn = min(l.mn, r.mn);
	}
	
	//Handle lazy propagation appriopriately
	void propagate(int node, int L, int R)
	{
		if(L != R)
		{
			cLazy[node*2] = 1;
			cLazy[node*2 + 1] = 1;
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node]; 
		}
		st[node].mn += lazy[node];
		cLazy[node] = 0;
		lazy[node] = 0;
	}
 
	void build(int node, int L, int R)
	{
		if(L == R)
		{
			st[node].mn = store[L];
			return;
		}
		int M = (L + R) / 2;
		build(node*2, L, M);
		build(node*2 + 1, M + 1, R);
		merge(st[node], st[node*2], st[node*2+1]);
	}
 
	data Query(int node, int L, int R, int i, int j)
	{
		if(cLazy[node])
			propagate(node, L, R);
		if(j<L || i>R)
			return data();
		if(i<=L && R<=j)
			return st[node];
		int M = (L + R)/2;
		data left = Query(node*2, L, M, i, j);
		data right = Query(node*2 + 1, M + 1, R, i, j);
		data cur;
		merge(cur, left, right);
		return cur;
	}
 
	data pQuery(int node, int L, int R, int pos)
	{
		if(cLazy[node])
			propagate(node, L, R);
		if(L == R)
			return st[node];
		int M = (L + R)/2;
		if(pos <= M)
			return pQuery(node*2, L, M, pos);
		else
			return pQuery(node*2 + 1, M + 1, R, pos);
	}	
 
	void Update(int node, int L, int R, int i, int j, int val)
	{
		if(cLazy[node])
			propagate(node, L, R);
		if(j<L || i>R)
			return;
		if(i<=L && R<=j)
		{
			cLazy[node] = 1;
			lazy[node] += val;
			propagate(node, L, R);
			return;
		}
		int M = (L + R)/2;
		Update(node*2, L, M, i, j, val);
		Update(node*2 + 1, M + 1, R, i, j, val);
		merge(st[node], st[node*2], st[node*2 + 1]);
	}
 
	void pUpdate(int node, int L, int R, int pos, int val)
	{
		if(cLazy[node])
			propagate(node, L, R);
		if(L == R)
		{
			cLazy[node] = 1;
			lazy[node] += val;
			propagate(node, L, R);
			return;
		}
		int M = (L + R)/2;
		if(pos <= M)
			pUpdate(node*2, L, M, pos, val);
		else
			pUpdate(node*2 + 1, M + 1, R, pos, val);
		merge(st[node], st[node*2], st[node*2 + 1]);
	}
 
	data query(int pos)
	{
		return pQuery(1, 1, N, pos);
	}
 
	data query(int l, int r)
	{
		return Query(1, 1, N, l, r);
	}
 
	void update(int pos, int val)
	{
		pUpdate(1, 1, N, pos, val);
	}
 
	void update(int l, int r, int val)
	{
		Update(1, 1, N, l, r, val);
	}
};
 
SegTree st;
.........................................................................................................
Sample 3 :
Rezwan arefin template
struct SegmentTree {
	int n; 
	vector<int> t, lazy; 
	SegmentTree(int _n = 0) {
		n = _n; 
		t = vector<int>(4*n, 0); 
		lazy = vector<int>(4*n, 0);
	}
 
	void upd(int node, int c) {
		t[node] = c; 
		lazy[node] = c;
	}
	void shift(int node) {
		if(!lazy[node]) return; 
		upd(node<<1, lazy[node]); 
		upd(node<<1|1, lazy[node]); 
		lazy[node] = 0;
	}
	void update(int node, int l, int r, int i, int j, int c) {
		if(r < i || l > j) return; 
		if(i <= l && r <= j) {
			upd(node, c); 
			return;
		} shift(node); 
		int mid = l + r >> 1;
		update(node<<1, l, mid, i, j, c); 
		update(node<<1|1, mid+1, r, i, j, c); 
		t[node] = max(t[node<<1], t[node<<1|1]);
	} 
	void update(int i, int j, int c) {
		update(1, 0, n-1, i, j, c); 
	}
	int query(int node, int l, int r, int i, int j) {
		if(r < i || l > j) return 0;
		if(i <= l && r <= j) return t[node]; 
		shift(node); 
		int mid = l + r >> 1;
		return max(query(node<<1, l, mid, i, j), query(node<<1|1, mid+1, r, i, j));
	}
	int query(int i, int j) {
		return query(1, 0, n-1, i, j); 
	}
};
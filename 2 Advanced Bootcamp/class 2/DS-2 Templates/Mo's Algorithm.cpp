/**
 * MO's algorithm
 * Handles offline query in O(Q \sqrt{N}) (usually)
 * - Maintain proper block_sz ~ \sqrt{N}
 * - Careful with < in query
 * - Query indices are presumed to be 0-indexed
 * - Array indices are also 0-indexed
**/

// [L to R] = no of distinct element
 
const int block_sz = 550;	// N ~ 3e5
int freq[N], mo_cnt = 0;
int ret[N];
 
inline void add(int idx) { 
	++freq[a[idx]];
	if(freq[a[idx]] == 1) ++mo_cnt;
}
 
inline void erase(int idx) {
	--freq[a[idx]];
	if(freq[a[idx]] == 0) --mo_cnt;
}
 
inline int get_ans() {
	return mo_cnt;
}
 
struct query {
	int l, r, idx;
	query() { }
	query(int _l, int _r, int _i) : l(_l), r(_r), idx(_i) { }
	bool operator < (const query &p) const {
		if(l/block_sz != p.l/block_sz) return l < p.l;
		return ((l/block_sz) & 1) ? r > p.r : r < p.r;
	}
};
 
void mo(vector<query> &q) {
	sort(q.begin(), q.end());
	memset(ret, -1, sizeof ret);
 
	// l = 1, r = 0 if 1-indexed array
	int l = 0, r = -1; /// l,r => current_l , current_r
	for(auto &qq : q) {

		// qq.l, qq.r = required l,r 
		while(qq.l < l) add(--l);
		while(qq.r > r) add(++r);
		while(qq.l > l) erase(l++);
		while(qq.r < r) erase(r--);
		ret[qq.idx] = max(ret[qq.idx], get_ans());
	}
}

for(int i=1;i<=no_of_query;i++)
{
      cout<<ret[i]<<endl;
}
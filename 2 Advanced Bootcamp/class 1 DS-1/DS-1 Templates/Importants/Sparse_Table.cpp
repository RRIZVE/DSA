 struct Sparse
{
    int n,lg;
    vector<vector<int> >sparse_mx,sparse_mn;
    vector<int>A;
    void init(int tmp)
    {
        n=tmp;
        A.resize(n+3);
        lg=32-__builtin_clz(n+2);// 64 if nmx > 10^9
        sparse_mx=vector< vector<int> >(n+2,vector<int>(lg));
        sparse_mn=vector< vector<int> >(n+2,vector<int>(lg));
    }
    void abr_init(int aa[])
    {
        for(int i=1;i<=n;i++)A[i]=aa[i];
        build_table();
    }
    void build_table()
    {
         for(int i=1;i<=n;i++)sparse_mx[i][0]=A[i],sparse_mn[i][0]=A[i];
         for(int k=1,p=1;k<lg;k++,p<<=1)
         {
             for(int i=1;i+p+p<=n+1;i++)
             {
                 sparse_mx[i][k]=max(sparse_mx[i][k-1],sparse_mx[i+p][k-1]);
                 sparse_mn[i][k]=min(sparse_mn[i][k-1],sparse_mn[i+p][k-1]);
             }
         }
    }
    int qmx(int l,int r)
    {
        int len=r-l+1;
        int k=32-__builtin_clz(len)-1;
        return max(sparse_mx[l][k],sparse_mx[r-(1<<k)+1][k]);
    }
    int qmn(int l,int r)
    {
        int len=r-l+1;
        int k=32-__builtin_clz(len)-1;
        return min(sparse_mn[l][k],sparse_mn[r-(1<<k)+1][k]);
    }


};
Sparse yo;                                                                                                     


///Another Template
struct RMQ{
    int N;
    vector< int >v[20];
    RMQ(const vector< int >&a) {
        N = a.size();
        v[0].resize(N);
        for (int i = 0; i < N; i++)
            v[0][i] = a[i];
 
        for (int k = 0; (1<<(k+1)) <= N; k++) {
            v[k+1].resize(N);
            for (int i = 0; i-1+(1<<(k+1)) < N; i++) {
                v[k+1][i] = min(v[k][i], v[k][i+(1<<k)]);
            }
        }
    }
 
    int findMin(int i, int j) {
        int k = j-i+1;
        k = lg[k];
        return min(v[k][i], v[k][j+1-(1<<k)]);
    }
};
RMQ yo(vec);                                                                                                            
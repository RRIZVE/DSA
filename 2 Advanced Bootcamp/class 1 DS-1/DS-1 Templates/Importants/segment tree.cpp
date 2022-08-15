///Range sum query
int tre[4*M],lz[4*M];
void propagate(int pos,int l,int r)
{
    if(lz[pos]==0)return ;
    tre[pos]+=lz[pos];
    if(l!=r)
    {
        lz[2*pos]+=lz[pos];
        lz[2*pos+1]+=lz[pos];
    }
    lz[pos]=0;
}
void update(int pos,int l,int r,int I,int J,int x)
{
    propagate(pos,l,r);
    if(l>J || r<I)return  ;
    if(I<=l && J>=r)
    {
        lz[pos]+=x;
        propagate(pos,l,r);
        return ;
    }
    int mid=(l+r)>>1;
    update(2*pos,l,mid,I,J,x);
    update(2*pos+1,mid+1,r,I,J,x);
    tre[pos]=tre[2*pos]+tre[2*pos+1];
}
int qry(int pos,int l,int r,int I,int J)
{
    propagate(pos,l,r);
    if(l>J || r<I)return 0;
    if(I<=l && J>=r)
    {
        return tre[pos];
    }
    int mid=(l+r)>>1;
    int x=qry(2*pos,l,mid,I,J);
    int y=qry(2*pos+1,mid+1,r,I,J);
    tre[pos]=tre[2*pos]+tre[2*pos+1];
    return x+y;
}
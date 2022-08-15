int bit[M+2][M+2];
///This will return the sum from (0,0)(low_left) to (x,y)(upper_right) rectangle
int qry(int x ,int y)
{
    int ret=0;
    if(x<0 || y<0)return 0;
    for(int i=x;i>=0;i=(i&(i+1))-1)
    for(int j=y;j>=0;j=(j&(j+1))-1)
        ret+=bit[i][j];
    return ret;
}
void update(int x,int y,int val)
{
    for(int i=x;i<=M;i=i|(i+1))
        for(int j=y;j<=M;j=j|(j+1))
            bit[i][j]+=val;
}
/// upper right corner = (x2,y2)
///lower left corner = (x1,y1)
/// this will return the sum inside the rectangle
int get_sum(int x1,int y1,int x2,int y2)
{
   return qry(x2,y2)-qry(x1-1,y2)-qry(x2,y1-1)+qry(x1-1,y1-1);
}
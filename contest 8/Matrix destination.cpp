bool canReach(int mat[R][C], int n, int i, int j)
{
    if(i==n-1 && j==n-1)
      return true;
    int x=0,y=0;
    if(j<n-1 && mat[i][j+1]%2==0) 
    {
        x=canReach(mat,n,i,j+1);        
    }
    if(i<n-1 && mat[i+1][j]%2==0) 
    {
        y=canReach(mat,n,i+1,j);        
    }
    
    if(x==1||y==1)
     return true;
     else
    return false;
}
class Solution{
    public:
    //You need to complete this fucntion
    
    long long power(int N,int R)
    {
      if(R==1)return N;
        if(R%2==0){
            long y=power(N,R/2);
            return (y*y)%1000000007;
        }
        return (N*power(N,R-1))%1000000007;
       //Your code here
        
    }

};
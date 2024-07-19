class Solution
{
    public:
    long long maximumSum(int arr[], int sizeOfArray)
    {
        long long dp[sizeOfArray]={0}; 
        dp[0]=max((long long)arr[0],dp[0]);
        dp[1]=max(dp[0],(long long)arr[1]);  
        
        
        for(int i=2;i<sizeOfArray;i++)
        {
           dp[i]=max(dp[i-2]+arr[i],dp[i-1]);   
        
        }
        
        int maxx=INT_MIN;
        bool isAllNegative=true;                
        for(int i=0;i<sizeOfArray;i++)
        {
           maxx=max(maxx,arr[i]);
           if(arr[i]>0)
           {
               isAllNegative=false;
               break;
           }
        
        }
        if(isAllNegative==true)
        {
           return maxx;                     
        }
        else
        return (dp[sizeOfArray-1]);          
    }
};
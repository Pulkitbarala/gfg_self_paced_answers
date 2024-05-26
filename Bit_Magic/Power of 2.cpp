class Solution{
    public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n){
        if (n == 0)  
        return 0;  
    while (n != 1)  
    {  
        if (n%2 != 0)  
            return 0;  
        n = n/2;  
    }  
    return 1;  
        // Your code here    
        
    }
};
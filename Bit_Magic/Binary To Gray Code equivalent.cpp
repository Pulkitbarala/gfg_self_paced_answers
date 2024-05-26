class Solution{
    public:
    //  Function to find the gray code of given number n
    int greyConverter(int n)
    {
         return n ^ (n >> 1); 
        // Your code here
        
    }
};
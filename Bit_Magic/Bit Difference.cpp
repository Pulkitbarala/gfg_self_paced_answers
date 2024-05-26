class Solution{
    public:
    // Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b){
        
        // Your logic here
        int count=0;
    while(a||b)
    {
    int ls_a = a&1;
    int ls_b = b&1;
    if(ls_a!=ls_b)
        count++;
    a=a>>1;
    b=b>>1;
    }
return count;
        
    }
};
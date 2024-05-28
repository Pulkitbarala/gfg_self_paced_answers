//User function Template for C++

class Solution{
  public:
    // Complete this function
    int sumOfDigits(int n)
    {
        if(n<10)
    return n;
 else
    return sumOfDigits(n/10)+n%10;
        //Your code here
    }
};
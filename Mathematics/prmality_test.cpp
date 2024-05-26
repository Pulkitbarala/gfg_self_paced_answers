class Solution{
    public:
        bool isPrime(int N)
    {
        if (N <= 1) {
        return false;  // Numbers less than or equal to 1 are not prime
        }
        for (int i = 2; i * i <= N; i++) {
            if (N % i == 0) {
                return false;  // If the number is divisible by any number from 2 to sqrt(number), it's not prime
            }
    }
    return true;  
    }

};
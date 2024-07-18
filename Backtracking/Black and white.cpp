
int mod = 1000000007;
long long numOfWays(int N, int M)
{
    long long count = 0;
    long long res = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            count = 0;
            if(i - 1 >= 0 && j - 2 >= 0)
            {
                count++;
            }
            if(i + 1 < N && j - 2 >= 0)
            {
                count++;
            }
            if(j + 2 < M && i + 1 < N)
            {
                count++;
            }
            if(j + 2 < M && i - 1 >= 0)
            {
                count++;
            }
            if(i - 2 >= 0 && j - 1 >= 0)
            {
                count++;
            }
            if(i - 2 >= 0 && j + 1 < M)
            {
                count++;
            }
            if(i + 2 < N && j - 1 >= 0)
            {
                count++;
            }
            if(i + 2 < N && j + 1 < M)
            {
                count++;
            }
            count++;
            res = res % mod + (((N % mod) * (M % mod)) % mod - count) % mod;
        }
    }
    return res;
}
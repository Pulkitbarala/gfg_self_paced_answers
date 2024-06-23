class Solution{
    public:
    int betBalance(string result)
    {
        
        int N, i, balance = 4, bet = 1;
        N = result.size();
        
        //loop for calculating the final balance
        for(i = 0;i < N;i++)
        {
            if(result[i] == 'W')
            {
                balance = balance + bet;
                bet = 1;
            }
            else
            {
                balance = balance - bet;
                bet = bet * 2;
            }
            if(balance < bet && i < N-1)
            {
                balance = -1;
                break;
            }
        }
        return balance;
    }
};

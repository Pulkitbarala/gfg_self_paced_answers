ll count(ll n) 
{
    vector<ll> moves = {3, 5, 10};
    vector<ll> dp(n + 1, 0);
    dp[0] = 1;
    for (ll move : moves) {
        for (ll i = move; i <= n; ++i) {
            dp[i] += dp[i - move];
        }
    }
    
    return dp[n];
}
unsigned long long maxValue(string s)
{
    unsigned long long ans=(int)(s[0]-'0');
    for(int i=1;i<s.length();i++)
    {
       ans=max(ans+(int)(s[i]-'0'),ans*(int)(s[i]-'0'));
       
    }
    
    return ans;
}

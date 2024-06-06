class Solution
{
    public:
    //Function to find minimum number of characters which Ishaan must insert  
    //such that string doesn't have three consecutive same characters.
    int modified (string a)
    {
        int n = a.size();
        int count = 0;
        
        //Iterating through the string starting from index 2.
        for(int i=2; i<n; i++)
        {
            //If three consecutive characters are same, we increment count.
            if(a[i] == a[i-1] && a[i-1] == a[i-2])
            {
                count++;
                //Adding character at index i and then incrementing i to i+1.
                i++;
            }
        }
        //returning the count of characters needed to be added.
        return count;
    }
};
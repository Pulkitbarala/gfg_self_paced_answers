class Solution
{
    public:
    //Function to check if the given pattern exists in the given string or not.
    bool search(string pat, string txt) 
    { 
        int M = pat.length(); 
        int N = txt.length(); 

        //A loop to slide pat[] one by one 
        for (int i = 0; i <= N - M; i++) { 
            int j; 

            //For current index i, check for pattern match 
            for (j = 0; j < M; j++) 
                if (txt[i + j] != pat[j]) 
                    break; 

            //If pattern is present at current index, return true
            if (j == M) 
                return true; 
        } 

        //If pattern is not found, return false
        return false; 
    } 
};
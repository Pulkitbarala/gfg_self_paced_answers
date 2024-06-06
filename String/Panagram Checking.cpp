class Solution
{
  public:
    //Function to check if a string is Pangram or not.
    bool checkPangram (string s) {
        //Initializing a boolean array to mark occurrence of each letter.
        bool present[26] = {false};
        
        //Iterating through the string to mark occurrence of each letter.
        for(char c : s) {
            if(isalpha(c)) {
                //Converting character to lowercase and marking its occurrence.
                present[tolower(c) - 'a'] = true;
            }
        }
        
        //Checking if all letters are present in the array.
        for(int i = 0; i < 26; i++) {
            if(!present[i]) {
                return false;
            }
        }
        
        return true;
    }

};
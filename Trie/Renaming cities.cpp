class Solution
{
    public:
    void insertInTrie(Node *root, string s)
    {
        for(int i = 0;i<=s.length()-1;i++)
        {
            if(root->mp[s[i]] == NULL){
                root->mp[s[i]] = newNode();
            }
            root = root->mp[s[i]];
        }
        root->isEndOfWord = true;
    }
    int searchInTrie(Node *root, string s)
    {
        int i;
        for( i = 0;i<s.length()-1; i++){
            if(root->mp[s[i]] == NULL){
                return i;
            }
            root = root->mp[s[i]];
        }
        
        if(root->isEndOfWord == false)
        return i;
        
        return INT_MAX;
    }
    
    void check(string *arr, int n) 
    {
        map<string,int> mp;
        Node *root = newNode();
        for(int i = 0;i<n;i++)
        {
            int k = searchInTrie(root, arr[i]); 
            string s = arr[i];
            if(k == INT_MAX)
            { 
                mp[s]++; 
                cout << s;
                    
                if(mp[s] > 1)
                    cout << " " << mp[s];
                cout << endl;
            }
            else
            {
                for(int j = 0;j<=k;j++){ 
                    cout << s[j];
                }
                insertInTrie(root, s); 
                mp[s]++;
                if(mp[s] > 1)
                    cout << " " << mp[s];
                cout << endl;
            }
        }
    }
};
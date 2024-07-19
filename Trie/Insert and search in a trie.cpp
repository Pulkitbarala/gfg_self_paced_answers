class Solution
{
    public:
        void insert(struct TrieNode *root, string key)
        {
            struct TrieNode *pCrawl = root;
            
            for (int level = 0; level < key.length(); level++) {
                int index = CHAR_TO_INDEX(key[level]);
                if (!pCrawl->children[index]) {
                    pCrawl->children[index] = getNode();
                }
                pCrawl = pCrawl->children[index];
            }
            pCrawl->isLeaf = true;
        }
        bool search(struct TrieNode *root, string key) 
        {
            struct TrieNode *pCrawl = root;
            
            for (int level = 0; level < key.length(); level++) {
                int index = CHAR_TO_INDEX(key[level]);
                if (!pCrawl->children[index]) {
                    return false;
                }
                pCrawl = pCrawl->children[index];
            }
            return (pCrawl != NULL && pCrawl->isLeaf);
        }
};
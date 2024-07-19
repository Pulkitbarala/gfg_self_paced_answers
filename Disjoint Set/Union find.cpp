class Solution
{
public:
    int find(int x, int par[]) 
    {
        if (par[x] != x) 
        {
            par[x] = find(par[x], par); 
        }
        return par[x];
    }
    void union_(int a, int b, int par[], int rank1[]) 
    {
        int rootA = find(a, par);
        int rootB = find(b, par);

        if (rootA != rootB) 
        {
            if (rank1[rootA] > rank1[rootB]) 
            {
                par[rootB] = rootA;
            } 
            else if (rank1[rootA] < rank1[rootB]) 
            {
                par[rootA] = rootB;
            } 
            else 
            {
                par[rootB] = rootA;
                rank1[rootA]++;
            }
        }
    }
    bool isConnected(int x, int y, int par[], int rank1[]) 
    {
        return find(x, par) == find(y, par);
    }
};

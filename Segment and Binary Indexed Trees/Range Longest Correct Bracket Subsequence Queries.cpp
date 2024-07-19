class Solution
{
    public:
    int getLongestSequence(Node* st, string str, int qs, int qe, int n) 
    {
        return getRangeGCD(st, 0, n - 1, qs, qe, 0).pairs * 2;
    }

    private:
    Node getRangeGCD(Node* st, int ss, int se, int qs, int qe, int si) 
    {
        if (qs <= ss && qe >= se)
            return st[si];
        if (se < qs || ss > qe)
            return Node();

        int mid = getMid(ss, se);
        Node leftChild = getRangeGCD(st, ss, mid, qs, qe, 2 * si + 1);
        Node rightChild = getRangeGCD(st, mid + 1, se, qs, qe, 2 * si + 2);

        return merge(leftChild, rightChild);
    }
};
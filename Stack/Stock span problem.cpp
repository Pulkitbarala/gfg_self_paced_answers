class Solution
{
public:
    vector<int> calculateSpan(int price[], int n)
    {
        vector<int> span(n);
        stack<int> s;

        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && price[s.top()] <= price[i])
            {
                s.pop();
            }
            span[i] = (s.empty()) ? (i + 1) : (i - s.top());

            s.push(i);
        }

        return span;
    }
};
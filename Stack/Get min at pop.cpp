stack<int> minStack;
stack<int> _push(int arr[],int n)
{
    stack<int> s;
    for (int i = 0; i < n; ++i) {
        s.push(arr[i]);
        
        if (minStack.empty()) {
            minStack.push(arr[i]);
        } else {
            minStack.push(min(minStack.top(), arr[i]));
        }
    }
    
    return s;
}
void _getMinAtPop(stack<int>s)
{
    while (!s.empty()) {
        s.pop();
        cout << minStack.top() << " ";
        minStack.pop();
    }
}

stack<int> _push(int arr[], int n) {
    stack<int> s;
    for (int i = n - 1; i >= 0; i--) {
        s.push(arr[i]);
    }
    return s;
}

void _getMinAtPop(stack<int> s) {
    stack<int> minStack;
    
    while (!s.empty()) {
        minStack.push(min(minStack.empty() ? INT_MAX : minStack.top(), s.top()));
        s.pop();
    }

    while (!minStack.empty()) {
        cout << minStack.top() << " ";
        minStack.pop();
    }
}
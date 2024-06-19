void StackQueue::push(int x) {
    s1.push(x);
}

int StackQueue::pop() {
    if (s2.empty()) {
        if (s1.empty()) {
            return -1;
        }
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }
    int topElement = s2.top();
    s2.pop();
    return topElement;
}
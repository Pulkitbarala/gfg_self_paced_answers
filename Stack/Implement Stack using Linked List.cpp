void MyStack::push(int x) {
    StackNode* newNode = new StackNode(x);
    newNode->next = top;
    top = newNode;
}

int MyStack::pop() {
    if (top == NULL) {
        return -1;
    } else {
        int poppedElement = top->data;
        StackNode* temp = top;
        top = top->next;
        delete temp;
        return poppedElement;
    }
}
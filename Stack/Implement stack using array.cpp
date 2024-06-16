void MyStack::push(int x)
{
    if (top < 999) {
        top++;
        arr[top] = x;
    }
}

int MyStack::pop()
{
    if (top == -1) {
        return -1;
    } else {
        int poppedElement = arr[top];
        top--;
        return poppedElement;
    }
}
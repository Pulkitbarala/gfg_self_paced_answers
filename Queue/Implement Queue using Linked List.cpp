void MyQueue::push(int x) {
    QueueNode* newNode = new QueueNode(x);
    if (rear == NULL) {
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}

int MyQueue::pop() {
    if (front == NULL) {
        return -1;
    }
    QueueNode* temp = front;
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }
    int poppedValue = temp->data;
    delete temp;
    return poppedValue;
}
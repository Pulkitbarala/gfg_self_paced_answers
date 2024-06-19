void left_Rotate_Deq_ByK(deque<int> &deq, int n, int k)
{
    k = k % n;
    for(int i = 0; i < k; i++) {
        deq.push_back(deq.front());
        deq.pop_front();
    }
}

void right_Rotate_Deq_ByK(deque<int> &deq, int n, int k)
{
    k = k % n;
    for(int i = 0; i < k; i++) {
        deq.push_front(deq.back());
        deq.pop_back();
    }
}
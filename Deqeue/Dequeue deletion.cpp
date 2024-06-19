void eraseAt(deque <int> &deq, int X)
{
    if (X >= 0 && X < deq.size()) {
        deq.erase(deq.begin() + X);
    }
}

void eraseInRange(deque<int> &deq, int start, int end)
{
    if (start < end && start >= 0 && end <= deq.size()) {
        deq.erase(deq.begin() + start, deq.begin() + end);
    }
}

void eraseAll(deque<int> &deq)
{
   deq.clear();
}
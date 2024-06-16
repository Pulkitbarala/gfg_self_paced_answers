class Solution {
public:
    void deleteMiddleHelper(stack<int>& s, int currentIndex, int middleIndex) {
        if (currentIndex == middleIndex) {
            s.pop();
            return;
        }
        
        int temp = s.top();
        s.pop();
        
        deleteMiddleHelper(s, currentIndex + 1, middleIndex);
        
        s.push(temp);
    }

    void deleteMid(stack<int>& s, int sizeOfStack) {
        int middleIndex = sizeOfStack / 2;
        deleteMiddleHelper(s, 0, middleIndex);
    }
};
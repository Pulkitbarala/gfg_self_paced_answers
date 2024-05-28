//User-function template for C++

// Complete the function
// n: Input n
// Return True if the given number is a lucky number else return False

class Solution{
public:
    bool isLucky(int n) {
        int position = n;
        int counter = 2;
        
        while (position >= counter) {
            if (position % counter == 0) {
                return false;
            }
            position -= position / counter;
            counter++;
        }
        return true;
    }
};
class Solution {
public:
    int diameter(Node* root) {
        int max_diameter = 0;
        calculateDiameter(root, max_diameter);
        return max_diameter;
    }
    
private:
    int calculateDiameter(Node* root, int &max_diameter) {
        if (root == NULL) {
            return 0;
        }
        
        int left_height = calculateDiameter(root->left, max_diameter);
        int right_height = calculateDiameter(root->right, max_diameter);
        
        int current_diameter = left_height + right_height + 1;
        
        max_diameter = max(max_diameter, current_diameter);
        
        return max(left_height, right_height) + 1;
    }
};
class Solution{
public:
    int height(Node* node){
        if(node == nullptr){
            return 0;
        }
        return max(height(node->left),height(node->right)) +1;
    }
};

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N) 
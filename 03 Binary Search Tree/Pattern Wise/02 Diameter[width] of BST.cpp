// longest path between any two nodes

class Solution {
private:
    int height(Node* node){
        if(node == nullptr){
            return 0;
        }
        return max(height(node->left),height(node->right)) +1;
    }
public:
    int diameter(Node* root) {
        if(root == nullptr){
            return 0;
        }
        int left_sub = diameter(root->left);
        int right_sub = diameter(root->right);
        int right_left = height(root->left) + height(root->right) + 1;
        return max({left_sub,right_sub,right_left});
    }
};

//optimal solution


class Solution {
private:
    pair<int,int> Diameter_height(Node* node){
        if(node == nullptr){
            return make_pair(0,0);
        }
        pair<int,int> left = Diameter_height(node->left);
        pair<int,int> right = Diameter_height(node->right);
        
        int l_h = left.first;
        int r_h = right.first;
        int lr_h = left.second + right.second +1;
        return make_pair( max({l_h,r_h,lr_h}) , max(left.second , right.second)+1 );
    }
public:
    int diameter(Node* root) {
        return Diameter_height(root).first;
    }
};
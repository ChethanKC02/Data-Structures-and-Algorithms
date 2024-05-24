// Input: n = 13
// Output: [1,10,11,12,13,2,3,4,5,6,7,8,9]

class Solution {
private:
    vector<int> v;

    struct Node{
        Node *child[10];
        bool isnum;
        Node(){
            isnum = false;
            for(int i=0;i<10;i++) child[i] = nullptr;
        }
    };
    Node *root = new Node();

    void insert(string word){
        Node *trav = root;
        for(char c:word){
            if(trav->child[c-'0'] == nullptr){
                trav->child[c-'0'] = new Node(); 
            }
            trav = trav->child[c-'0'];
        }
        trav->isnum = true;
    }

    void dfs(Node *root, int val ){
       for(int i=0;i<10;i++){
            if(root->child[i]){
                v.push_back(val*10+i);
                dfs(root->child[i],val*10+i);
            }
        }
    }

public:
    vector<int> lexicalOrder(int n) {
        for(int i=1;i<=n;i++) insert(to_string(i));
        dfs(root,0);
        return v;       
    }
};
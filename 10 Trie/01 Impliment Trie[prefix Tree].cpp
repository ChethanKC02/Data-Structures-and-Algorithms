class Node{
    public:
    Node *child[26];
    bool isWord;
    Node(){
        isWord = false;
        for(auto &a:child) a = nullptr;
    }
};

class Trie {
    Node *root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *trav = root;
        int ch;
        for(char c:word){
            ch = c- 'a';
            if(trav->child[ch] == nullptr){
                trav->child[ch] = new Node();
            }
            trav = trav->child[ch];
        }
        trav->isWord = true;
    }
    
    bool search(string word) {
        Node *trav = root;
        int ch;
        for(char c:word){            
            ch = c- 'a';
            if(trav->child[ch]){
                trav = trav->child[ch];
            }
            else{
                return false;
            }
        }
        return trav->isWord;
    }
    
    bool startsWith(string prefix) {
        Node *trav = root;
        int ch;
        for(char c:prefix){
            ch = c - 'a';
            if(trav->child[ch]){
                trav = trav->child[ch];
            }
            else{
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
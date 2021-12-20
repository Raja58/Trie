/ <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        20 Dec 2021
//  @Detail  :        Implement Trie (Prefix Tree) (LeetCode)
//  ============================
//  -->

struct Node{
        Node *link[26];
        bool isEnd;
        Node() {
            for(int i = 0; i < 26; i++)
                link[i] = NULL;
            isEnd = false;
        }
        
        bool contains(int x){
            return link[x] != NULL;
        }
    };

class Trie {
    
private:
    Node *root;
    
public:
    
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *temp = root;
        for(int i = 0; i < word.size(); i++)
        {
            if(!temp -> contains(word[i] - 'a'))
                temp -> link[word[i] - 'a'] = new Node();
            temp = temp -> link[word[i] - 'a'];
        }
        temp -> isEnd = true;
    }
    
    bool search(string word) {
        Node *temp = root;
        for(int i = 0; i < word.size(); i++)
        {
            if(!temp -> contains(word[i] - 'a'))
                return false;
            temp = temp -> link[word[i] - 'a'];
        }
        return temp -> isEnd;
    }
    
    bool startsWith(string word) {
        Node *temp = root;
        for(int i = 0; i < word.size(); i++)
        {
            if(!temp -> contains(word[i] - 'a'))
                return false;
            temp = temp -> link[word[i] - 'a'];
        }
        return true;
    }
};

/ <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        20 Dec 2021
//  @Detail  :        Design Add and Search Words Data Structure (LeetCode)
//  ============================
//  -->

class WordDictionary {
    struct Node{
        Node *link[26];
        bool isEnd;
        Node(){
            for(int i = 0; i < 26; i++)
                link[i] = NULL;
            isEnd = false;
        }
        
        bool contains(char &c){
            return link[c - 'a'];
        }
    };
private:
    Node *root;
public:
    WordDictionary() {
        root = new Node;
    }
    
    void addWord(string word) {
        Node *temp = root;
        for(int i = 0; i < word.size(); i++)
        {
            if(!temp -> contains(word[i]))
                temp -> link[word[i] - 'a'] = new Node();
            temp = temp -> link[word[i] - 'a'];
        }
        temp -> isEnd = true;
    }
    
    bool isFound(int idx, string &word, Node *root)
    {
        if(idx == word.size())
            return root -> isEnd;
        
        if(word[idx] != '.')
        {
            if(!root -> contains(word[idx]))
                return false;
            return isFound(idx + 1, word, root -> link[word[idx] - 'a']);
        }
        
        for(int i = 0; i < 26; i++)
            if(root -> link[i])
                if(isFound(idx + 1, word, root -> link[i]))
                    return true;
        return false;
    }
    
    bool search(string word) {
        Node *temp = root;
        return isFound(0, word, root);
    }
};

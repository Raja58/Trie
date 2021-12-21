// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        21 Dec 2021
//  @Detail  :        Replace Words (LeetCode)
//  ============================
//  -->

class Solution {
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
        
public:
    Node *root = new Node();
    
    void insert(string &str)
    {
        Node *temp = root;
        for(int i = 0; i < str.size(); i++)
        {
            if(!temp -> contains(str[i]))
                temp -> link[str[i] - 'a'] = new Node();
            temp = temp -> link[str[i] - 'a'];
        }
        temp -> isEnd = true;
    }
    
    string getRootWord(string &word)
    {
        Node *temp = root;
        for(int i = 0; i < word.size(); i++)
        {
            if(!temp -> contains(word[i]))
                return word;
            temp = temp -> link[word[i] - 'a'];
            if(temp ->isEnd)
                return word.substr(0, i + 1);
        }
        return word;
    }
    
    string replaceWords(vector<string>& dictionary, string sentence) {
        for(int i = 0; i < dictionary.size(); i++)
            insert(dictionary[i]);
        
        string word, result = "";
        stringstream ss(sentence);
        while(getline(ss, word, ' '))
        {
            result += getRootWord(word) + ' ';
        }
        result.pop_back();
        return result;
    }
};

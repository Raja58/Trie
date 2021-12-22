// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        22 Dec 2021
//  @Detail  :        Remove Sub-Folders from the Filesystem (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    struct Node{
        unordered_map<string, Node *> link;
        bool isEnd;
        Node(){
            isEnd = false;
        }
        
        bool contains(string str){
            return link[str];
        }
    };
    
    Node *root = new Node();
    
    vector<string> getSeparate(string str)
    {
        vector<string> result;
        
        str = str.substr(1);
        stringstream ss(str);
        string word;
        
        while(getline(ss, word, '/'))
            result.push_back(word);
        return result;
    }
    
    bool isSubFolder(vector<string> &folder)
    {
        Node *temp = root;
        for(int i = 0; i < folder.size(); i++)
        {
            if(!temp -> contains(folder[i]))
                temp -> link[folder[i]] = new Node();
            temp = temp -> link[folder[i]];
            if(temp -> isEnd)
                return true;
        }
        temp -> isEnd = true;
        return false;
    }
    
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> result;
        sort(folder.begin(),folder.end());
        for(int i = 0; i < folder.size(); i++)
        {
            vector<string> temp = getSeparate(folder[i]);
            if(!isSubFolder(temp))
                result.push_back(folder[i]);
        }
        return result;
    }
};

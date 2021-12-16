// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        16 Dec 2021
//  @Detail  :        Contacts (HackerRank)
//  ============================
//  -->

struct trie{
    trie *arr[26];
    bool isEnd;
    int count;
    trie(){
        for(int i = 0; i < 26; i++)
            arr[i] = NULL;
        isEnd = false;
        count = 0;
    }
};

void addWord(string &str, trie *cache)
{
    trie *root = cache;
    for(int i = 0; i < str.size(); i++)
    {
        int idx = str[i] - 'a';
        if(!root -> arr[idx])
            root -> arr[idx] = new trie();
        root = root -> arr[idx];
        root -> count++;
    }
    root -> isEnd = true;
}

int getCnt(string &str, trie *&cache)
{
    trie *temp = cache;
    for(int i = 0; i < str.size(); i++)
    {
        int idx = str[i] - 'a';
        if(!temp -> arr[idx])
            return 0;
        else
            temp = temp -> arr[idx];
    }
    
    return temp -> count;
}

vector<int> contacts(vector<vector<string>> queries) {
    vector<int> result;
    trie *cache = new trie();
    for(auto &x : queries)
        if(x[0] == "add")
            addWord(x[1], cache);
        else
            result.push_back(getCnt(x[1], cache));
    return result;
}

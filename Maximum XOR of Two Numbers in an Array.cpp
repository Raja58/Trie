// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        22 Dec 2021
//  @Detail  :        Maximum XOR of Two Numbers in an Array (LeetCode)
//  ============================
//  -->

class Solution {
public:
    struct Node{
        Node *link[2];
        Node(){
            link[0] = link[1] = NULL;
        }
        
        bool contains(int x){
            return link[x];
        }
    };
    
    void insert(Node *root, int &num)
    {
        Node *temp = root;
        for(int i = 31; i >= 0; i--)
        {
            int poten = (1 << i) & num ? 1 : 0;
            if(!temp -> contains(poten))
                temp -> link[poten] = new Node();
            temp = temp -> link[poten];
        }
    }
    
    int getMaxXor(Node *root, int &num)
    {
        int result = 0;
        Node *temp = root;
        for(int i = 31; i >= 0; i--)
        {
            int isSet = (1 << i) & num ? 1 : 0;
            if(temp -> contains(!isSet))
            {
                result |= (1 << i);
                temp = temp -> link[!isSet];
            }
            else
                temp = temp -> link[isSet];
        }
        return result;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        Node *root = new Node();
        for(int i = 0; i < nums.size(); i++)
            insert(root, nums[i]);
        
        int result = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            int temp = getMaxXor(root, nums[i]);
            if(temp > result)
                result = temp;
        }
        return result;
    }
};

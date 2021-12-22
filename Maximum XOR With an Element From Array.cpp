// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        22 Dec 2021
//  @Detail  :        Maximum XOR With an Element From Array (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    struct detail{
        int val;
        int maxi;
        int idx;
    };
    
    struct Node{
        Node *link[2];
        Node(){
            link[0] = link[1] = NULL;
        }
        
        bool contains(int x){
            return link[x];
        }
    };
    
    void insert(Node *temp, int &num)
    {
        for(int i = 31; i >= 0; i--)
        {
            int bit = 1 & (num >> i);
            if(!temp -> contains(bit))
                temp -> link[bit] = new Node();
            temp = temp -> link[bit];
        }
    }
    
    int getMaxXor(int num, Node *root)
    {
        Node *temp = root;
        int result = 0;
        for(int i = 31; i >= 0; i--)
        {
            int bit = 1 & (num >> i);
            if(temp -> contains(!bit))
            {
                result |= (1 << i);
                temp = temp -> link[!bit];
            }
            else
                temp = temp -> link[bit];
        }
        return result;
    }
    
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<detail> input(n);
        for(int i = 0; i < n; i++)
        {
            input[i].val = queries[i][0];
            input[i].maxi = queries[i][1];
            input[i].idx = i;
        }
        
        sort(input.begin(), input.end(), [](detail &x, detail &y) { return x.maxi < y.maxi;});
        sort(nums.begin(), nums.end());
        
        vector<int> result(n);
        Node *root = new Node();
        int idx = 0;
        for(int i = 0; i < n; i++)
        {
            int start = idx;
            while(idx < nums.size() && nums[idx] <= input[i].maxi)
                idx++;
            
            if(start != idx)
            {
                for(int j = start; j < idx; j++)
                    insert(root, nums[j]);
            }
            
            if(idx == 0)
            {
                result[input[i].idx] = -1;
                continue;
            }
            
            result[input[i].idx] = getMaxXor(input[i].val, root);
        }
        return result;
    }
};

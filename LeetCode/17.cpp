// LeetCode 17. Letter Combinations of a Phone Number
class Solution {
public:
    string arr[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz",};
    vector <string> ans;
    
    
    void dfs(string s ,string digits, int n){
        
        int num = digits[n]-'0';
        
        if( n== digits.size()-1 ) 
        {
            for(int i=0; i<arr[num].size(); i++) 
                ans.push_back(s+arr[num][i]);
            return;
        }
        
        
        for(int i=0; i<arr[num].size(); i++)
        {
            string tmp = s+arr[num][i];
            dfs(tmp, digits, n+1);
            
        }
        
    }
    vector<string> letterCombinations(string digits) 
    {
        
        if(digits!="")
            dfs("",digits,0);
        return ans;
        
    }
};

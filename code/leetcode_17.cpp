#include<string>
#include<iostream>
#include<vector>
#include<functional>
using namespace std;

    string get_c(int x){
        switch(x)
        {
            case 2:return "abc";
            case 3:return "def";
            case 4:return "ghi";
            case 5:return "jkl";
            case 6:return "mno";
            case 7:return "pqrs";
            case 8:return "tuv";
            case 9:return "wxyz";
            default: return"";
        }

    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string path;
        int size=digits.size();
        if (size==0)
        return ans;
        std::function<void(int)> dfs=[&](int i){
            if(path.size()==size){
                ans.push_back(path);
                return;
            }
            string temp=get_c(digits[i]-'0');
            for(int j=0;j<temp.size();j++){
                path+=temp[j];
                dfs(i+1);
                path.pop_back();
            }
        };
        dfs(0);
        return ans;
    }



int main() {
  string s="23";
  letterCombinations(s);
  return 0;
}
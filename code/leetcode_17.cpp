#include<iostream>
#include<vector>
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
void dfs(string dig,int i,int size,string path,vector<string> &ans){
    if(i==size){
        ans.push_back(path);
        return ;
    }
    path.push_back(' ');
    string s=get_c(dig[i]-'0');
    for(int k=0;k<s.size();k++){
        path[i]=s[k];
        dfs(dig,i+1,size,path,ans);
    }
}
vector<string> letterCombinations(string digits) {
    vector<string> ans;
    int size=digits.size();
    if (size==0)
    return ans;
    string path;
    dfs(digits,0,size,path,ans);
    return ans;
}

int main(){
    string digits;
    cin>>digits;
    letterCombinations(digits);
    return 0;
}
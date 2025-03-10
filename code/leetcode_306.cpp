#include<iostream>
#include<vector>
#include<string>
#include<functional>

using namespace std;

bool is_num(string s){
    if(s.size()==1){
        return true;
    }
    if(s[0]=='0')
    return false;
    return true;
}
bool isAdditiveNumber(string num) {
    vector<int> path;
    int size=num.size();
    bool  ans=false;
    function<void(int)> dfs=[&](int left){
        if(left==size&&path.size()>2){
            ans=true;
            return;
        }
        for(int right=left+1;right<=size;right++){
            string s=num.substr(left,right-left);
            int temp=-1;
            if(is_num(s)){
                temp=stoi(s);
            }
            if(temp==-1)
            continue;
            int p_size=path.size();
            if(p_size<2){
                path.push_back(temp);
                dfs(right);
                path.pop_back();
            }else{
                if(path[p_size-2]+path[p_size-1]==temp){
                    path.push_back(temp);
                    dfs(right);
                    path.pop_back();
                }else if(path[p_size-2]+path[p_size-1]<temp){
                    break;
                }
            }
        }
    };

    dfs(0);
    return ans;
}

int main(){
    string s;
    cin>>s;
    isAdditiveNumber(s);
    return 0;
}
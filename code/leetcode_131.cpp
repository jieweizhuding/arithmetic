#include<iostream>
#include<vector>
#include<functional>
#include<string>
using namespace std;

bool is_pa(string t){
    int x=0,y=t.size()-1;
    while(x<y){
        if(t[x]!=t[y]){
            return false;
        }
        x++;
        y--;
    }
    return true;
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> path;
    
    int size=s.size();

    function<void(int)> dfs=[&](int left){
        if(left==size){
            ans.push_back(path);
            return;
        }
        for(int j=left;j<size;j++){
            string temp=s.substr(left,j-left+1);
            if(is_pa(temp)){
                path.push_back(temp);
                dfs(j+1);
                path.pop_back();
            }
        }
    };

    dfs(0);
    return ans;
}


int main(){
    string s;
    cin>>s;
    partition(s);
    return 0;
}
#include<iostream>
#include<vector>
#include<functional>
#include<string>
using namespace std;


int toi(string s){
    int x=0,y=s.size();
    while(s[x]=='0'){
        x++;
    }
    if(x==y){
        return 0;
    }else{
        s=s.substr(x,y-x);
        return stoi(s);
    }
}

vector<string> restoreIpAddresses(string s) {
    vector<string> ans;
    vector<string> path;
    int size=s.size();
    function<void(int)> dfs=[&](int left){
        if(path.size()>4){
        return;
    }
    if(path.size()==4){
        if(left==size){
            string t;
            t+=path[0];
            for(int k=1;k<4;k++){
                t+='.';
                t+=path[k];
            }
            cout<<t<<endl;
            ans.push_back(t);
        }
        return;
    }
        for(int right=left+1;right<=left+3&&right<=size;right++){
            string s_temp=s.substr(left,right-left);
            int temp=toi(s_temp);
            if(temp<255){
                path.push_back(s_temp);
                dfs(right);
                path.pop_back();
            }else
            continue;
        }
    };

    dfs(0);
    return ans;
}





int main(){
    string s;
    cin>>s;
    restoreIpAddresses(s);
    return 0;
}
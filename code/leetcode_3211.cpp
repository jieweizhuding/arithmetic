#include<iostream>
#include<vector>
#include<string>
#include<functional>


using namespace std;


vector<string> validStrings(int n) {
    vector<string> ans;
    string path;
    function<void()> dfs=[&](){
        if(path.size()==n){
            ans.push_back(path);
            return;
        }
        for(int i=0;i<2;i++){
            if(!path.empty()){
                if(path.back()=='0'){
                    if(i==0){
                        continue;
                    }
                }
            }
            path.push_back(i+'0');
            dfs();
            path.pop_back();
        }
    };

    dfs();
    return ans;
}

int main(){
    int x;
    cin>>x;
    validStrings(x);
    return 0;
}
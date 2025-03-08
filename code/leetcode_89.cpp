#include<iostream>
#include<vector>
using namespace std;


bool f(int x,int y){
    int diff = x ^ y; // 计算 x 和 y 的二进制差异
// 判断 diff 是否只有一个 1（即是否是 2 的幂）
return diff != 0 && (diff & (diff - 1)) == 0;
}

vector<int> grayCode(int n) {
    bool find_ans=false;
    vector<int> path;
    path.push_back(0);
    vector<bool> visited(1<<n,false);
    visited[0]=true;
    auto dfs=[&](this auto&& dfs,int i)->void{
        if(find_ans){
            return;
        }
        if(path.size()==(1<<n)){
            if(f(path[i-1],0)){
                find_ans=true;
            }
            return;
        }
        for(int j=1;j<(1<<n);j++){
            if(visited[j]){
                continue;
            }
            if(!f(j,path.back())){
                continue;
            }
            path.push_back(j);
            visited[j]==true;
            dfs(i+1);
            if(find_ans){

            break;
            }
            path.pop_back();
            visited[j]=false;
        }
    };
    dfs(0);
    return path;
}

int main(){
    int n;
    cin>>n;
    grayCode(n);
}
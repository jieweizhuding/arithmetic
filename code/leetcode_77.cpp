#include<iostream>
#include<vector>
using namespace std;


vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int > path;
    auto dfs=[&]( this auto&& dfs,int i)->void{
        if(i==k+1){
            ans.push_back(path);
            return ;
        }
        for(int j=i;j<=n;j++){
            path.push_back(j);
            dfs(i+1);
            path.pop_back();
        }
    };
    dfs(1);
    return ans;

}
int main(){
    int n,k;
    cin>>n>>k;
    combine(n,k);
    return 0;
}
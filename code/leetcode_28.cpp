#include<iostream>
#include<vector>
using namespace std;

vector<int> get_next_array(string needle){
    vector<int> next;
    next.push_back(-1);
    next.push_back(0);
    for(int i=2;i<needle.size();i++){
        int j=i;
        while(j>0){
            int k=next[j-1];
            if(k==-1){
                next.push_back(0);
                j=0;
                continue;
            }
            if(needle[i-1]==needle[k]){
                next.push_back(k+1);
                j=0;
                continue;
            }else{
                j=k+1;
            }
        }
    }
    return next;
}

int KMP(string haystack,string needle){
    if(haystack.size()<needle.size()){
        return -1;
    }
    vector<int> next=get_next_array(needle);
    int i=0;
    int j=0;
    while(i<haystack.size()){
        if(haystack[i]==needle[j]){
            i++;
            j++;
        }else{
            if(j==0)i++;
            else{
                int z=next[j];
                while((needle[j]==needle[z])&& (z!=0)){
                    z=next[z];
                }
                j=z;
                }
            }
        if(j==needle.size()){
            return i-j;
        }
    }
    return -1;
}
int main(){
    string haystack,needle;
    cin>>haystack;
    cin>>needle;
    int ans=KMP(haystack,needle);
    cout<<ans;
    return 0;
}
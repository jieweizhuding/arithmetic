/**
 * 该问题是动态规划问题，
 * 动态规划问题的解决方法是：
 * 1.可视化（DAG）
 * 2.找到子问题
 * 3.确定子问题间的关系
 *  3.1 找到子问题的解决顺序
 *  3.2 确保所有的子问题都可以被求出
 * 4.得到previous数组
 * 
 * 
 * 
 * 接下来我们一步步考虑：
 * 我们能做的操作是切开字符串，不同的切口对应不同的结果。
 * 第一步是将其可视化，一般映射为DAG，
 * 因为题中没有明确指出有向性，所以我们考虑操作自身的有向性，即第二刀的结果依赖于第一刀的位置
 * 这也是dp问题的鲜明特点（依赖性）。
 * 接下来考虑剪枝操作，容易想到可以规定后面的切口必须在前面的切口的右边。
 * 第一步的作用正是为第二步铺垫，当第一步结束后，第二步就显而易见了。
 * 子问题1：第一刀切在哪里？是第一个使得左侧字符串回文的位置还是后面有更好的位置？
 * -有多种结果
 * 子问题2：第二刀切在哪里？需要且仅需要子问题1的结果。
 * 子问题3：……需要且仅需要1,2的结果
 * ……
 * 此时该题可解，如果需要得到最后的具体结果，可以添加previous数组。
 */



 //TODO: 题目理解错误，需要完全重写。
 /*
 错误原因：将记忆化搜索DP当成了递推DP，没有能力完成
 */
 #include<iostream>
 #include<vector>
using namespace std;

int dp_f(string s){
    
}

vector<int> check_Palindrome(string s,int begin){
    vector<int> Palindrome;
    int size=s.size();
    int i=begin;
    for(int end=begin+1;end<size;end++){
        int j=end;
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }else{
                j=-1;
            }
        }
        if(j!=-1){
            Palindrome.push_back(end);
        }
    }
}


int main(){
    string s;
    cin>>s;



}

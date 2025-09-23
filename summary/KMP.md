因为一道题需要用到KMP算法，故复习了一下。
KMP算法的精髓在于添加了next数组，因此理解next数组的意义就是该算法的核心。

这里我们称等待被匹配的较长的字符串为目标字符串，用于匹配的短的字符串为模板字符串。
#### next数组的定义大致为：
next[i]=k，即模板字符串的前i位(意为当前在第i位的字符串不用被考虑进去)的子字符串的最大前缀与后缀的重合长度，如
 a a b c a a b
-1 0 1 0 0 1 2

#### 首先KMP算法的大致流程为：
用i,j两个索引分别指向目标字符串和模板字符串的头的位置，并比较对应位置的元素是否相同，如果相同则i,j同时自增1个单位，若不同，则i不变，j=next[j]，并重现开始比较，重复以上流程。
若j=-1，则i++，j++。当i达到目标字符串的尾部时依然没有对应成功，则没有模板字符串。

#### 我们考虑next数组怎么求解：
由定义可知next[0]=-1,next[1]=0,
假设
$$
next[j-1]=k
$$
$$
[\underline{a_0\ a_1\ a_2\ ...\ a_{k-1}}\ a_k\ ......\underline{a_{j-k-1}\ ...\ a_{j-2}}\ a_{j-1}\ a_j]
$$
画下划线的部分完全相同

1. 若$arr[j-1]=arr[k]$，
则$next[j]=k+1$
2. 若$arr[j-1]\neq arr[k]$，
则令j=k，并重新执行1,2步

接下来我们说明这么做的正确性：
主要的问题集中在第二步，即递归导致的复杂性。
为什么令j=k？
1. 若j=m>k，即存在一个m使得前缀与后缀的最大重合长度为m，又因为m>k，则next[j-1]=m>k，矛盾。
2. 若j<k,我们在这里就不做完整的证明了，具体的证明可以看看这位大佬的
https://blog.csdn.net/sunnianzhong/article/details/8802559
这里因为我们知道j不会大于k，故在递归过程中j单调递减，
又知道当j=k时完全有可能结束，即j最终结果可以为k，故直接取j<k会丢失这一可能性。
综上，令j=next[j-1]为每步的最优解，且为全局的最优解。


#### 最终优化
以上的结论与代码已经足够实现目标了，但也有一点足以优化的地方。
目标：aaaacaaaab
模板：aaaab
         i
         j
当ij在如上位置时，j=next[j],但是arr[next[j]]==arr[j]，我们可以轻易发现
即使j=next[j]，此时也一定无法匹配上，因为arr[i]!=arr[j]==arr[next[j]]
所以可以在更新j前对arr[j]是否等于arr[next[j]]进行判断，如果等于，则另j=next[next[j]],并一直判断，直到两者不相等或j=0。



可以看例题leetcode 28
写代码时最好使用例子a b a b c a b a b d辅助索引的判断
```C++
class Solution {
public:
    //可以使用a b a b c a b a b d
    //       0 0 1 2 0 1 2 3 4 i
    //我们在考虑第i位时，比较其与第v[i-1]位(index为4->c)，发现不同
    //那么我们知道v[i]>4,用同样的方法考虑v[v[i-1]-1]->v[3]=2
    //再考虑index=2处，以此类推，直到相等或发现v[i]=0
    void get_next(string s,vector<int>& v){
        int i=1,j=0;
        v[0]=0;
        while(i<s.size()){
            if(s[i]==s[v[i-1]]){
                v[i]=v[i-1]+1;
            }else{
                j=v[i-1]-1;
                while(j>=0){
                    if(s[i]==s[v[j]]){
                        v[i]=v[j]+1;
                        break;
                    }else{
                        j=v[j]-1;
                    }
                }
                if(j<0)v[i]=0;
            }
            i++;
        }
    }
    int strStr(string haystack, string needle) {
        vector<int> next(needle.size());
        get_next(needle,next);

        int i=0,j=0;
        while(i<haystack.size()&&j<needle.size()){
            if(haystack[i]==needle[j]){
                i++;
                j++;
            }else{
                if(j==0){
                    i++;
                    continue;
                }
                j=next[j-1];
            }
        }
        
        if(j==needle.size()){
            return i-j;
        }else return -1;
    }
};
```
/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start

#include <string>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
    首先看到题目考虑存储，处理，输出三部分。
    存储：将一个【字符串】存储到【链表】中
        ##条件：
        链表：节点数在【1，100】内，value在【0，9】内
        ##思路：
        ①字符串转数组
            字符串去除除数字外的字符
            字符串去首位0
        ②数组转链表
*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        std::string s;
    }

    ListNode* arr_to_list(){

    }
};
// @lc code=end


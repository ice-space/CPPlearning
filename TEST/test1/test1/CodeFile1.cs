
/*反转链表
public ListNode ReverseList(ListNode head)
{
    //新链表
    ListNode newHead = null;
    while (head != null)
    {
        //先保存访问的节点的下一个节点，保存起来
        //留着下一步访问的
        ListNode temp = head.next;
        //每次访问的原链表节点都会成为新链表的头结点，
        //其实就是把新链表挂到访问的原链表节点的
        //后面就行了
        head.next = newHead;
        //更新新链表
        newHead = head;
        //重新赋值，继续访问
        head = temp;
    }
    //返回新链表
    return newHead;
} */

//链表内指定区间反转
using System;
using System.Collections.Generic;
using System.Windows.Forms;

class Solution
{
    public:
    ListNode* reverseBetween(ListNode* head, int m, int n)
    {
        //加个表头
        ListNode* res = new ListNode(-1);
        res->next = head;
        //前序节点
        ListNode* pre = res;
        //当前节点
        ListNode* cur = head;
        //找到m
        for (int i = 1; i < m; i++)
        {
            pre = cur;
            cur = cur->next;
        }
        //从m反转到n
        for (int i = m; i < n; i++)
        {
            ListNode* temp = cur->next;
            cur->next = temp->next;
            temp->next = pre->next;
            pre->next = temp;
        }
        //返回去掉表头
        return res->next;
    }
};

//链表中的节点每k个一组翻转
class Solution
{
    public:
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        //找到每次翻转的尾部
        ListNode* tail = head;
        //遍历k次到尾部
        for (int i = 0; i < k; i++)
        {
            //如果不足k到了链表尾，直接返回，不翻转
            if (tail == NULL)
                return head;
            tail = tail->next;
        }
        //翻转时需要的前序和当前节点
        ListNode* pre = NULL;
        ListNode* cur = head;
        //在到达当前段尾节点前
        while (cur != tail)
        {
            //翻转
            ListNode* temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        //当前尾指向下一段要翻转的链表
        head->next = reverseKGroup(tail, k);
        return pre;
    }
};

#合并k个已排序的链表#
class Solution
{
    public:
    //两个有序链表合并函数
    ListNode* Merge2(ListNode* pHead1, ListNode* pHead2)
    {
        //一个已经为空了，直接返回另一个
        if (pHead1 == NULL)
            return pHead2;
        if (pHead2 == NULL)
            return pHead1;
        //加一个表头
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        //两个链表都要不为空
        while (pHead1 && pHead2)
        {
            //取较小值的节点
            if (pHead1->val <= pHead2->val)
            {
                cur->next = pHead1;
                //只移动取值的指针
                pHead1 = pHead1->next;
            }
            else
            {
                cur->next = pHead2;
                //只移动取值的指针
                pHead2 = pHead2->next;
            }
            //指针后移
            cur = cur->next;
        }
        //哪个链表还有剩，直接连在后面
        if (pHead1)
            cur->next = pHead1;
        else
            cur->next = pHead2;
        //返回值去掉表头
        return head->next;
    }

    //划分合并区间函数
    ListNode* divideMerge(vector<ListNode*> &lists, int left, int right)
    {
        if (left > right)
            return NULL;
        //中间一个的情况
        else if (left == right)
            return lists[left];
        //从中间分成两段，再将合并好的两段合并
        int mid = (left + right) / 2;
        return Merge2(divideMerge(lists, left, mid), divideMerge(lists, mid + 1, right));
    }

    ListNode* mergeKLists(vector<ListNode*> &lists)
    {
        //k个链表归并排序
        return divideMerge(lists, 0, lists.size() - 1);
    }

    //YOUXIAXULIE
    class Solution
    {
        public:
    struct cmp
        {
            //重载小顶堆比较方式
            bool operator()(ListNode* a, ListNode* b) {
        return  a->val > b->val; 
    }
    };
    ListNode* mergeKLists(vector<ListNode*> &lists)
    {
        //小顶堆
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        //遍历所有链表第一个元素
        for (int i = 0; i < lists.size(); i++)
        {
            //不为空则加入小顶堆
            if (lists[i] != NULL)
                pq.push(lists[i]);
        }
        //加一个表头
        ListNode* res = new ListNode(-1);
        ListNode* head = res;
        //直到小顶堆为空
        while (!pq.empty())
        {
            //取出最小的元素
            ListNode* temp = pq.top();
            pq.pop();
            //连接
            head->next = temp;
            head = head->next;
            //每次取出链表的后一个元素加入小顶堆
            if (temp->next != NULL)
                pq.push(temp->next);
        }
        return res->next;
    }
};





//HAS
class Solution
{
    public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        vector<int> res;
        //创建哈希表,两元组分别表示值、下标
        unordered_map<int, int> hash;
        //在哈希表中查找target-numbers[i]
        for (int i = 0; i < numbers.size(); i++)
        {
            int temp = target - numbers[i];
            //若是没找到，将此信息计入哈希表
            if (hash.find(temp) == hash.end())
            {
                hash[numbers[i]] = i;
            }
            else
            {
                //哈希表中记录的是之前的数字，所以该索引比当前小
                res.push_back(hash[temp] + 1);
                res.push_back(i + 1);
                break;
            }
        }
        return res;
    }
};

//数组中只出现一次的两个数字
class Solution
{
    public:
    vector<int> FindNumsAppearOnce(vector<int>& array)
    {
        unordered_map<int, int> mp;
        vector<int> res;
        //遍历数组
        for (int i = 0; i < array.size(); i++)
            //统计每个数出现的频率
            mp[array[i]]++;
        //再次遍历数组
        for (int i = 0; i < array.size(); i++)
            //找到频率为1的两个数
            if (mp[array[i]] == 1)
                res.push_back(array[i]);
        //整理次序
        if (res[0] < res[1])
            return res;
        else
            return { res[1], res[0]};
    }
};

//缺失的第一个正整数
class Solution
{
    public:
    int minNumberDisappeared(vector<int>& nums)
    {
        int n = nums.size();
        unordered_map<int, int> mp;
        //哈希表记录数组中出现的每个数字
        for (int i = 0; i < n; i++)
            mp[nums[i]]++;
        int res = 1;
        //从1开始找到哈希表中第一个没有出现的正整数
        while (mp.find(res) != mp.end())
            res++;
        return res;
    }
};

# N皇后问题#
class Solution
{
    public:
    //判断皇后是否符合条件
    bool isValid(vector<int> &pos, int row, int col)
    {
        //遍历所有已经记录的行
        for (int i = 0; i < row; i++)
        {
            //不能同行同列同一斜线
            if (row == i || col == pos[i] || abs(row - i) == abs(col - pos[i]))
                return false;
        }
        return true;
    }

    //递归查找皇后种类
    void recursion(int n, int row, vector<int> & pos, int &res)
    {
        //完成全部行都选择了位置
        if (row == n)
        {
            res++;
            return;
        }
        //遍历所有列
        for (int i = 0; i < n; i++)
        {
            //检查该位置是否符合条件
            if (isValid(pos, row, i))
            {
                //加入位置
                pos[row] = i;
                //递归继续查找
                recursion(n, row + 1, pos, res);
            }
        }
    }

    int Nqueen(int n)
    {
        int res = 0;
        //下标为行号，元素为列号，记录皇后位置
        vector<int> pos(n, 0);
        //递归
        recursion(n, 0, pos, res);
        return res;
    }
};

#删除有序链表中重复的元素-II#
class Solution
{
    public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        //空链表
        if (head == NULL)
            return NULL;
        ListNode* res = new ListNode(0);
        //在链表前加一个表头
        res->next = head;
        ListNode* cur = res;
        while (cur->next != NULL && cur->next->next != NULL)
        {
            //遇到相邻两个节点值相同
            if (cur->next->val == cur->next->next->val)
            {
                int temp = cur->next->val;
                //将所有相同的都跳过
                while (cur->next != NULL && cur->next->val == temp)
                    cur->next = cur->next->next;
            }
            else
                cur = cur->next;
        }
        //返回时去掉表头
        return res->next;
    }
};


class Solution
{
    public:
    void recursion(vector<string> &res, string &str, string &temp, vector<int> &vis)
    {
        //临时字符串满了加入输出
        if (temp.length() == str.length())
        {
            res.push_back(temp);
            return;
        }
        //遍历所有元素选取一个加入
        for (int i = 0; i < str.length(); i++)
        {
            //如果该元素已经被加入了则不需要再加入了
            if (vis[i])
                continue;
            if (i > 0 && str[i - 1] == str[i] && !vis[i - 1])
                //当前的元素str[i]与同一层的前一个元素str[i-1]相同且str[i-1]已经用过了
                continue;
            //标记为使用过 
            vis[i] = 1;
            //加入临时字符串
            temp.push_back(str[i]);
            recursion(res, str, temp, vis);
            //回溯
            vis[i] = 0;
            temp.pop_back();
        }
    }

    vector<string> Permutation(string str)
    {
        //先按字典序排序，使重复字符串相邻
        sort(str.begin(), str.end());
        //标记每个位置的字符是否被使用过s
        vector<int> vis(str.size(), 0);
        vector<string> res;
        string temp;
        //递归获取
        recursion(res, str, temp, vis);
        return res;
    }
};


class Solution
{
    public:
    int Fibonacci(int n)
    {
        if (n <= 2) return 1;
        return Fibonacci(n - 1) + Fibonacci(n - 2);
    }
};


//后序遍历
class Solution
{
    public:
    void postorder(vector<int> &res, TreeNode* root)
    {
        //遇到空节点则返回
        if (root == NULL)
            return;
        //先遍历左子树
        postorder(res, root->left);
        //再遍历右子树
        postorder(res, root->right);
        //最后遍历根节点
        res.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> res;
        //递归后序遍历
        postorder(res, root);
        return res;
    } }

//合并二叉树
class Solution
{
    public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2)
    {
        //若只有一个节点返回另一个，两个都为NULL自然返回NULL
        if (t1 == NULL)
            return t2;
        if (t2 == NULL)
            return t1;
        //根左右的方式递归
        TreeNode* head = new TreeNode(t1->val + t2->val);
        head->left = mergeTrees(t1->left, t2->left);
        head->right = mergeTrees(t1->right, t2->right);
        return head;
    }
};

# 输出二叉树的右视图#

class Solution
{
    public:
    //建树函数
    //四个int参数分别是前序最左节点下标，前序最右节点下标
    //中序最左节点下标，中序最右节点坐标
    TreeNode* buildTree(vector<int>& xianxu, int l1, int r1, vector<int>& zhongxu, int l2, int r2)
    {
        if (l1 > r1 || l2 > r2)
            return NULL;
        //构建节点
        TreeNode* root = new TreeNode(xianxu[l1]);
        //用来保存根节点在中序遍历列表的下标 
        int rootIndex = 0;
        //寻找根节点
        for (int i = l2; i <= r2; i++)
        {
            if (zhongxu[i] == xianxu[l1])
            {
                rootIndex = i;
                break;
            }
        }
        //左子树大小
        int leftsize = rootIndex - l2;
        //右子树大小
        int rightsize = r2 - rootIndex;
        //递归构建左子树和右子树
        root->left = buildTree(xianxu, l1 + 1, l1 + leftsize, zhongxu, l2, l2 + leftsize - 1);
        root->right = buildTree(xianxu, r1 - rightsize + 1, r1, zhongxu, rootIndex + 1, r2);
        return root;
    }
    //深度优先搜索函数
    vector<int> rightSideView(TreeNode* root)
    {
        //右边最深处的值
        unordered_map<int, int> mp;
        //记录最大深度
        int max_depth = -1;
        //维护深度访问节点
        stack<TreeNode*> nodes;
        //维护dfs时的深度
        stack<int> depths;
        nodes.push(root);
        depths.push(0);
        while (!nodes.empty())
        {
            TreeNode* node = nodes.top();
            nodes.pop();
            int depth = depths.top();
            depths.pop();
            if (node != NULL)
            {
                //维护二叉树的最大深度
                max_depth = max(max_depth, depth);
                //如果不存在对应深度的节点我们才插入
                if (mp.find(depth) == mp.end())
                    mp[depth] = node->val;
                nodes.push(node->left);
                nodes.push(node->right);
                depths.push(depth + 1);
                depths.push(depth + 1);
            }
        }
        vector<int> res;
        for (int i = 0; i <= max_depth; i++)
            res.push_back(mp[i]);
        return res;
    }
    vector<int> solve(vector<int>& xianxu, vector<int>& zhongxu)
    {
        vector<int> res;
        //空节点
        if (xianxu.size() == 0)
            return res;
        //建树
        TreeNode* root = buildTree(xianxu, 0, xianxu.size() - 1, zhongxu, 0, zhongxu.size() - 1);
        //找每一层最右边的节点
        return rightSideView(root);
    }
};

//#二叉树的镜像#
class Solution
{
    public:
    TreeNode* Mirror(TreeNode* pRoot)
    {
        //空树返回
        if (pRoot == NULL)
            return NULL;
        //先递归子树
        TreeNode* left = Mirror(pRoot->left);
        TreeNode* right = Mirror(pRoot->right);
        //交换
        pRoot->left = right;
        pRoot->right = left;
        return pRoot;
    }
};

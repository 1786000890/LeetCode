### 421.Maximum-XOR-of-Two-Numbers-in-an-Array

本题涉及到一个新的数据结构叫做Trie（字典树）。关于字典树的基本概念可以参见：http://www.cnblogs.com/huangxincheng/archive/2012/11/25/2788268.html

相比于 Binary Indexed Tree 本质是一个数组，那么 Trie 本质上就是一个真正的多叉树。Trie把重复的前缀作为节点固定下来，可以省下很多空间。

首选我们需要结合本题，构建多叉树这种数据类型。它首先需要有递归的树状结构：即每一个节点下面有若干个该相同数据结构的指针。其次，需要设计构造函数进行初始化(复习一下C++面向对象的概念，构造函数的无参默认函数)。
```cpp
class TrieNode
{
   TrieNode* next[2];
   TrieNoe()
   {
      next[0] =NULL;
      next[1] =NULL;
   }
}
```
然后一项重要的工作就是用给定一堆数据（比如数组）来构建这个字典树。
```cpp
TreeNode* buildTree(vector<int>nums)
{
   TrieNode* root=new TrieNode();   // 创建根节点
   for (int i=0; i<nums.size(); i++)  // 给定一个数据
   {
      int num = nums[i];
      TreeNode* node=root;
      for (int j=31; j>=0; j--)
      {
          int bit = ((num>>j)&1);
          if (node->next[bit]==NULL)          
              node->next[bit]=new TrieNode();
          node = node->next[bit];
      }      
   }   
   return root;
}
```

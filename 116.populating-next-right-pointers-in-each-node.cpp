/*
 * @lc app=leetcode id=116 lang=cpp
 *
 * [116] Populating Next Right Pointers in Each Node
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
#include <queue>
class Solution {
   public:
    Node* connect(Node* root) {
        if(root == nullptr) return root;

        std::queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* prev_n = q.front();
            q.pop();
            int q_size = q.size();

            bool is_leaf_layer = false;
            if (prev_n->left == nullptr){
                is_leaf_layer = true;
            } else {
                q.push(prev_n->left);
                q.push(prev_n->right);
            }

            for (int i = 0; i < q_size; i++) {
                Node* n = q.front();
                q.pop();
                prev_n->next = n;
                prev_n = n;
                if(!is_leaf_layer){
                    q.push(n->left);
                    q.push(n->right);
                }
            }
        }
        return root;
    }
};
// @lc code=end

class Solution {
    // 0代表没有被摄像头覆盖
    // 1代表有摄像头
    // 2代表被摄像头覆盖（但是没有装摄像头）
    int _minCameraCoverResult(TreeNode* root, int& result) {
        // 空节点视作被摄像头覆盖了（题目不需要考虑空节点）
        if (root == nullptr) {
            return 2;
        }
        // 后续遍历
        int left = _minCameraCoverResult(root->left, result);
        int right = _minCameraCoverResult(root->right, result);
        // 判断当前节点是否需要装摄像头
        // 1.如果两个都是2，代表当前节点不需要装摄像头（不然会损失一层覆盖），返回0
        if (left == 2 && right == 2) {
            return 0; // 当前节点不装摄像头也没有被覆盖
        }
        // 2.如果两个节点中有一个是0，则代表当前节点必须装摄像头才能覆盖到下一层的节点
        if (left == 0 || right == 0) {
            result++; // 当前节点需要装摄像头
            return 1;
        }
        // 注意必须先判断两个其中有一个为0的情况，因为这种情况是必须装摄像头的；
        // 比如：一个为1一个为0，虽然此时本层已经被覆盖，但有一个子树没有覆盖上，本层必须装摄像头
        // 3.两个节点中其中一个是1，说明当前节点已经被覆盖上，不需要装摄像头
        if (left == 1 || right == 1) {
            return 2;
        }
        return 0; // 理论上不会走到这里
    }

public:
    int minCameraCover(TreeNode* root) {
        int result = 0;
        // 如果当前位是0（没有覆盖上，即root节点没有被覆盖）
        if (_minCameraCoverResult(root, result) == 0) {
            result++; // root节点装摄像头
        }
        return result;
    }
};

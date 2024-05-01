class Solution {
    // 检查是不是每个桶都装满了
    bool bucketCheck(vector<int>& bucket, int target) {
        for (auto& i : bucket) {
            if (i != target) {
                return false;
            }
        }
        return true;
    }
    // bucket是每一个桶中的数字，target是每一个桶应该达到的值，index是当前选择的树
    bool _canPartitionKSubsets(vector<int>& nums, vector<int>& bucket, int target,
                               int index) {
        // index越界，判断是否符合条件，即是不是每个桶都装满了
        if (index >= nums.size()) {
            // 因为之前已经判断过sum%k != 0 的情况了，即所有数字肯定是有一个能成功放入的解的
            // 既然能走到这里，说明就已经找到了这个解，直接返回true就可以了，不需要额外的检查
            //return bucketCheck(bucket,target);
            return true;
        }

        // 开始每一层的操作，将当前index选择一个桶往里面装
        for (int i = 0; i < bucket.size(); i++) {
            // 这个桶装不下，换一个桶
            if (bucket[i] + nums[index] > target) {
                continue;
            }
            // 前一个桶和当前桶的大小一样，说明当前的桶也装不下这个数字
            if(i > 0 && bucket[i] == bucket[i-1]){
                continue;
            }
            // 装得下，将当前数装进去
            bucket[i] += nums[index];
            // 走下一个数字去，如果已经可以装好，则直接返回true
            if (_canPartitionKSubsets(nums, bucket, target, index + 1)) {
                return true;
            }
            // 当前数字装在i桶里面不可行，需要装另外一个桶
            // 回溯当前层的操作
            bucket[i] -= nums[index];
            // 如果当前bucket是0还装不下这个数字，说明其他桶也装不下，直接跳出
            if(bucket[i] == 0){
                break;
            }
        }
        return false;
    }

public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        // 首先获取所有元素的和
        int sum = 0;
        for (auto& i : nums) {
            sum += i;
        }
        // 因为需要拆成k个，如果可以实现，最终的桶大小肯定是sum/k
        int target = sum / k;
        // 不能整除，说明无法实现，提前返回
        if (sum % k != 0) {
            return false;
        }
        // 排序可以提高速度
        sort(nums.begin(), nums.end());

        vector<int> bucket(k, 0);
        return _canPartitionKSubsets(nums, bucket, target, 0);
    }
};
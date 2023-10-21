//https://leetcode.cn/problems/snapshot-array/description/
class SnapshotArray {
public:
   SnapshotArray(int length):cur_arr(length){
    snap_count=0;
    for(int i=0;i<length;i++){
        cur_arr[i][0]=0;
    }
   }

    void set(int index, int val) {
        cur_arr[index][snap_count]=val;
    }
    
    int snap() {
        return snap_count++;
    }
    
    int get(int index, int snap_id) {
        //upper_bound是指找到比snap_id大的第一个数, 并且不包含其自身
        // 如果返回cur_arr[index].end(), 说明没有数比snap_id大, 
        //如果返回cur_arr[index].end()-1, 就是小于等于snap_id的数
        auto value=cur_arr[index].upper_bound(snap_id);
        return (--value)->second;
    }
    vector<map<int,int>> cur_arr;
    int snap_count;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
 

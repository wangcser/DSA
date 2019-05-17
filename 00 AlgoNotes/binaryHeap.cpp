vector<int> upAdjust(cector<int> nums, int length) {
    // 新插入的节点加入到序列尾部
    int child = length - 1;
    // 找到该节点的父亲
    int parent = (child - 1) / 2;
    // 缓存该节点
    int tmp = nums[child];

    // child 值小于 parent 则上浮交换
    while(child > 0 && tmp < nums[parent]) {
        nums[child] = nums[parent];
        child = parent;
        parent = (child - 1) / 2;
    }
    // 循环结束，表示 child 找到了正确的位置
    nums[child] = tmp;

    return num;
}

vector<int> downAdjust(cector<int> nums, int parent, int length) {
    // 缓存需要下沉的元素
    int tmp = nums[parent];
    // 找到左孩子
    int child = 2 * parent + 1;
    // 开始下沉
    while(child < length) {
        // 如果右孩子节点比左孩子小，则定位到右孩子
        // 也就是选择最小的那个孩子进行交换
        if(child + 1 < length && nums[child] > nums[child + 1])
            child++;
        // 如果父节点比孩子节点小或等于，则下沉结束
        if(tmp <= nums[child]) break;
        // 单向赋值
        nums[parent] = nums[child];
        parent = child;
        child = 2 * parent + 1;
    }
    // 循环结束，表示 parent 找到了正确的位置
    nums[parent] = tmp;

    return nums;
}

vector<int> buildHead(vector<int> nums, int length) {
    // 从最后一个非叶子节点开始下沉
    for(int i = (length - 2) / 2; i >= 0; i--) {
        nums = downAdjust(nums, i, length)
    }

    return nums;
}

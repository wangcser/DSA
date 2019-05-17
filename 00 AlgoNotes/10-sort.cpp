vector<int> selectSort(vector<int> nums) {
    
    // 使用 i 更新区间
    for(int i = 0; i < nums.size() - 1; i++) {
        
        // 比较
        int min = i;
        // 
        for(int j = i + 1; j < nums.size(); j++) {
            if(a[min] > a[j]) min = j;
        }

        // 交换
        swap(nums[min], nums[i]);
    }

    return nums;
}

vector<int> insertSort(vector<int> nums) {

    // 依次选择未排序部分头元素插入
    for(int i = 1; i < nums.size(); i++) {
        
        int tmp = nums[i]; // 当前头元素，腾挪时会覆盖，因此需要缓存一下
        int k = i - 1; // 已排序部分的长度

        // 通过比较查找插入的位置
        while(k >= 0 && nums[k] > tmp) {
            k--;
        }

        // 有序序列在插入序列的左侧
        // 从有序序列尾部开始腾挪空间
        for(int j = i; j > k + 1; j--) {
            nums[i] = nums[j - 1];
        }

        // 插头元素到指定位置 k
        nums[k + 1] = tmp;
    }

    return nums;
}

vector<int> bubbleSort(vector<int> nums) {
    // 扫描轮次
    for(int i = 0; i < nums.size(); i++) {
        // 扫描交换
        for(int j = 0； i < n - i; j++) {
            if(nums[j + 1] < nums[j])
                swap(nums[j + 1], nums[j]);
        }
    }

    return nums;
}

vector<int> shellSort(vector<int> nums) {
    // 设定希尔序列
    for(int h = n / 2; h > 0; h /= 2) {
        // 对各个局部分组从头到尾轮流插入排序
        for(int i = h; i < N; i++) {
            // 将 nums[i] 插入到所在分组的正确位置
            insertSort(nums, i, h);
        }
    }

    return nums;
}

void insertSort(vector<int>& nums, int i, int h) {
    // 将 i 位置元素插入其所在子序列的正确位置
    // 插入排序中有序部分在插入位置的左侧
    int insertNum = nums[i]; // 这个位置在腾挪时会被覆盖，需要缓存一下
    for(int j = i - h; j >= 0 && nums[i] < nums[j]; j -= h) {
        nums[j + h] = nums[j];
    }

    nums[j + h] = insertNum;
}


vector<int> mergeSort(vector<int> nums, int l, int r) {
    // l == r, 代表子序列只有一个元素自然有序
    if(l < r) {
        // 分割
        int mid = (l + r) / 2;
        // 左半边序列排序
        nums = mergeSort(nums, l, mid);
        // 右半边序列排序
        nums = mergeSort(nums, mid + 1, r);
        // 合并
        merge(nums, l, mid, r);
    }

    return nums;
}

void merge(vector<int>& nums, int l, int mid, int r) {
    // 使用临时序列汇总其合并结果
    vector<int> tmp = new vector<int> (r - l + 1);
    int i = l, j = mid + 1, k = 0;

    // 合并，直到用完某个序列
    while(i <= mid && j <= r) {
        if(nums[i] < nums[j])
            tmp[k++] = nums[i++];
        else
            tmp[k++] = nums[j++];
    }

    while(i <= mid) tmp[k++] = nums[i++];
    while(j <= r) tmp[k++] = nums[j++];

    // 将修改结果返回原数组，原数组中的修改范围是连续的
    for(int i = 0; i < k; i++) {
        nums[l++] = tmp[i];
    }
}

// 迭代实现
vector<int> mergeSort(vector<int> nums) {
    
    // 设定子数组的大小：1,2,4,8,16，...
    for(int i = 1; i < n; i+= i) {
        // 注意掌握 i 就是间隔这一特征
        int l = 0;
        int mid = l + i - 1;
        int r = mid + i;

        // 由于从 1 开始，因此直接开始合并
        while(r < n) {
            merge(nums, l, mid, r);
            // 更新下标到下一组
            l = r + 1;
            mid = l + i - 1;
            r = mid + i;
        }

        // 还有一些被遗漏的数组没合并，千万别忘了
        // 因为不可能每个字数组的大小都刚好为 i
        if(l < n && mid < n) {
            merge(nums, l, mid, n - 1);
        }
    }

    return nums;
}

vector<int> quickSort(vector<int> nums, int l, int r) {

    if（l < r) {
        // 使用 partition 获取中轴元素
        int mid = partition(nums, l, r);
        // 分割
        nums = quickSort(nums, l, mid - 1);
        nums = quickSort(nums, mid + 1, r);
    }

    return nums;
}
// 找到当前子数组的中轴元素
vector<int> partition(vector<int>& nums, int l, int r) {
    int target = nums[l];
    int i = l + 1;
    int j = r;

    while(true) {
        // 从左向右找到第一个大于 target 的元素
        while(i <= j && nums[i] <= target) i++;
        // 从右向左找到第一个小于 target 的元素
        while(i <= j && nums[j] >= target) j--;
        // 查找终止条件：越界
        if(i >= j) break;
        // 交换这两个元素的位置
        swap(nums[i], nums[j]);
    }
    // 交换 target 和 nums[j]，使中轴元素就位
    nums[l] = nums[j];
    nums[j] = target;

    return j;
}

vector<int> headSort(vector<int> nums) {
    // 建堆
    for(int i = (nums.size() - 2) / 2; i >= 0; i--) {
        downAdjust(nums, i, n - 1);
    }

    // 堆排序
    for(int i = n - 1; i >= 1; i--) {
        // 将堆顶元素和最后元素交换
        swap(nums[0], nums[i]);

        // 重建堆
        downAdjust(nums, 0, i - 1);
    }

    return nums;
}
//下沉操作
void downAdjust(vector<int>& nums, int parent, int n) {
    //临时保存要下沉的元素
    int tmp = nums[parent];
    //定位左孩子节点的位置
    int child = 2 * parent + 1;
    //开始下沉
    while(child <= n) {
        // 如果右孩子节点比左孩子大，则定位到右孩子
        if(child + 1 <= n && nums[child] < nums[child + 1])
            child++;
        // 如果孩子节点小于或等于父节点，则下沉结束
        if(nums[child] <= tmp) break;
        // 父节点进行下沉
        nums[parent] = nums[child];
        parent = child;
        child = 2 * parent + 1;
    }

    nums[parent] = tmp;
}

vector<int> countSort(vector<int> nums) {
    // 确定序列的最大值，以此确定统计数组的空间
    int max = nums[0];
    for(int i = 1; i < nums.size(); i++) {
        if(max < nums[i])
            max = nums[i];
    }

    // 创建大小为 max 的统计数组，略过 0 位置
    // 已自动初始化为 0
    int [] count = new int [max + 1];
    
    // 扫描并统计
    for(int i = 0; i < nums.size(); i++) {
        count[nums[i]]++;
    }

    // 使用统计数组重构序列
    int k = 0;
    for(int i = 0; i <= max; i++) {
        for(int j = count[i]; j > 0; j--) {
            nums[k++] = i;
        }
    }

    return nums;
}

vector<int> bucketSort(vector<int> nums) {
    // 找到最值
    int max = nums[0];
    int min = nums[0];
    for(int i = 1; i < nums.size(); i++) {
        if(min > nums[i]) min = nums[i];
        if(max < nums[i]) max = nums[i];
    }

    // 使用相对偏移值建桶
    int d = max - min;
    // 创建 d / 5 + 1 个桶，第 i 桶存放  5*i ~ 5*i+5-1范围的数
    int bucketNum = d / 5 + 1;
    // 初始化桶
    vector<list<int>> bucketList = new vector(bucketNum);
    for(int i = 0; i < bucketNum; i++) {
        bucketList.add(new list<int>());
    }
    // 元素入桶
    for(int i = 0; i < n; i++) {
        bucketList.[(nums[i] - min) / d].insert(nums[i] - min);
    }

    // 桶内排序
    for（inti= 0； i < bucketNum; i++) {
        sort(bucketList[i]);
    }

    // 汇总桶
    int k = 0;
    for(int i = 0; i < bucketNum; i++) {
        for(auto iter : bucketList[i]) {
            nums[k++] = iter + min;
        }
    }

    return nums;
}

vector<int> radixSort(vector<int> nums) {
    // 找出最大值
    int max = nums[0];
    for(int i = 1; i < nums.size(); i++) {
        if(max < nums[i]) max = nums[i];
    }

    // 计算最大值的位数，决定扫描的趟数
    int num = 1;
    while(max / 10  > 0) {
        num++;
        max /= 10;
    }

    // 创建 10 个桶
    vector<list<int>> bucketList = new vector<> (10);
    // 初始化桶
    for（int i = 0; i < 10; i++) {
        bucketList.push_back(new list<int> ());
    }

    // 开始排序
    for(int i = 1; i < num; i++) {
        for(int j = 0; j < nums.size(); j++) {
            // 获取当前数数位的基数
            int radix = nums[j] / (int)pow(10, i-1) % 10;
            bucketList[radix].insert(nums[j]);
        }
        // 合并桶，放回原数组，进行下一位排序
        int k = 0;
        for(int j = 0; j < 10; j++) {
            for(auto iter : bucketList[j]) {
                nums[k++] = t;
            }
            // 清空当前桶
            bucketList[j].clean();
        }
    }

    return nums；
}
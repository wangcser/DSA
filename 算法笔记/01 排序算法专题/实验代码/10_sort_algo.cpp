#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <numeric>
#include <list>
#include <cmath>
#include <stack>

using namespace std;

class SortAlgo {
public:
    SortAlgo() {
        srand(time(NULL));

        for (int i = 0; i < 20; ++i) {
            nums.push_back(rand() % 100);
        }
        n = nums.size();
    }

    void bubbleSort() {
        for (int i = 0; i < n - 1; ++i) { // 排序趟数，只需要 n-1 趟
            for (int j = 0; j < n - 1 - i; ++j) { // 每趟的比较次数，i 趟 n-i 次
                if (nums[j] > nums[j + 1])
                    swap(nums[j], nums[j + 1]);
            }
        }
    }

    void betterBubbleSort() {
        int board = n - 1; // j 只能取到 n-2
        for (int i = 0; i < n - 1; ++i) { // 排序趟数，只需要 n-1 趟
            bool earlyStop = true; // 1. 每趟检查是否执行过交换，没有则表示序列有序，提前终止
            int lastSwapIndex = n; // 2. 每趟记录发生交换的最后位置，只对无序区进行交换
            for (int j = 0; j < board; ++j) { // 每趟的比较次数，i 趟 n-i 次
                if (nums[j] > nums[j + 1]) {
                    swap(nums[j], nums[j + 1]);
                    earlyStop = false;
                    lastSwapIndex = j;
                }
            }
            board = lastSwapIndex;
            if (earlyStop == true) return;
        }
    }

    void selectSort() {
        /* in-place method */
        // 这里从 0 开始，表示开始时全都为未排序序列
        for (int i = 0; i < n; ++i) {
            // 找到右侧未排序区间中最小元素的位置
            int minIndex = i;
            for (int j = i + 1; j < n; ++j) {
                if (nums[minIndex] > nums[j])
                    minIndex = j;
            }
            // 将最小元素和未排序区间头元素交换，并更新区间
            swap(nums[i], nums[minIndex]);
        }
    }

    void insertSort() {
        /* in-place method */
        // 这里从 1 开始，表示开始时认为左侧一个元素为有序的
        for (int i = 1; i < n; ++i) {
            int tmp = nums[i]; // 待插入元素，无序区间的头元素
            int j; // 有序区间的右边界位置
            // 这里使用了尾部移动法，也可以使用依次交换策略
            for (j = i - 1; j >= 0 && nums[j] > tmp; --j) {
                nums[j + 1] = nums[j];
            }
            // 退出循环时进行了 --j，因此需要 j+1
            nums[j + 1] = tmp;
        }
    }

    void shellSort() {
        /* a faster insert sort */
        // 选择一个 shell 序列作为外循环
        for (int h = n / 2; h > 0; h /= 2) {
            // 对各个局部分组进行插入排序，这里是轮流排序
            for (int i = h; i < n; ++i) {
                shellInsertSort(i, h); // 这里 h 代表间隔
            }
        }
    }

    void mergesort(int l, int r) {
        /* 这里用双闭区间实现更清晰 */
        if (l + 1 >= r) return; // 在该区间中，l+1＝＝r 代表还剩一个元素
        // 使用左闭右开区间，使用双闭区间也不错
        int mid = l + (r - l) / 2;
        mergesort(l, mid);
        mergesort(mid, r);
        merge(l, mid, r);
    }

    void mergeSort() {
        mergesort(0, n);
    }

    void buttomTopMergeSort() {
        /* 枚举步长，将相邻区间合并 */
        for (int step = 1; step < n; step = step << 1) { // step = 1 2 4 8 16
            int offset = step + step;
            for (int index = 0; index < n; index += offset) { // offset = 2 4 8 16
                int l = index;
                int mid = min(l + step, n);
                int r = min(l + offset, n);
                merge(l, mid, r);
            }
        }
    }

    void quicksort(int l, int r) {
        if (l >= r) return;

        int mid = partition(l, r);
//        int mid = midThree_partition(l, r);
//        int mid = random_partition(l, r);
        quicksort(l, mid - 1);
        quicksort(mid + 1, r);
    }

    void quickSort() {
        // 这是双闭区间
        quicksort(0, n - 1);
    }

    void buttomTopQuickSort() {
        stack<int> st;
        int l = 0, r = n - 1;
        int mid = partition(l, r);
        // 用栈保存每一个待排序子串的首尾元素下标
        // 下一次while循环时取出这个范围，对这段子序列进行 partition 操作

        st.push(l);
        st.push(mid - 1);
        st.push(mid + 1);
        st.push(r);

        while (!st.empty()) {
            // 注意出栈顺序
            r = st.top();
            st.pop();
            l = st.top();
            st.pop();

            mid = partition(l, r);
            if (l < mid - 1) {
                st.push(l);
                st.push(mid - 1);
            }
            if (mid + 1 < r) {
                st.push(mid + 1);
                st.push(r);
            }
        }
    }

    void heapSort() {
        // build heap：只需要保证前一半的元素满足堆序性即可
        for (int i = (n - 2) / 2; i >= 0; --i) {
            downAdjust(i, n - 1);
        }
        // sort：将堆顶元素依次交换到堆底
        for (int i = n - 1; i >= 1; --i) {
            swap(nums[0], nums[i]);
            downAdjust(0, i - 1);
        }
    }

    void STLHeapSort() {
        sort_heap(nums.begin(), nums.end());
    }

    void countSort() {
        // 这里使用了区间压缩的优化方法
        vector<int>::iterator max_it = max_element(nums.begin(), nums.end());
        vector<int>::iterator min_it = min_element(nums.begin(), nums.end());
        int maxNum = *max_it;
        int minNum = *min_it;

        // 1. 初始化统计数组
        int n = maxNum - minNum + 1; // 区间长度
        vector<int> count(n, 0);

        // 2. 扫描并统计
        for (auto num : nums)
            count[num - minNum]++;

        // 3. 重构序列
        int k = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = count[i]; j > 0; --j) {
                nums[k++] = i + minNum;
            }
        }
    }

    void bucketSort() {
        // 这里和计数排序一样，使用了区间优化
        int maxNum = *max_element(nums.begin(), nums.end());
        int minNum = *min_element(nums.begin(), nums.end());
        // 使用区间长度来划分桶
        int n = maxNum - minNum + 1;
        int bucketNum = n / 5 + 1; // 每 5 个步长构建一个桶，第 i 桶存放  5*i ~ 5*i+5-1范围的数

        // 初始化桶
        vector<vector<int>> buckets(bucketNum);

        // 元素入桶
        for (auto num : nums) {
            buckets[(num - minNum) / bucketNum].push_back(num);
        }
        // 桶内排序
        for (int i = 0; i < bucketNum; ++i) {
            sort(buckets[i].begin(), buckets[i].end());
        }
        // 汇总结果，桶间有序
        int k = 0;
        for (int i = 0; i < bucketNum; ++i) {
            for (auto it : buckets[i]) {
                nums[k++] = it;
            }
        }
    }

    void radixSort() {
        // 这里和计数排序一样，使用了区间优化
        int maxNum = *max_element(nums.begin(), nums.end());
        // 计算最大值的位数，决定扫描的趟数，每位都执行一轮桶排序
        int bits = 0;
        while (maxNum > 0) {
            maxNum /= 10;
            bits++;
        }

        // 创建 10 个桶:0~9
        vector<vector<int>> buckets(10);

        // 排序
        for (int i = 0; i < bits; ++i) {
            for (auto num : nums) {
                // 获取当前数数位的基数
                int radix = (num / (int) pow(10, i)) % 10;
                buckets[radix].push_back(num);
            }
            // 合并桶，放回原数组，进行下一位排序
            int k = 0;
            for (int i = 0; i < 10; ++i) {
                for (auto num : buckets[i])
                    nums[k++] = num;
                buckets[i].clear();
            }
        }
    }


    bool isSorted() {
        if (nums.size() < 2) {
            cout << "nums size < 2, true" << endl;
            return true;
        }

        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                cout << "false" << endl;
                return false;
            }
        }

        cout << "true" << endl;
        return true;
    }

    void shuffle() {
        for (int i = 0; i < n; ++i) {
            int randIndex = i + rand() % (n - i);
            swap(nums[i], nums[randIndex]);
        }
    }

    void betterShuffle() {
        random_shuffle(nums.begin(), nums.end());
    }

    void printNums() {
        for (auto num : nums)
            cout << num << " ";

        cout << endl;
    }

private:
    vector<int> nums;
    int n;

    // shell sort
    void shellInsertSort(int i, int h) {
        // i 代表无序区间的头元素，h 代表间隔，类比 insertSort 中的 1
        int tmp = nums[i];
        int j;
        for (j = i - h; j >= 0 && nums[j] > tmp; j -= h) {
            nums[j + h] = nums[j];
        }
        nums[j + h] = tmp;
    }

    // merge sort
    void merge(int l, int mid, int r) {
        // 辅助容器用于缓存合并的结果，注意容器大小
        vector<int> helper(r - l);
        // 序列 1 的头为 l，序列 2 的头为 mid，合并序列的头为 0
        int i = l, j = mid, k = 0;

        // 合并
        while (i < mid && j < r) {
            if (nums[i] < nums[j])
                helper[k++] = nums[i++];
            else
                helper[k++] = nums[j++];
        }

        // 将剩余序列存入辅助容器
        while (i < mid) helper[k++] = nums[i++];
        while (j < r) helper[k++] = nums[j++];

        // 将合并结果复制回到原序列
        for (int i = 0; i < k; ++i) {
            nums[l++] = helper[i];
        }
    }

    //quick sort
    int partition(int l, int r) {
        /* 返回就位后枢轴变量的下标 */
        int pivot = nums[l];
        // 取区间头元素为枢轴变量
        int i = l + 1, j = r;
        while (true) {
            while (i <= j && nums[i] <= pivot) i++;
            while (i <= j && nums[j] >= pivot) j--;

            if (i > j) break;

            swap(nums[i], nums[j]);
        }
        // 退出循环时 j-- 了，因此最终 j 的位置为左侧最右端的位置
        swap(nums[l], nums[j]);

        return j;
    }

    int random_partition(int l, int r) {
        int randIndex = l + rand() % (r - l + 1);
        swap(nums[l], nums[randIndex]);
        return partition(l, r);
    }

    int midThree_partition(int l, int r) {
        int mid = l + (r - l) / 2;
        int midIndex = l;
        // 下面三次比较相当于冒泡排序
        if (nums[l] > nums[mid]) swap(nums[l], nums[mid]);
        if (nums[mid] > nums[r]) swap(nums[mid], nums[r]);
        if (nums[l] > nums[mid]) swap(nums[l], nums[mid]);

        // 将中值和最小值交换
        swap(nums[l], nums[mid]);

        return partition(l, r);
    }

    // heap sort
    void downAdjust(int p, int n) {
        int tmp = nums[p];
        // 对于堆来说，如果从 1 开始计算，则 left-child = 2 * p
        // 如果从 0 开始计算，则 left-child = 2 * p + 1，相当于所有结果都 +1
        int child = 2 * p + 1;
        while (child <= n) {
            // 如果右孩子更大，则使用右孩子下沉
            if (child + 1 <= n && nums[child] < nums[child + 1])
                child++;
            // 满足堆序性则停止
            if (nums[child] <= tmp) break;
            // 父节点下沉，使用子节点的值覆盖父节点的值
            nums[p] = nums[child];
            p = child;
            child = 2 * p + 1;
        }

        nums[p] = tmp;
    }
};


int main() {
    SortAlgo mySort;
    mySort.printNums();

    mySort.buttomTopQuickSort();
    mySort.printNums();

    mySort.isSorted();

//    mySort.shuffle();
//    mySort.printNums();

    return 0;
}
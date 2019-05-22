int binSearch(vector<int>& nums, int target) {
    
    // 1. pre-processing
    sort(nums.begin(), nums.end());
    
    // 2. bin-search
    int l = 0, r = nums.size() - 1;

    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] < target) l = mid + 1;
        else r = mid - 1;
    } // end condition: l > r

    return -1;
}

int binSearch(vector<int>& nums, int target) {
    
    // 1. pre-processing
    sort(nums.begin(), nums.end());

    // 2. bin-search
    int l = 0, r = nums.size();

    while(l < r) {
        int mid = l + (r - l) / 2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] < target) l = mid + 1;
        else r = mid;
    } // end condition: l = r

    // 3. post-processing
    if(l != nums.size() && nums[l] == target) return l;
    else return -1;
}

int binSearch(vector<int>& nums, int target) {
    
    // 1. pre-processing
    sort(nums.begin(), nums.end());

    // 2. bin-search
    int l = 0, r = nums.size() - 1;

    while(l + 1 < r) {
        int mid = l + (r - l) / 2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] < target) l = mid;
        else r = mid;
    } // end condition: [l, r]

    // 3. post-processing
    if(nums[l] == target) return l;
    else if(nums[r] == target) return r;
    else return -1;
}


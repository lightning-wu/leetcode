
 int lengthOfLIS(vector<int>& nums){
    int size = nums.size();
    int* dp = new int[size];
    int res = 0;
    dp[0] = 1;
    for (int i = 1; i < size; i++){
        dp[i] = getMaxChildState(dp, nums, i);
        res = (res < dp[i]) ? dp[i] : res;
    }
    return res;
 }

 void getMaxChildState(int* dp, vector<int>& nums, int i){
    int maxLen = 1;
    for (int j = 0; j < i; j++){
        if (nums[j] < nums[i]){
            maxLen = (maxLen < dp[j] + 1) ? dp[j] + 1 : maxLen; 
        }   
    }
 }


 int lengthOfLIS(vector<int>& nums){
    int size = nums.size();
    int* minDataEachLen = new int[size + 1];
    int len = 0;
    for (int i = 0; i < size; i++){
        update(minDataEachLen, len, nums[i]);
    }
    return len;
 }

void update(int* minDataEachLen, int& len, int data){
    // binary search
    int low = 1;
    int high = len; 
    int mid;
    while (low <= high){
        mid = (low + high) / 2;
        if (minDataEachLen[mid] < data)
            low = mid + 1;
        else if (midDataEachLen[mid] > data)
            high = mid - 1;
        else 
            return;
    }
    minDataEachLen[low] = data;
    len = (low > len) ? low : len;
}

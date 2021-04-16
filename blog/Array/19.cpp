vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
    vector<long long int> pre(n,1), post(n,1);
    for(int i = 1; i < n; i++){
        pre[i] = pre[i-1] * nums[i-1] ;
    }
    for(int i = n-2; i >= 0; i--){
        post[i] = post[i+1] * nums[i+1];
    }
    for(int i = 0; i < n; i++){
        nums[i] = post[i] * pre[i];
    }
    
    return nums;
}

class NumArray {
    vector<int>seg;
    vector<int>num;
    int n;
    void build(vector<int>& nums,int low,int high,int ind){
        if(low==high){
            seg[ind]=nums[low];
            return ;
        }
        int mid=(low+high)/2;
        build(nums,low,mid,2*ind+1);
        build(nums,mid+1,high,2*ind+2);
        seg[ind]=seg[2*ind+1]+seg[2*ind+2];
        return ;
    }
    void upd(int i,int val,int low,int high,int ind){
        if(low==high){
            seg[ind]=val;
            return;
        }
        int mid=(low+high)/2;
        if(i<=mid)upd(i,val,low,mid,2*ind+1);
        else upd(i,val,mid+1,high,2*ind+2);
        seg[ind]=seg[2*ind+1]+seg[2*ind+2];
    }
    int query(int l,int r,int ll,int rr,int ind){
        if(r<ll||l>rr)return 0;
        if(l<=ll&&rr<=r)return seg[ind];
        int mid=(ll+rr)/2;
      int left = query(l,r,ll,mid,2*ind+1);
        int right=query(l,r,mid+1,rr,2*ind+2);
        return left+right;
    }
public:
    NumArray(vector<int>& nums) { 
        n=nums.size();
        seg=vector<int>(4*n+1,0);
        num=nums;
      
        build(nums,0,nums.size()-1,0);
    }
    
    void update(int index, int val) {
        upd(index,val,0,n-1,0);
        num[index]=val;
    }
    
    int sumRange(int left, int right) {
       return query(left,right,0,n-1,0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
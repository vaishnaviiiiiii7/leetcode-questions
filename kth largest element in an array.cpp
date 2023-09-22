class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        //we first transform k into the (size-k)th smallest element 
        //since quick select finds the kth smallest element
        k = nums.size()-k;
        return qs(nums,0,nums.size()-1,k);
    }

    int qs(vector<int>&v, int l, int r, int k){
        if(l==r)return v[l];
        int currSize = r-l+1;
        int pivot = v[rand()%currSize+l];
        
        int low = l,high = r,equal = l;
        while(equal<=high){
            int curr = v[equal];
            if(curr<pivot){
                swap(v[equal++],v[low++]);
            }else if(curr>pivot){
                swap(v[equal],v[high--]);
            }else{
                equal++;
            }
        }

        if(k<low) return qs(v,l,low-1,k);
        else if(k<=high) return pivot;
        return qs(v,high+1,r,k);
    }
};

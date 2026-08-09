class SegmentTree{
  public:
    struct Node{
        int cnt=0;
        int first=-1;
        int last=-1;
        long long val=0;
    };
    vector<Node>segTree;
    vector<int>&nums;
    SegmentTree(int n,vector<int>&nums):nums(nums){
        segTree.assign(4*n,Node());
    }
    Node merge(Node a,Node b){
        if(a.cnt==0) return b;
        if(b.cnt==0) return a;
        Node res;
        res.cnt=a.cnt+b.cnt;
        res.first=a.first;
        res.last=b.last;
        res.val=a.val+b.val;
        res.val+=1ll*a.last*(b.first-a.last);
        return res;
    }
    bool isPeak(int i){
        if(i<=0 || i>=nums.size()-1) return false;
        return nums[i]>nums[i-1] && nums[i]>nums[i+1];
    }
    void build(int i,int l,int r){
        if(l==r){
            if(isPeak(l)){
                segTree[i].cnt=1;
                segTree[i].first=l;
                segTree[i].last=l;
            }
            return;
        }
        int mid=l+(r-l)/2;
        build(2*i+1,l,mid);
        build(2*i+2,mid+1,r);
        segTree[i]=merge(segTree[2*i+1],segTree[2*i+2]);
    }
    void update(int i,int l,int r,int idx){
        if(l==r){
            segTree[i]=Node();
            if(isPeak(idx)){
                segTree[i].cnt=1;
                segTree[i].first=idx;
                segTree[i].last=idx;
            }
            return;
        }
        int mid=l+(r-l)/2;
        if(idx<=mid){
            update(2*i+1,l,mid,idx);
        }else{
            update(2*i+2,mid+1,r,idx);
        }
        segTree[i]=merge(segTree[2*i+1],segTree[2*i+2]);
    }   
    Node query(int i,int l,int r,int start,int end){
        if(end<l || r<start) return Node();
        if(start<=l && r<=end) return segTree[i];
        int mid=l+(r-l)/2;
        return merge(query(2*i+1,l,mid,start,end),query(2*i+2,mid+1,r,start,end));
    }
};
class Solution {
public:
    vector<long long> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        vector<long long>v;
        int n=nums.size();
        SegmentTree seg(n,nums);
        seg.build(0,0,n-1);
        for(auto &q:queries){
            if(q[0]==1){
                int l=q[1];
                int r=q[2];
                if(r-l+1<3){
                    v.push_back(0);
                    continue;
                }
                auto x=seg.query(0,0,n-1,l+1,r-1);
                if(x.cnt==0){
                    v.push_back(0);
                    continue;
                }
                long long res=x.val;
                res+=1ll*x.last*(r-x.last);
                res-=1ll*l*(r-x.first);
                v.push_back(res);
            }else{
                int idx=q[1];
                int val=q[2];
                nums[idx]=val;
                for(int i=idx-1;i<=idx+1;i++){
                    if(i>=0 && i<n){
                        seg.update(0,0,n-1,i);
                    }
                }
            }
        }
        return v;
    }
};
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> results;
        bool just_right = false;
        int last_number = nums[0] + 1;
        for(int i = 0; i < nums.size() - 1; i++){
            int first_number = nums[i];
            if(first_number == last_number){
                continue;
            }
            last_number = first_number;
            int left = i + 1;
            int right = nums.size() - 1;
            just_right = false;
            while(left != right){
                int sum = first_number + nums[left] + nums[right];
                if(sum == 0){
                    if(!just_right){
                    vector<int> triplet = {first_number, nums[left], nums[right]};
                    results.push_back(triplet);
                    }
                    just_right = true;
                    left++;
                } else{
                    just_right = false;
                    if(sum > 0){
                        right--;
                    } else{
                        left++;
                    }
                } 
            }
        }
        return results;
    }
};


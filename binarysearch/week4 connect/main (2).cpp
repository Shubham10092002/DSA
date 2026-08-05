class Solution {
public:
int findPivot(vector<int> arr) {
  int s = 0;
  int e = arr.size() - 1;
  int mid = s + (e-s)/2;

  while(s <= e) {
    if(s == e) {
      //single element
      return s;
    }
    if(mid <= e && arr[mid] > arr[mid+1])
      return mid;
    if(mid-1 >= s && arr[mid-1] > arr[mid])
      return mid-1;

    if(arr[s] > arr[mid]) 
      e = mid - 1;
    else
      s = mid + 1;

    mid = s + (e-s)/2;

  }
  return -1;
}
int binarySearch(vector<int> arr, int s, int e, int target) {
    int mid = s + (e-s)/2;

    while(s <= e) {
        if(arr[mid] == target) {
            return mid;
        }
        if(arr[mid] > target)
            e = mid - 1;
        else
            s = mid + 1;
        mid = s +(e-s)/2;
    }
    return -1;


}
    int search(vector<int>& nums, int target) {

        int pivotIndex = findPivot(nums);
        int ans = 0;
        if(target >= nums[0] && target <= nums[pivotIndex]) {
            ans = binarySearch(nums, 0, pivotIndex, target);

        }
        else {
            ans = binarySearch(nums, pivotIndex+1, nums.size()-1, target);
        }

    return ans;
        
    }
};


find the peak element in  array

int findThePeakEle(vector<int> &arr){

    int n = arr.size()

    if(n == 1){
        return 0;
    }

    if(arr[0] > arr[1]){
        return 0;
    }

    if(arr[n-1] > arr[n-2]){
        return n-1;
    }

    int s = 1;
     int e = n-2;
     int mid = s + (e - s)/2;
     while(s<=e){
        if(arr[mid] < arr[mid +1] && arr[mid] > arr[mid - 1])
            return mid;

        if(ar[mid] > arr[mid +1])
            e = mid -1;

        else
            s = mid +1;

        mid = s + (e-s)/2;
     }

     return -1;
}

//koko eating banana 
bool EatingHour(vector<int> &banana,int mini, int hr){

    int count = 0;
    for(int i = 0; i< arr.size(); i++){
        count +=  arr[i]/mini;
        int rem = arr[i]%mini;
        // count +=  ceil((double)(banana[i]) / (double)(hr)) 
        if(rem > 0)
            count++;

        if(count > hr){
            retur false;
        }
    }

    return true;
}

int kokobanana(vector<int> &banana, int hr){
     int ans  = -1;

     int mini = 1;
     int maxi =  *max_element(banana.begin(),banana.end());
     int s =mini;
    int e = maxi;
    int mid = s + (e-s)/2;

    while(s<=e){
        if(EatingHour(banana,mid, hr)){
            ans  = mid ;
            e = mid - 1;
        }
        else{
            s =  mid + 1 ;
        }

        mid =  s + (e - s)/2;
    }

    return ans;

}
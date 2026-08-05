// Write a function that takes the binary representation of a positive integer and returns the number of 
// set bits
//  it has (also known as the Hamming weight).
  int hammingWeight(int n) {
        int count = 0;
        //approach:1
        //return (__builtin_popcount(n));

        approach:2
        // while(n>0){
        //     if(n & 1){
        //         count++;
        //     }
        //     n = n>>1;
        // }
        // return count;

        approach:3
        // for(int i = 31; i>=0; i--){
        //     if((n >>i) & 1 == 1)
        //     count++;
        // }
        // return count;

        approach:3
        //making rightmost set bit to unset
        while(n>0){
            n = (n & (n-1));
            //if(n!= 0)
            count++;
        }
        return count;
    }

//sort by number of 1 bits
    //arr[5,2,3,8]
    //output[2,8,3,5]
//lamda function for comparator
vector<int> sorton1bits(vector<int>&arr){
  sort(begin(arr),end(arr),lamda);
  return arr;
}


auto lamda = [](int &a, int &b ){
    int cA = findonebits(a);
    int cB = findonebits(b);
    if(cA == cB)
        return a<b;//if count of 1 bits equal

    else 
        return  cA < cB;//asc on count of 1 bits
};

int findonebits(n){
  int count = 0;
  while(n!=0){
    if((n&1)==1)
      count++;
    n>>=1;
  }
}


int onebit = __builtin__popcount(n);
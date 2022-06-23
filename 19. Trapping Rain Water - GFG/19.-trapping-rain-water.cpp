// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        long long res=0;
        int leftmax[n];
        leftmax[0]=arr[0];
        for(int i=1;i<n;i++)
        leftmax[i]=max(leftmax[i-1],arr[i]);
        int rightmax[n];
        rightmax[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--)
        rightmax[i]=max(arr[i],rightmax[i+1]);
        for(int i=1;i<n-1;i++)
        {
            res+=min(leftmax[i],rightmax[i])-arr[i];
        }
        return res;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends
// { Driver Code Starts
#include <iostream>
using namespace std;


 // } Driver Code Ends
// Function to find element in sorted array

int leftIndex(int N, int arr[], int X){
    
    // Your code here
    int l=0,h=N-1;
    while(l<=h)
    {
        int mid=(l+h)/2;
        if(arr[mid]>X)
        h=mid-1;
        else if(arr[mid]<X)
        l=mid+1;
        else
        {
            if(mid==0||arr[mid-1]!=arr[mid])
            return mid;
            else
            h=mid-1;
        }
    }
    return -1;
    
}




// { Driver Code Starts.

// Driver Code
int main() {
	
	// Testcase input
	int testcases;
	cin >> testcases;
    
    // Looping through all testcases
	while(testcases--){
	    int sizeOfArray;
	    cin >> sizeOfArray;
	    
	    int arr[sizeOfArray];
	    
	    // Array input
	    for(int index = 0; index < sizeOfArray; index++){
	        cin >> arr[index];
	    }
	    
	    int elemntToSearch;
	    cin >> elemntToSearch;
	    
	    cout << leftIndex(sizeOfArray, arr, elemntToSearch) << endl;
	}
	
	return 0;
}  // } Driver Code Ends
class Solution {
public:
    string decodeAtIndex(string s, int k) {
        //d is deocoded string 
        long long d=0;
        for(auto x:s){

            //check the if digit occure , we will update length of string 

            if(isdigit(x)){
                d=d*(x-'0');                
            }

            //other wise increment by 1

            else{
                d++;
            }
        }

            //we have total length build by the string and no 
          //reverse travesal

        for(int i=s.size()-1;i>=0;i--){

            //check the it char is digit

            if(isdigit(s[i])){

                //we will reduce the length of decoded string by digit we get 

                d/=(s[i]-'0');

                //also we reduce the k index

                k = k % d;
            }
            else{

                //if we reached at end or found the index k 

                if(k==0 || k==d){
                    return string("")+s[i];
                }
                d--;
            }
            
            
        }
            
            
            
        
        return "";
    }
};
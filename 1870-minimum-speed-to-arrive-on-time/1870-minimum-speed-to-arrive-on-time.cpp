class Solution {
public:
    double timeRequired(vector<int>& dist,int speed)
    {
        double time=0.0;
        for(int i=0;i<dist.size();i++){
            double t=(double)dist[i]/(double)speed;
            time+=(i==dist.size()-1?t:ceil(t));
        }
        return time;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low=1,high=1e9,minSpeed=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(timeRequired(dist,mid)<=hour){
                minSpeed=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return minSpeed;
    }
};
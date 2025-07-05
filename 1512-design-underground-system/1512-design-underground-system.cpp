class UndergroundSystem {
    unordered_map<int,pair<string,int>>checkInMap;
    unordered_map<string,pair<int,int>>checkOutMap;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkInMap[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string startStation=checkInMap[id].first;
        int inTime=checkInMap[id].second;
        checkInMap.erase(id);
        string startAndEnd=startStation+"-"+stationName;
        int timeTaken=t-inTime;
        if(checkOutMap.find(startAndEnd)!=checkOutMap.end())
        {
            checkOutMap[startAndEnd].first=checkOutMap[startAndEnd].first+timeTaken;
            checkOutMap[startAndEnd].second=checkOutMap[startAndEnd].second+1;
        }
        else{
            checkOutMap[startAndEnd]={timeTaken,1};
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        string startAndEnd=startStation+"-"+endStation;
        return (double)checkOutMap[startAndEnd].first/checkOutMap[startAndEnd].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        map<int,int>mp={{1,31},{2,28},{3,31},{4,30},{5,31},{6,30},{7,31},{8,31},{9,30},{10,31},{11,30},{12,31}};
        map<pair<int,int>,int>days;
        int alice_smonth=stoi(arriveAlice.substr(0,2));
        int alice_sdate=stoi(arriveAlice.substr(3));
        int alice_emonth=stoi(leaveAlice.substr(0,2));
        int alice_edate=stoi(leaveAlice.substr(3));
        int bob_smonth=stoi(arriveBob.substr(0,2));
        int bob_sdate=stoi(arriveBob.substr(3));
        int bob_emonth=stoi(leaveBob.substr(0,2));
        int bob_edate=stoi(leaveBob.substr(3));
        for(int i=1;i<=12;i++){
            if(i>=alice_smonth && i<=alice_emonth){
                int start=(i==alice_smonth)?alice_sdate:1;
                int end=(i==alice_emonth)?alice_edate:mp[i];
                for(int d=start;d<=end;d++){
                    days[{i,d}]++;
                }
            }
            if(i>=bob_smonth && i<=bob_emonth){
                int start=(i==bob_smonth)?bob_sdate:1;
                int end=(i==bob_emonth)?bob_edate:mp[i];
                for(int d=start;d<=end;d++){
                    days[{i,d}]++;
                }
            }
        }
        int cnt=0;
        for(auto it:days){
            if(it.second>1) cnt++;
        }
        return cnt;
    }
};
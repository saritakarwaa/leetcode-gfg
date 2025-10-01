class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int full=numBottles;
        int drank=0;
        int empty=0;
        while(full>0){
            drank+=full;
            empty+=full;
            full= empty/ numExchange;
            empty = empty % numExchange;
        }
        return drank;
    }
};
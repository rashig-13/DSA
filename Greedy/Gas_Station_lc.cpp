There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.

Given two integer arrays gas and cost, return the starting gas stations index if you can travel around the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique

//https://www.youtube.com/watch?v=xmJZSYSvgfE

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int total_surplus=0,surplus=0;
        int ans=0;
        for(int i=0;i<n;i++){
            total_surplus+=gas[i]-cost[i];
            surplus+=gas[i]-cost[i];
            if(surplus<0){
                surplus=0;
                ans=i+1;
            }
            
        }
        if(total_surplus<0) return -1;
        else
            return ans;
    }
};
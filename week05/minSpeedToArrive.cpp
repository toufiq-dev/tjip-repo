class Solution {
public:
    // TC: O(n log m) where, n = |dist|, m = INT_MAX / 2
    // SC: O(1)
    bool isPossible(vector<int> &dist, int currSpeed, double hour) {
        double elapsed_time = 0.0;
        for(int i = 0; i < dist.size(); ++i) {
            if(i + 1 != dist.size())
                elapsed_time += (dist[i] + currSpeed - 1) / currSpeed;
            else 
                elapsed_time += 1.00 * dist[i] / currSpeed;
        }

        return elapsed_time <= hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int L = 1, R = INT_MAX / 2;
        while(L < R) {
            int M = L + (R - L) / 2;
            if(!isPossible(dist, M, hour)) 
                L = M + 1;
            else 
                R = M;
        }

        return L == INT_MAX / 2 ? -1 : L;
    }
};
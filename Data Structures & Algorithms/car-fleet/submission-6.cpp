class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> vec;
        for (int i = 0; i < speed.size(); i++) {
            vec.push_back({position[i], speed[i]});
        }
        sort(vec.rbegin(), vec.rend());

        vector<float> arrive;
        for (int i = 0; i < speed.size(); i++) {
            float time = (double)(target - vec[i].first) / vec[i].second;
            arrive.push_back(time);
        }

        int fleet = 1;
        for (int i = 1; i < speed.size(); i++) {
            if (arrive[i - 1] < arrive[i]) {
                fleet++;
            } else {
                arrive[i] = arrive[i - 1];
            }
        }
        return fleet; 

    }
};

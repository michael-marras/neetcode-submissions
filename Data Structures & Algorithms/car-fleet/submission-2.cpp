class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        std::map<int, int, std::greater<int>> posToSpeed;
        std::unordered_set<float> times;
        float bottleNeckTime = -1;

        for (int i = 0; i < position.size(); i++) {
            posToSpeed[position[i]] = speed[i];
        }

        for (auto x : posToSpeed) {
            float time = static_cast<float>(target - x.first) / x.second;
            if (time < bottleNeckTime) {
                time = bottleNeckTime;
            }
            else {
                bottleNeckTime = time;
            }
            times.insert(time);
        }

        return times.size();
    }
};

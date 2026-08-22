class Solution {
public:
    int maximumSum(vector<int>& arr) {

        int bestNoDelete = arr[0];
        int bestOneDelete = INT_MIN;

        int ans = arr[0];

        for (int i = 1; i < arr.size(); i++) {

            int newOneDelete;

            if (bestOneDelete == INT_MIN) {
                newOneDelete = bestNoDelete;
            } else {
                newOneDelete = max(
                    bestOneDelete + arr[i],
                    bestNoDelete
                );
            }

            int newNoDelete = max(
                arr[i],
                bestNoDelete + arr[i]
            );

            bestNoDelete = newNoDelete;
            bestOneDelete = newOneDelete;

            ans = max(ans, max(bestNoDelete, bestOneDelete));
        }

        return ans;
    }
};
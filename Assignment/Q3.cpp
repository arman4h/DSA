#include <iostream>
#include <vector>

using namespace std;

int main() {
    int totalStreets;
    cin >> totalStreets;

    vector<vector<int>> shortestTime(
        totalStreets,
        vector<int>(totalStreets)
    );

    for (int row = 0; row < totalStreets; row++) {
        for (int col = 0; col < totalStreets; col++) {
            cin >> shortestTime[row][col];
        }
    }

    for (int middle = 0; middle < totalStreets; middle++) {
        for (int start = 0; start < totalStreets; start++) {
            for (int end = 0; end < totalStreets; end++) {
                if (
                    shortestTime[start][middle] +
                    shortestTime[middle][end]
                    <
                    shortestTime[start][end]
                ) {
                    shortestTime[start][end] =
                        shortestTime[start][middle] +
                        shortestTime[middle][end];
                }
            }
        }
    }

    int totalScenarios;
    cin >> totalScenarios;

    while (totalScenarios--) {
        int restaurantStreet;
        int gasStationStreet;
        int destinationStreet;

        cin >> restaurantStreet
            >> gasStationStreet
            >> destinationStreet;

        int deliveryTime =
            shortestTime[restaurantStreet][gasStationStreet]
            +
            shortestTime[gasStationStreet][destinationStreet];

        int directTime =
            shortestTime[restaurantStreet][destinationStreet];

        cout << deliveryTime << " "
             << deliveryTime - directTime
             << endl;
    }

    return 0;
}
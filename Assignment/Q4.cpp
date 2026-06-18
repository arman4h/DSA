#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCaseCount;
    cin >> testCaseCount;

    while (testCaseCount--) {
        int totalCities, totalRoads, pathLength;
        cin >> totalCities >> totalRoads >> pathLength;

        vector<int> visitedCities(pathLength);

        for (int i = 0; i < pathLength; i++) {
            cin >> visitedCities[i];
            visitedCities[i]--;
        }

        const long long infinityValue = 1e18;

        vector<vector<long long>> shortestDistance(
            totalCities,
            vector<long long>(totalCities, infinityValue)
        );

        for (int city = 0; city < totalCities; city++) {
            shortestDistance[city][city] = 0;
        }

        for (int road = 0; road < totalRoads; road++) {
            int cityOne, cityTwo;
            long long roadLength;

            cin >> cityOne >> cityTwo >> roadLength;

            cityOne--;
            cityTwo--;

            if (roadLength < shortestDistance[cityOne][cityTwo]) {
                shortestDistance[cityOne][cityTwo] = roadLength;
                shortestDistance[cityTwo][cityOne] = roadLength;
            }
        }

        for (int middleCity = 0; middleCity < totalCities; middleCity++) {
            for (int startCity = 0; startCity < totalCities; startCity++) {
                for (int endCity = 0; endCity < totalCities; endCity++) {
                    if (
                        shortestDistance[startCity][middleCity] == infinityValue ||
                        shortestDistance[middleCity][endCity] == infinityValue
                    ) {
                        continue;
                    }

                    if (
                        shortestDistance[startCity][middleCity] +
                        shortestDistance[middleCity][endCity]
                        <
                        shortestDistance[startCity][endCity]
                    ) {
                        shortestDistance[startCity][endCity] =
                            shortestDistance[startCity][middleCity] +
                            shortestDistance[middleCity][endCity];
                    }
                }
            }
        }

        bool validPath = true;

        for (int i = 0; i + 1 < pathLength; i++) {
            if (
                shortestDistance[visitedCities[i]][visitedCities[i + 1]]
                == infinityValue
            ) {
                validPath = false;
                break;
            }
        }

        if (!validPath) {
            cout << -1 << '\n';
            continue;
        }

        vector<int> targetCities;

        targetCities.push_back(visitedCities[0]);

        int lastTargetIndex = 0;

        for (int currentIndex = 1; currentIndex < pathLength - 1; currentIndex++) {
            int startCity = visitedCities[lastTargetIndex];
            int currentCity = visitedCities[currentIndex];
            int nextCity = visitedCities[currentIndex + 1];

            if (
                shortestDistance[startCity][nextCity]
                <
                shortestDistance[startCity][currentCity] +
                shortestDistance[currentCity][nextCity]
            ) {
                targetCities.push_back(currentCity);
                lastTargetIndex = currentIndex;
            }
        }

        targetCities.push_back(visitedCities[pathLength - 1]);

        cout << targetCities.size() << '\n';
    }

    return 0;
}
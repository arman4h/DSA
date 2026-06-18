#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int testCase;
    cin >> testCase;

    while (testCase--) {
        int totalNodes, totalEdges;
        cin >> totalNodes >> totalEdges;

        vector<vector<pair<int, int>>> graph(totalNodes + 1);

        for (int i = 0; i < totalEdges; i++) {
            int fromNode, toNode, edgeWeight;
            cin >> fromNode >> toNode >> edgeWeight;

            graph[fromNode].push_back({toNode, edgeWeight});
            graph[toNode].push_back({fromNode, edgeWeight});
        }

        vector<int> minimumCost(totalNodes + 1, 1e9);
        vector<int> parentNode(totalNodes + 1, -1);
        vector<bool> visited(totalNodes + 1, false);

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > minHeap;

        minimumCost[1] = 0;
        minHeap.push({0, 1});

        while (!minHeap.empty()) {
            int currentNode = minHeap.top().second;
            minHeap.pop();

            if (visited[currentNode]) {
                continue;
            }

            visited[currentNode] = true;

            for (auto edge : graph[currentNode]) {
                int nextNode = edge.first;
                int weight = edge.second;

                if (!visited[nextNode] && weight < minimumCost[nextNode]) {
                    minimumCost[nextNode] = weight;
                    parentNode[nextNode] = currentNode;
                    minHeap.push({weight, nextNode});
                }
            }
        }

        for (int node = 2; node <= totalNodes; node++) {
            int firstNode = parentNode[node];
            int secondNode = node;

            if (firstNode > secondNode) {
                swap(firstNode, secondNode);
            }

            cout << firstNode << " "
                 << secondNode << " "
                 << minimumCost[node] << endl;
        }
    }

    return 0;
}
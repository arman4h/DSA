#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int totalNodes;
    int totalEdges;

    cin >> totalNodes >> totalEdges;

    vector<vector<int>> graph(totalNodes);

    for (int i = 0; i < totalEdges; i++) {
        int firstNode, secondNode;
        cin >> firstNode >> secondNode;

        graph[firstNode].push_back(secondNode);
        graph[secondNode].push_back(firstNode);
    }

    int sourceNode, destinationNode;
    cin >> sourceNode >> destinationNode;

    vector<bool> visited(totalNodes, false);
    queue<int> bfsQueue;

    bfsQueue.push(sourceNode);
    visited[sourceNode] = true;

    while (!bfsQueue.empty()) {
        int currentNode = bfsQueue.front();
        bfsQueue.pop();

        for (int nextNode : graph[currentNode]) {
            if (!visited[nextNode]) {
                visited[nextNode] = true;
                bfsQueue.push(nextNode);
            }
        }
    }

    if (visited[destinationNode]) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class TreeGraph {
private:
    int totalNodes;
    vector<vector<int>> connections;
    
    pair<int, int> findFarthestNode(int startNode, vector<int>& previousNode) {
        vector<bool> alreadyVisited(totalNodes, false);
        vector<int> distanceFromStart(totalNodes, 0);
        queue<int> nodesToVisit;
        
        nodesToVisit.push(startNode);
        alreadyVisited[startNode] = true;
        previousNode[startNode] = -1;
        
        int mostDistantNode = startNode;
        int longestDistance = 0;
        
        while (!nodesToVisit.empty()) {
            int currentNode = nodesToVisit.front();
            nodesToVisit.pop();
            
            for (int neighborNode : connections[currentNode]) {
                if (!alreadyVisited[neighborNode]) {
                    alreadyVisited[neighborNode] = true;
                    distanceFromStart[neighborNode] = distanceFromStart[currentNode] + 1;
                    previousNode[neighborNode] = currentNode;
                    nodesToVisit.push(neighborNode);
                    
                    if (distanceFromStart[neighborNode] > longestDistance) {
                        longestDistance = distanceFromStart[neighborNode];
                        mostDistantNode = neighborNode;
                    }
                }
            }
        }
        
        return {mostDistantNode, longestDistance};
    }
    
    vector<int> buildPathBetweenNodes(int firstNode, int lastNode, vector<int>& previousNode) {
        vector<int> nodesInPath;
        int currentPosition = lastNode;
        
        while (currentPosition != -1) {
            nodesInPath.push_back(currentPosition);
            currentPosition = previousNode[currentPosition];
        }
        
        vector<int> finalPath;
        for (int i = nodesInPath.size() - 1; i >= 0; i--) {
            finalPath.push_back(nodesInPath[i]);
        }
        
        return finalPath;
    }
    
public:
    TreeGraph(int numNodes) : totalNodes(numNodes) {
        connections.resize(totalNodes);
    }
    
    void createConnection(int node1, int node2) {
        connections[node1].push_back(node2);
        connections[node2].push_back(node1);
    }
    
    void displayConnections() {
        cout << "Condition of the adjacency list" << endl;
        for (int i = 0; i < totalNodes; i++) {
            cout << i << ":";
            for (int connectedNode : connections[i]) {
                cout << "->" << connectedNode;
            }
            cout << endl;
        }
    }
    
    void calculateLongestPath(int startingPoint) {
        vector<int> pathTracker1(totalNodes);
        pair<int, int> firstSearch = findFarthestNode(startingPoint, pathTracker1);
        int endPoint1 = firstSearch.first;
        
        vector<int> pathTracker2(totalNodes);
        pair<int, int> secondSearch = findFarthestNode(endPoint1, pathTracker2);
        int endPoint2 = secondSearch.first;
        int maximumDistance = secondSearch.second;
        
        vector<int> completePath = buildPathBetweenNodes(endPoint1, endPoint2, pathTracker2);
        
        cout << "Maximum shortest path" << endl;
        for (int i = 0; i < completePath.size(); i++) {
            cout << "->" << completePath[i];
        }
        cout << endl;
        
        cout << "Maximum shortest path Distance:" << maximumDistance << endl;
    }
};

int main() {
    int numberOfVertices, numberOfEdges;
    cout << "Enter the number of vertices and edges" << endl;
    cin >> numberOfVertices >> numberOfEdges;
    
    TreeGraph myGraph(numberOfVertices);
    
    cout << "Enter the edges" << endl;
    for (int i = 0; i < numberOfEdges; i++) {
        int vertex1, vertex2;
        cin >> vertex1 >> vertex2;
        myGraph.createConnection(vertex1, vertex2);
    }
    
    int sourceVertex;
    cout << "Enter the source vertex" << endl;
    cin >> sourceVertex;
    
    myGraph.displayConnections();
    myGraph.calculateLongestPath(sourceVertex);
    
    return 0;
}
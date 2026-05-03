#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class DirectedGraph {
private:
    int nodeCount;
    vector<vector<int>> edges;
    
    void exploreNode(int currentNode, vector<bool>& hasBeenVisited, stack<int>& orderStack) {
        hasBeenVisited[currentNode] = true;
        
        for (int nextNode : edges[currentNode]) {
            if (!hasBeenVisited[nextNode]) {
                exploreNode(nextNode, hasBeenVisited, orderStack);
            }
        }
        
        orderStack.push(currentNode);
    }
    
public:
    DirectedGraph(int totalNodes) : nodeCount(totalNodes) {
        edges.resize(totalNodes);
    }
    
    void insertEdge(int fromNode, int toNode) {
        edges[fromNode].push_back(toNode);
    }
    
    void findTopologicalOrder() {
        stack<int> orderStack;
        vector<bool> hasBeenVisited(nodeCount, false);
        
        for (int node = 0; node < nodeCount; node++) {
            if (!hasBeenVisited[node]) {
                exploreNode(node, hasBeenVisited, orderStack);
            }
        }
        
        bool isFirstElement = true;
        while (!orderStack.empty()) {
            if (!isFirstElement) {
                cout << " -> ";
            }
            cout << orderStack.top();
            orderStack.pop();
            isFirstElement = false;
        }
        cout << endl;
    }
};

int main() {
    int totalVertices, totalEdges;
    cin >> totalVertices >> totalEdges;
    
    DirectedGraph dagGraph(totalVertices);
    
    for (int i = 0; i < totalEdges; i++) {
        int startVertex, endVertex;
        cin >> startVertex >> endVertex;
        dagGraph.insertEdge(startVertex, endVertex);
    }
    
    dagGraph.findTopologicalOrder();
    
    return 0;
}
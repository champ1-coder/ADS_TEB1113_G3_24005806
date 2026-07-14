// graphlinkedlist

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <unordered_map>
using namespace std;

// Linked list node for adjacency edges
class EdgeNode {
public:
    string dest;
    int weight;
    EdgeNode* next;
    EdgeNode(string d, int w) : dest(d), weight(w), next(nullptr) {}
};

class Graph {
private:
    unordered_map<string, int> nameToIndex;
    vector<string> indexToName;
    vector<EdgeNode*> adj;      // Each index points to a linked list of edges

public:
    int addVertex(string name) {
        if (nameToIndex.find(name) != nameToIndex.end())
            return nameToIndex[name];
        int idx = adj.size();
        nameToIndex[name] = idx;
        indexToName.push_back(name);
        adj.push_back(nullptr);
        return idx;
    }

    void addDirectedEdge(string u, string v, int w) {
        int uIdx = addVertex(u);
        addVertex(v);  // ensure v exists
        EdgeNode* newNode = new EdgeNode(v, w);
        // Insert at head of u's linked list
        newNode->next = adj[uIdx];
        adj[uIdx] = newNode;
    }

    void addUndirectedEdge(string u, string v, int w) {
        addDirectedEdge(u, v, w);
        addDirectedEdge(v, u, w);
    }

    void display() {
        for (int i = 0; i < adj.size(); ++i) {
            cout << indexToName[i] << " -> ";
            EdgeNode* cur = adj[i];
            while (cur) {
                cout << "(" << cur->dest << ", " << cur->weight << ") ";
                cur = cur->next;
            }
            cout << endl;
        }
    }

    void dijkstra(string srcName) {
        if (nameToIndex.find(srcName) == nameToIndex.end()) return;

        int V = adj.size();
        int src = nameToIndex[srcName];
        vector<int> dist(V, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[src] = 0;
        pq.emplace(0, src);

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue;

            // Traverse the linked list of neighbours of vertex 'u'
            EdgeNode* cur = adj[u];
            while (cur) {
                int v = nameToIndex[cur->dest];
                int w = cur->weight;

                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.emplace(dist[v], v);
                }
                cur = cur->next;   // move to the next node in the list
            }
        }

        cout << "\nShortest distances from " << srcName << ":\n";
        for (int i = 0; i < V; ++i) {
            cout << "  " << srcName << " -> " << indexToName[i] << " : ";
            (dist[i] == INT_MAX) ? cout << "INF\n" : cout << dist[i] << "\n";
        }
    }

    ~Graph() {
        for (auto head : adj) {
            EdgeNode* cur = head;
            while (cur) {
                EdgeNode* temp = cur;
                cur = cur->next;
                delete temp;
            }
        }
    }
};

int main() {
    Graph g;
    g.addUndirectedEdge("A", "B", 4);
    g.addUndirectedEdge("A", "C", 8);
    g.addUndirectedEdge("B", "E", 6);
    g.addUndirectedEdge("B", "C", 3);
    g.addUndirectedEdge("C", "D", 2);
    g.addUndirectedEdge("D", "E", 10);

    cout << "Adjacency list (linked lists):\n";
    g.display();
    g.dijkstra("A");
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const char* input = "INPUT.txt";

class Vertex{
    private:
        int data;
        bool visited = false;
        vector<Vertex*> friendEdge;
    public:
        Vertex(){
            data = 0;
        }
        Vertex(int num){
            data = num;
        }
        int getData(){
            return data;
        }
        void setData(int num){
            data = num;
        }
        bool isVisit(){
            return visited;
        }
        void setVisit(bool t){
            visited = t;
        }
        const vector<Vertex*>& getFriendEdge(){
            return friendEdge;
        }
        void addFriend(Vertex* v){
            friendEdge.push_back(v);
        }
        int friendSize(){
            return int(friendEdge.size());
        }
};

void resetGraph(vector<Vertex*>& Graph){
    for (Vertex* v : Graph) v->setVisit(false);
}

void Visit(Vertex* v){
    cout << v->getData() << " ";
    v->setVisit(true);
    for (Vertex* u : v->getFriendEdge()){
        if (!u->isVisit()) Visit(u);
    }
}

void DFS(vector<Vertex*>& Graph){
    if (Graph.empty()) return;
    cout << "DFS: ";
    for (Vertex* v : Graph){
        if (!v->isVisit()) Visit(v);
    }
    cout << endl;
}

void BFS(vector<Vertex*>& Graph){
    if (Graph.empty()) return;
    cout << "BFS: ";
    queue<Vertex*> que;
    que.push(Graph[0]);
    Graph[0]->setVisit(true);
    while (!que.empty()){
        Vertex* v = que.front();
        cout << v->getData() << " ";
        que.pop();
        for (Vertex* u : v->getFriendEdge()){
            if (!u->isVisit()){
                u->setVisit(true);
                que.push(u);
            }
        }
    }
}

int main(){
    ifstream file(input);
    if (!file.is_open()){
        cout << "LLLL";
        return 0;
    }
    vector<Vertex*> Graph;
    int n; file >> n;
    Graph.resize(n);
    for (int i = 0; i < n; ++i){
        Graph[i] = new Vertex();
        Graph[i]->setData(i);
    }
    int m; file >> m;
    for (int i = 0; i < m; ++i){
        int x,y;
        file >> x >> y;
        Graph[x]->addFriend(Graph[y]);
        Graph[y]->addFriend(Graph[x]); //Nếu là đồ thị có hướng chỉ cần bỏ phần này đi là được
    }
    file.close();
    DFS(Graph);
    resetGraph(Graph);
    BFS(Graph);
    for (int i = 0; i < n; ++i) {
        delete Graph[i];
    }
    Graph.clear();
    return 0;
}

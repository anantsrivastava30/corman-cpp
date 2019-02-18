#if !defined(__POINTER_GRAPH__)
#define __POINTER_GRAPH__

#include<iostream>
#include<memory>
#include<string>
#include<unordered_map>

/*
 A directed graph DS with pointers has three main constituents:
 1. Vertex
    properties :
    a. has a name
    b. has incoming edges
    c. has outgoing edges
 2. Edges
    properties :
    a. has a weight
    b. has a to Vertex and a from Vertex.
    c. information about the sister edges.
 3. Graph
    properties :
    a. size of graph ie number of vertices.
    b. insert vertex.
    c. insert egdes.
 */


struct Edge;

struct Vertex {
    std::string name;
    Edge * outgoing, *incoming;
    int degree;
    Vertex(decltype(name) n) : name(n), outgoing(nullptr), incoming(nullptr), degree(0) {};
    ~Vertex() {};
};

struct Edge {
    int weight;
    Vertex *to, *from;
    Edge * next_to, *prev_to, *next_from, *prev_from;
    Edge(int w, Vertex *to,  Vertex *from) : weight(w), to(to), from(from),
                                             next_to(nullptr), prev_to(nullptr),
                                             next_from(nullptr), prev_from(nullptr) {};
    ~Edge() {};
};

class Graph {
    /*
     where do we save the graph node association for lookup
     */
public:
    std::unordered_map<std::string, Vertex*> g; // to store the vertex and string assocation
    int vertices;

    Graph() : vertices(0) {};
    ~Graph() {
        std::cout << "freeing memory for hamsters" << std::endl;
        //for_each(g.begin(), g.end(), [](std::pair<std::string, Vertex *> v){
        //            delete v.second->outgoing;
        //            delete v.second->incoming;
        //            delete v.second;
        //        });
    };

    Vertex *addVertex(std::string name) {
        auto itr = g.find(name);
        if(itr == g.end()) {
            Vertex *vert = new Vertex(name);
            g[name] = vert;
            std::cout << "Vertex created with name id " << name << std::endl;
            return vert;
            vertices++;
        }
        else
           std::cout << "vertice in graph" << std::endl; 
           return itr->second;
    }

    Edge *addEdge(int w, Vertex *from, Vertex *to) {
        Edge *edge = new Edge(w, to, from);
        // to first
        if(!to->incoming) { // to vertex has no incoming edges; this edge will be the parent edge.
            std::cout << "parent edge going to " << to->name << std::endl;
            to->incoming = edge;
        }
        else {
            auto itr = to->incoming;
            while(itr->next_to) {
                itr = itr->next_to;
            }
            edge->prev_to = itr;
            itr->next_to = edge;
        }

        // from
        if(!from->outgoing) {
            std::cout << "parent edge coming from " << from->name << std::endl;
            from->outgoing = edge;
        }
        else {
            auto itr = from->outgoing;
            while(itr->next_from) {
                itr = itr->next_from;
            }
            edge->prev_from = itr;
            itr->next_from = edge;
        }
        std::cout << "edge and all associations created" << std::endl;
        return edge;
    }
    
    void getAdjVertices(Vertex *vert) {
        while (vert->outgoing) {
            std::cout << vert->outgoing->weight << std::endl;
            vert->outgoing = vert->outgoing->next_from;
        }
    }
};

#endif


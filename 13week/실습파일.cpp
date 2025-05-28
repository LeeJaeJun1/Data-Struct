#include<iostream>
#include<list>
#include<vector>

using namespace std;

class MatrixGraph {
public:
    MatrixGraph() = default;

    list<int> vertices();
    list<int> edges();

    bool is_adjacent_to(int vid1, int vid2);
    list<int> incident_edges(int vid);

    bool insert_vertex(int vid);
    bool insert_edge(int eid, int src, int dst);
    bool erase_edge(int eid);
    bool erase_vertex(int vid);

private:
    class Vertex;
    class Edge;
    Vertex* find_vertex(int vid);
    Edge* find_edge(int eid);

    bool is_adjacent_to(Vertex* u, Vertex* v);
    list<Edge*> incident_edges(Vertex* v);
    bool erase_edge(Edge* e);

    list<Vertex*> vertices_list;
    list<Edge*> edges_list;
    vector<vector<Edge*>> matrix;
};

class MatrixGraph::Vertex {
public:
    Vertex(int vid, int matrix_idx)
        : vid(vid), matrix_idx(matrix_idx) {}
private:
    int vid;
    int matrix_idx;
    list<Vertex*>::iterator vertices_list_pos;
    friend class MatrixGraph;
};

class MatrixGraph::Edge {
public:
    Edge(int eid, Vertex* src, Vertex* dst)
    : eid(eid), src(src),dst(dst) {}
private:
    int eid;
    Vertex* src;
    Vertex* dst;
    list<Edge*>::iterator  edges_list_pos;
    friend class MatrixGraph;
};

list<int> MatrixGraph::vertices() {
    list<int> result;
    for(Vertex* v : vertices_list) {
        result.push_back(v->vid);
    }
    return result;
}

list<int> MatrixGraph::edges() {
    list<int> result;
    for(Edge* e : edges_list) {
        result.push_back(e->eid);
    }
    return result;
}

MatrixGraph::Vertex* MatrixGraph::find_vertex(int vid) {
    for(Vertex* v : vertices_list) {
        if(v->vid == vid) {
            return v;
        }
    }
    return nullptr;
}

MatrixGraph::Edge* MatrixGraph::find_edge(int eid) {
    for(Edge* e : edges_list) {
        if(e->eid==eid) {
            return e;
        }
    }
    return nullptr;
}

bool MatrixGraph::is_adjacent_to(int vid1, int vid2) {
    return is_adjacent_to(find_vertex(vid1), find_vertex(vid2));
}

bool MatrixGraph::is_adjacent_to(MatrixGraph::Vertex *u, MatrixGraph::Vertex *v) {
    if(u==nullptr || v== nullptr) {
        return false;
    }
    return matrix[u->matrix_idx][v->matrix_idx] != nullptr
    || matrix[v->matrix_idx][u->matrix_idx] != nullptr;
}

list<int> MatrixGraph::incident_edges(int vid) {
    list<Edge*> incident_edge_list = incident_edges(find_vertex(vid));
    list<int> result;
    for(Edge* e : incident_edge_list){
        result.push_back(e->eid);
    }
    return result;
}

list<MatrixGraph::Edge*> MatrixGraph::incident_edges(MatrixGraph::Vertex *v) {
    if(v== nullptr) {
        return {};
    }
    list<Edge*> result;
    int matrix_idx = v->matrix_idx;
    for(int i = 0; i < matrix.size(); i++) {
        if(i == matrix_idx) {
            continue;
        }
        if(matrix[i][matrix_idx] != nullptr) {
            result.push_back(matrix[i][matrix_idx]);
        }
    }
    return result;
}

bool MatrixGraph::insert_vertex(int vid) {
    if(find_vertex(vid) != nullptr) {
        return false;
    }

    Vertex* new_vertex = new Vertex(vid, vertices_list.size());
    vertices_list.push_back(new_vertex);
    new_vertex->vertices_list_pos = --vertices_list.end();

    for(vector<Edge*>&arr : matrix) {
        arr.push_back(nullptr);
    }
    matrix.emplace_back(matrix.size()+1, nullptr);
    return true;
}

bool MatrixGraph::insert_edge(int eid, int src_vid, int dst_vid) {
    Vertex* src = find_vertex(src_vid);
    Vertex* dst = find_vertex(dst_vid);
    if(find_edge(eid) != nullptr) {
        return false;
    }
    if(src== nullptr || dst == nullptr) {
        return false;
    }
    if(is_adjacent_to(src,dst)) {
        return false;
    }

    Edge* new_edge = new Edge(eid,src,dst);
    edges_list.push_back(new_edge);
    new_edge->edges_list_pos = --edges_list.end();

    matrix[src->matrix_idx][dst->matrix_idx] = new_edge;
    matrix[dst->matrix_idx][src->matrix_idx] = new_edge;
    return true;
}

bool MatrixGraph::erase_edge(int eid) {
    return erase_edge(find_edge(eid));
}

bool MatrixGraph::erase_edge(Edge* e) {
    if(e== nullptr) {
        return false;
    }
    int src_idx = e->src->matrix_idx;
    int dst_idx = e->dst->matrix_idx;

    matrix[src_idx][dst_idx] = matrix[dst_idx][src_idx] = nullptr;
    edges_list.erase(e->edges_list_pos);
    delete e;
    return true;
}

bool MatrixGraph::erase_vertex(int vid) {
    Vertex* v = find_vertex(vid);
    if(v== nullptr) {
        return false;
    }

    for(Edge* e : incident_edges(v)) {
        erase_edge(e);
    }

    int matrix_idx = v->matrix_idx;
    for(int i = 0; i < matrix.size(); i++) {
        if(i==matrix_idx) { continue;}
        matrix[i].erase(matrix[i].begin() + matrix_idx);
    }
    matrix.erase(matrix.begin() + matrix_idx);

    for(Vertex* other : vertices_list) {
        if(other->matrix_idx > matrix_idx) {
            --other->matrix_idx;
        }
    }

    vertices_list.erase(v->vertices_list_pos);
    delete v;
    return true;
}


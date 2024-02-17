#pragma once

#include <cassert>
#include <vector>

template <typename T = long long> struct Edge {
    int id;
    int from;
    int to;
    T cost;
    bool operator<(const Edge& other) const { return cost < other.cost; }
    bool operator>(const Edge& other) const { return cost > other.cost; }
    Edge& operator=(const T& x) {
        to = x;
        return *this;
    }
    operator int() const { return to; }
};

template <typename T = long long> struct Graph {
    int _n;
    std::vector<std::vector<Edge<T>>> _graph;
    const T INF = std::numeric_limits<T>::max() / 2;
    std::vector<Edge<T>> _edges;
    Graph(int n) : _n(n) { _graph.resize(_n); }
    std::vector<Edge<T>>& operator[](int i) { return _graph[i]; }
    int size() { return _n; }
    void add_edge(int u, int v, T cost) {
        assert(0 <= u && u < _n);
        assert(0 <= v && v < _n);
        int id = (int)_edges.size();
        _graph[u].push_back({id, u, v, cost});
        _graph[v].push_back({id, v, u, cost});
        _edges.push_back({id, u, v, cost});
    }
    void add_edge_directed(int from, int to, T cost) {
        assert(0 <= from && from < _n);
        assert(0 <= to && to < _n);
        int id = (int)_edges.size();
        _graph[from].push_back({(int)_edges.size(), from, to, cost});
        _edges.push_back({id, from, to, cost});
    }
    void add_edge(int u, int v) { add_edge(u, v, 1); }
    void add_edge_directed(int from, int to) { add_edge_directed(from, to, 1); }
    Edge<T> getEdge(int i) {
        assert(0 <= i && i < (int)_edges.size());
        return _edges[i];
    }
};
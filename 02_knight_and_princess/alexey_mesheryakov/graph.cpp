#include <assert.h>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

constexpr int VERTEX_COUNT = 14;
constexpr int INVALID_ID = -1;

using std::pair;
using std::vector;
using EdgeId = int;
using VertexId = int;

class Graph {
 public:
  class Edge {
   public:
    Edge(const pair<VertexId, VertexId>& vertex_ids, const EdgeId& edge_id)
        : vertex_ids_(vertex_ids), id_(edge_id) {}

    std::string to_string() const {
      std::stringstream buffer;
      buffer << "{\"id\":" << id_ << ",\"vertex_ids\":[" << vertex_ids_.first
             << "," << vertex_ids_.second << "]}";
      return buffer.str();
    }
    pair<VertexId, VertexId> get_vertex_ids() const { return vertex_ids_; }

   private:
    const EdgeId id_ = INVALID_ID;
    const pair<VertexId, VertexId> vertex_ids_ = {};
  };
  class Vertex {
   public:
    explicit Vertex(const VertexId& id) : id_(id) {}

    std::string to_string() const {
      std::stringstream buffer;
      buffer << "{\"id\":" << id_ << ",\"edge_ids\":[";
      for (int i = 0; i < edge_ids_.size() - 1; i++)
        buffer << edge_ids_[i] << ",";
      buffer << edge_ids_[edge_ids_.size() - 1] << "]}";
      return buffer.str();
    }

    void add_edge(const EdgeId& edge_id) {
      edge_ids_.push_back(edge_id);
      assert(edge_id_not_exist(edge_id) && "Edge id already exist");
    }

   private:
    bool edge_id_not_exist(const EdgeId& new_edge_id) {
      bool exist = false;
      for (const auto& edge_id : edge_ids_)
        exist = exist || (edge_id == new_edge_id);
      return !exist;
    }
    const VertexId id_ = INVALID_ID;
    vector<EdgeId> edge_ids_ = {};
  };

  const bool vertex_exist(const VertexId& id) {
    return (0 <= id) && (id < vertex_id_counter_);
  }

  const bool edge_exist(const EdgeId& id) {
    return (0 <= id) && (id < edge_id_counter_);
  }

  const bool edge_exist(const VertexId& first, const VertexId& second) {
    bool exist = false;
    for (const auto& edge : edges_) {
      auto vertices = edge.get_vertex_ids();
      exist = exist || (vertices.first == first && vertices.second == second) ||
              (vertices.second == first && vertices.first == second);
    }
    return exist;
  }

  void add_vertex() { vertices_.emplace_back(vertex_id_counter_++); }

  void add_edge(const VertexId& first, const VertexId& second) {
    assert(vertex_exist(first) && "Source vertex id doesn't exist");
    assert(vertex_exist(second) && "Destination vertex id doesn't exist");
    assert(edge_exist(first, second) && "Such edge already exist");
    edges_.push_back(Edge({first, second}, edge_id_counter_));
    vertices_[first].add_edge(edge_id_counter_);
    vertices_[second].add_edge(edge_id_counter_);
    edge_id_counter_++;
  }

  std::string to_json() const {
    std::stringstream buffer;
    buffer << "{\"vertices\":[";
    for (int j = 0; j < vertices_.size(); j++) {
      const Vertex vertex = vertices_[j];
      buffer << vertex.to_string();
      if (j != vertices_.size() - 1)
        buffer << ",";
    }
    buffer << "],\"edges\":[";
    for (int j = 0; j < edges_.size(); j++) {
      const Edge edge = edges_[j];
      buffer << edge.to_string();
      if (j != edges_.size() - 1)
        buffer << ",";
    }
    buffer << "]}\n";
    return buffer.str();
  }

 private:
  vector<Edge> edges_ = {};
  vector<Vertex> vertices_ = {};
  VertexId vertex_id_counter_ = 0;
  EdgeId edge_id_counter_ = 0;
};

int main() {
  Graph graph;
  const vector<pair<VertexId, VertexId> > edges = {
      {0, 1},  {0, 2},  {0, 3},  {1, 4},   {1, 5},   {1, 6},
      {2, 7},  {2, 8},  {3, 9},  {4, 10},  {5, 10},  {6, 10},
      {7, 11}, {8, 11}, {9, 12}, {10, 13}, {11, 13}, {12, 13}};
  for (int i = 0; i < VERTEX_COUNT; i++) {
    graph.add_vertex();
  }
  for (const auto& edge : edges) {
    graph.add_edge(edge.first, edge.second);
  }
  std::ofstream file;
  file.open("graph.json", std::fstream::out | std::fstream::trunc);
  file << graph.to_json();
  file.close();
  return 0;
}

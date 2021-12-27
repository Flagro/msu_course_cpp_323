#pragma once

#include <functional>
#include <map>
#include <queue>
#include <tuple>
#include <vector>

#include "graph.hpp"
#include "graph_path.hpp"

namespace uni_cource_cpp {
class GraphTraverser {
 public:
  GraphTraverser(const Graph& graph);
  static std::map<VertexId, int> get_updated_depths(
      const Graph& graph,
      const std::map<int, std::set<VertexId>>& known_depths,
      int start_depth);
  GraphPath find_shortest_path(VertexId source_vertex_id,
                               VertexId destination_vertex_id) const;
  GraphPath find_fastest_path(VertexId source_vertex_id,
                              VertexId destination_vertex_id) const;
  std::vector<GraphPath> find_all_shortest_paths(
      VertexId source_vertex_id,
      std::set<VertexId> destination_vertices_ids) const;

 private:
  using Weight = int;
  using GetWeightCallback = std::function<Weight(const EdgeId& edge_id)>;

  const Graph& graph_;

  GraphPath find_dijkstra_path(
      VertexId source_vertex_id,
      VertexId destination_vertex_id,
      const GetWeightCallback& get_weight_callback) const;
};
}  // namespace uni_cource_cpp

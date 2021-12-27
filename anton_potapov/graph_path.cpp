#include <utility>
#include <vector>

#include "graph.hpp"
#include "graph_path.hpp"

namespace uni_cource_cpp {
GraphPath::GraphPath(const Graph& graph,
                     std::vector<VertexId> vertex_ids_vector,
                     std::vector<EdgeId> edge_ids_vector)
    : graph_(graph),
      vertex_ids_(std::move(vertex_ids_vector)),
      edge_ids_(std::move(edge_ids_vector)) {}

GraphPath::Distance GraphPath::distance() const {
  return edge_ids_.size();
}

Edge::Duration GraphPath::duration() const {
  Edge::Duration result = 0;
  for (const auto& edge_id : edge_ids_) {
    result += graph_.get_edge(edge_id).get_duration();
  }
  return result;
}

const std::vector<VertexId>& GraphPath::path_vector_ids() const {
  return vertex_ids_;
}
}  // namespace uni_cource_cpp

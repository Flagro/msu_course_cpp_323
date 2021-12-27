#include <utility>
#include <vector>

#include "graph.hpp"
#include "graph_path.hpp"

namespace uni_cource_cpp {
GraphPath::GraphPath(std::vector<VertexId> vertex_ids_vector,
                     std::vector<EdgeId> edge_ids_vector,
                     const Edge::Duration& duration)
    : duration_(duration),
      vertex_ids_(std::move(vertex_ids_vector)),
      edge_ids_(std::move(edge_ids_vector)) {}

GraphPath::Distance GraphPath::distance() const {
  return edge_ids_.size();
}

const Edge::Duration& GraphPath::duration() const {
  return duration_;
}

const std::vector<VertexId>& GraphPath::path_vector_ids() const {
  return vertex_ids_;
}
}  // namespace uni_cource_cpp

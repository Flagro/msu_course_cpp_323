#pragma once

#include <vector>

#include "graph.hpp"

namespace uni_cource_cpp {
class GraphPath {
 public:
  using Distance = int;

  GraphPath(std::vector<VertexId> vertex_ids,
            std::vector<EdgeId> edge_ids,
            const Edge::Duration& duration);

  const std::vector<VertexId>& path_vector_ids() const;

  Distance distance() const;
  const Edge::Duration& duration() const;

 private:
  Edge::Duration duration_;
  std::vector<VertexId> vertex_ids_;
  std::vector<EdgeId> edge_ids_;
};
}  // namespace uni_cource_cpp

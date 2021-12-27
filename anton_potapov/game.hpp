#pragma once

#include "graph.hpp"
#include "graph_path.hpp"
#include "graph_traverser.hpp"

namespace uni_cource_cpp {
class Game {
 public:
  const VertexId knight_position;
  const VertexId princess_position;

  Game(Graph game_map,
       const VertexId& knight_position_id,
       const VertexId& princess_position_id);

  GraphPath find_shortest_path() const;
  GraphPath find_fastest_path() const;
  Graph& map();

 private:
  Graph game_map_;
};
}  // namespace uni_cource_cpp

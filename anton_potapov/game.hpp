#include "graph.hpp"
#include "graph_path.hpp"
#include "graph_traverser.hpp"

namespace uni_cource_cpp {
class Game {
 public:
  Game(Graph game_map,
       const VertexId& knight_position,
       const VertexId& princess_position);

  GraphPath find_shortest_path() const;
  GraphPath find_fastest_path() const;
  Graph& map();

 private:
  Graph game_map_;
  const VertexId knight_position_;
  const VertexId princess_position_;
};
}  // namespace uni_cource_cpp

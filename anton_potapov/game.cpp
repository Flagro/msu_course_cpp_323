#include "game.hpp"
#include "graph_path.hpp"
#include "graph_traverser.hpp"

namespace uni_cource_cpp {
Game::Game(Graph game_map,
           const VertexId& knight_position,
           const VertexId& princess_position)
    : game_map_(game_map),
      knight_position_(knight_position),
      princess_position_(princess_position) {}

GraphPath Game::find_shortest_path() const {
  return GraphTraverser(game_map_).find_shortest_path(knight_position_,
                                                      princess_position_);
}

GraphPath Game::find_fastest_path() const {
  return GraphTraverser(game_map_).find_fastest_path(knight_position_,
                                                     princess_position_);
}

Graph& Game::map() {
  return game_map_;
}
}  // namespace uni_cource_cpp

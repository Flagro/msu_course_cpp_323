#include "game_generator.hpp"
#include "game.hpp"
#include "graph.hpp"
#include "graph_generator.hpp"

namespace uni_cource_cpp {
GameGenerator::GameGenerator(const GraphGenerator::Params& params)
    : params_(params) {}
Game GameGenerator::generate_game() const {
  auto graph = GraphGenerator(params_).generate_graph();
  const auto knight_position = graph.get_root_vertex_id();
  const auto princess_position =
      get_random_vertex_id(graph.get_vertices_at_depth(graph.depth()));
  return Game(graph, knight_position, princess_position);
}
}  // namespace uni_cource_cpp

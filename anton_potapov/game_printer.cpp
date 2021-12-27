#include <iostream>
#include <sstream>
#include <string>

#include "game.hpp"
#include "game_printer.hpp"
#include "graph.hpp"
#include "graph_printer.hpp"

namespace uni_cource_cpp {
GamePrinter::GamePrinter(Game& input_game) : game_(input_game) {}

std::string GamePrinter::print_game() const {
  std::stringstream result_stringstream;
  result_stringstream << "{" << std::endl
                      << "\tmap: "
                      << GraphPrinter(game_.map()).print_graph_description()
                      << "," << std::endl;
  result_stringstream << "\tknight position: "
                      << print_position(game_.knight_position) << ","
                      << std::endl;
  result_stringstream << "\tprincess position: "
                      << print_position(game_.princess_position) << std::endl
                      << "}";
  return result_stringstream.str();
};

std::string GamePrinter::print_position(const VertexId& vertex_id) const {
  std::stringstream position_stringstream;
  position_stringstream << "{vertex_id: " << vertex_id << ", depth: "
                        << game_.map().get_vertex(vertex_id).depth << "}";
  return position_stringstream.str();
}
}  // namespace uni_cource_cpp

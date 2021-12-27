#pragma once

#include "game.hpp"
#include "graph_generator.hpp"

namespace uni_cource_cpp {
class GameGenerator {
 public:
  explicit GameGenerator(
      const GraphGenerator::Params& params = GraphGenerator::Params());
  Game generate_game() const;

 private:
  const GraphGenerator::Params params_{};
};
}  // namespace uni_cource_cpp

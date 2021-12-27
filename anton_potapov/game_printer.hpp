#pragma once

#include "game.hpp"

namespace uni_cource_cpp {
class GamePrinter {
 public:
  explicit GamePrinter(Game& input_game);
  std::string print_game() const;
  std::string print_position() const;

 private:
  Game& game_;
};
}  // namespace uni_cource_cpp

#pragma once

#include <string>

namespace uni_cource_cpp {
class LogMessagesGenerator {
 public:
  static std::string generation_started_string(int id);

  static std::string generation_finished_string(
      int id,
      const std::string& graph_description);

  static std::string generation_max_depth_warning(int id,
                                                  int max_generated_depth,
                                                  int given_depth);
  static std::string traversal_started_string(int index);
  static std::string traversal_finished_string(int index,
                                               const std::string& paths);
  static std::string game_preparing_string();
  static std::string game_ready_string(const std::string& game_description);
  static std::string shortest_path_searching_string();
  static std::string shortest_path_ready_string(const std::string& path_string);
  static std::string fastest_path_searching_string();
  static std::string fastest_path_ready_string(const std::string& path_string);
};
}  // namespace uni_cource_cpp

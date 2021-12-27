#include <chrono>
#include <iomanip>
#include <sstream>
#include <string>

#include "log_messages_generator.hpp"

namespace {
std::string get_current_date_time() {
  const auto date_time = std::chrono::system_clock::now();
  const auto date_time_t = std::chrono::system_clock::to_time_t(date_time);
  std::stringstream date_time_string;
  date_time_string << std::put_time(std::localtime(&date_time_t),
                                    "%Y.%m.%d %H:%M:%S");
  return date_time_string.str();
}
}  // namespace

namespace uni_cource_cpp {
std::string LogMessagesGenerator::generation_started_string(int id) {
  std::stringstream generation_started_stringstream;
  generation_started_stringstream << get_current_date_time() << ": Graph " << id
                                  << ", Generation Started" << std::endl;
  return generation_started_stringstream.str();
}

std::string LogMessagesGenerator::generation_finished_string(
    int id,
    const std::string& graph_description) {
  std::stringstream generation_finished_stringstream;
  generation_finished_stringstream << get_current_date_time() << ": Graph "
                                   << id << ", Generation Finished "
                                   << graph_description << std::endl;
  return generation_finished_stringstream.str();
}

std::string LogMessagesGenerator::generation_max_depth_warning(
    int id,
    int max_generated_depth,
    int given_depth) {
  std::stringstream generation_max_depth_warning_stringstream;
  generation_max_depth_warning_stringstream
      << get_current_date_time() << ": Graph " << id
      << "generated graph's depth=" << max_generated_depth
      << " is less than specified one =" << given_depth << std::endl;
  return generation_max_depth_warning_stringstream.str();
}

std::string LogMessagesGenerator::traversal_started_string(int id) {
  std::stringstream traversal_started_stringstream;
  traversal_started_stringstream << get_current_date_time() << ": Graph " << id
                                 << ", Traversal Started" << std::endl;
  return traversal_started_stringstream.str();
}

std::string LogMessagesGenerator::traversal_finished_string(
    int id,
    const std::string& graph_paths) {
  std::stringstream traversal_finished_stringstream;
  traversal_finished_stringstream
      << get_current_date_time() << ": Graph " << id
      << ", Traversal Finished, Paths: " << graph_paths << std::endl;
  return traversal_finished_stringstream.str();
}

std::string LogMessagesGenerator::game_preparing_string() {
  std::stringstream game_preparing_stringstream;
  game_preparing_stringstream << get_current_date_time()
                              << " Game is preparing..." << std::endl;
  return game_preparing_stringstream.str();
}
std::string LogMessagesGenerator::game_ready_string(
    const std::string& game_description) {
  std::stringstream game_ready_stringstream;
  game_ready_stringstream << get_current_date_time() << " Game is ready "
                          << game_description << std::endl;
  return game_ready_stringstream.str();
};
std::string LogMessagesGenerator::shortest_path_searching_string() {
  std::stringstream path_searching_started_stringstream;
  path_searching_started_stringstream << get_current_date_time()
                                      << " Searching for the shortest path..."
                                      << std::endl;
  return path_searching_started_stringstream.str();
}
std::string LogMessagesGenerator::shortest_path_ready_string(
    const std::string& path_string) {
  std::stringstream shortest_path_stringstream;
  shortest_path_stringstream << get_current_date_time()
                             << " Shortest Path: " << path_string << std::endl;
  return shortest_path_stringstream.str();
}
std::string LogMessagesGenerator::fastest_path_searching_string() {
  std::stringstream path_searching_started_stringstream;
  path_searching_started_stringstream << get_current_date_time()
                                      << " Searching for the fastest path..."
                                      << std::endl;
  return path_searching_started_stringstream.str();
}
std::string LogMessagesGenerator::fastest_path_ready_string(
    const std::string& path_string) {
  std::stringstream fastest_path_stringstream;
  fastest_path_stringstream << get_current_date_time()
                            << " Fastest Path: " << path_string << std::endl;
  return fastest_path_stringstream.str();
}
}  // namespace uni_cource_cpp

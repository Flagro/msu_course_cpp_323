#include <filesystem>
#include <fstream>
#include <string>
#include <utility>

#include "config.hpp"
#include "game_generator.hpp"
#include "graph_generator.hpp"
#include "graph_input_handler.hpp"
#include "graph_path.hpp"
#include "graph_printer.hpp"
#include "log_messages_generator.hpp"
#include "logger.hpp"

using uni_cource_cpp::GameGenerator;
using uni_cource_cpp::GraphGenerator;
using uni_cource_cpp::GraphInputHandler;
using uni_cource_cpp::GraphPath;
using uni_cource_cpp::GraphPrinter;
using uni_cource_cpp::Logger;
using uni_cource_cpp::LogMessagesGenerator;

void prepare_temp_directory() {
  std::filesystem::create_directory(
      uni_cource_cpp::config::TEMP_DIRECTORY_PATH);
}

void write_to_file(const std::string& file_text, const std::string& file_path) {
  std::fstream json_file;
  json_file.open(file_path, std::ios::out);
  if (!json_file.is_open()) {
    throw std::runtime_error("file not created");
  }
  json_file << file_text << std::endl;
  json_file.close();
}

int main() {
  const auto depth = GraphInputHandler::handle_depth_input();
  const auto new_vertices_count =
      GraphInputHandler::handle_new_vertices_count_input();

  prepare_temp_directory();

  auto& logger = Logger::get_logger();

  // logger.log(LogMessagesGenerator::game_preparing_string());

  const auto params = GraphGenerator::Params(depth, new_vertices_count);

  const auto game_generator = GameGenerator(params);
  auto game = game_generator.generate_game();

  // logger.log(LogMessagesGenerator::game_ready_string(game));
  // logger.log(LogMessagesGenerator::shortest_path_searching_string());

  const auto shortest_path = game.find_shortest_path();

  // logger.log(LogMessagesGenerator::shortest_path_ready_string(shortest_path));
  // logger.log(LogMessagesGenerator::fastest_path_searching_string());

  const auto fastest_path = game.find_fastest_path();

  // logger.log(LogMessagesGenerator::fastest_path_ready_string(fastest_path));

  const auto map_json = GraphPrinter(game.map()).print();
  write_to_file(map_json, "map.json");

  return 0;
}

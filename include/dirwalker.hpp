// Copyright 2021 Your Name <your_email>

#ifndef INCLUDE_DIRWALKER_HPP_
#define INCLUDE_DIRWALKER_HPP_

#include <filesystem>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

#include "boost/filesystem.hpp"

struct Statistic {
  int date;
  std::string account;
  std::string broker;
  int num_files;
};
class DirectoryWalker {
 private:
  std::vector<std::string> files;
  std::vector<boost::filesystem::path> directories;
  std::vector<Statistic> statistics;

 public:
  void read_directory(std::string directory, bool output_list);
  void output_statistics();
};
#endif  // INCLUDE_DIRWALKER_HPP_

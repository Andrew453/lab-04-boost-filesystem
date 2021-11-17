// Copyright 2021 Your Name <your_email>

#include <dirwalker.hpp>
#include <iostream>
#include <stdexcept>

#include "boost/filesystem.hpp"

using namespace std;

auto example() -> void { throw std::runtime_error("not implemented"); }

void DirectoryWalker::output_finded_files() {}
DirectoryWalker::DirectoryWalker() {

}
void DirectoryWalker::output_statistics() {
  for (auto& st : statistics) {
    std::cout << "broker: " << setw(10) << left << st.broker
              << "account:" << setw(10) << left << st.account
              << "number of files:" << setw(10) << left << st.num_files
              << "lastdate:" << setw(10) << left << st.date << endl;
  }
}

void DirectoryWalker::read_directory(std::string directory, bool output_list) {
  //Записываем начальный список путей
  for (const boost::filesystem::directory_entry& object :
       boost::filesystem::directory_iterator{directory}) {
    if (is_directory(object)) {
      directories.push_back(object);
    }
  }

  for (auto& element : directories) {
    for (const boost::filesystem::directory_entry& object :
         boost::filesystem::directory_iterator{element}) {
      if (is_directory(object)) {
        directories.push_back(object);
      } else if (boost::filesystem::is_regular_file(object)) {
        cmatch m;
        bool checker = false;
        regex_search(object.path().c_str(), m,
                     regex("([a-z]+)/balance_([0-9]+)_([0-9]+).txt"));
        if (m[0] != "") {
          if (output_list) {
            cout << m[1] << " balance_" << m[2] << "_" << m[3] << ".txt"
                 << endl;
          }
          for (auto& st : statistics) {
            if (st.broker == m[1]) {
              if (std::stoi(m[3]) > st.date) {
                st.date = std::stoi(m[3]);
                st.account = m[2];
              }
              checker = true;
              st.num_files++;
            }
          }
          if (!checker) {
            Statistic statistic;
            statistic.broker = m[1];
            statistic.date = std::stoi(m[3]);
            statistic.account = m[2];
            statistic.num_files = 1;
            statistics.push_back(statistic);
          }
        }
        checker = false;
      }
    }
  }
}

DirectoryWalker::~DirectoryWalker() {
  std::cout << "Thank you for choosing my service" << std::endl;
}
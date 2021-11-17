#include <dirwalker.hpp>

using namespace std;

int main() {
  DirectoryWalker directoryWalker;
  directoryWalker.read_directory("../misc/ftp", false);
  directoryWalker.output_statistics();
//  asdas
}
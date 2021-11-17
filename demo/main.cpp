#include <dirwalker.hpp>

using namespace std;

int main() {
  DirectoryWalker directoryWalker;
  directoryWalker.read_directory("../misc/ftp", false);
  directoryWalker.output_statistics();
//  string a = "balance_01234567_76543210.txt";
//  cmatch m;
//  std::string object = "/home/prokiprok/CLionProjects/labs/lab-04-boost-filesystem/misc/ftp/bcs/balance_01234567_76543210.txt";
//  regex_search(object.c_str(), m, regex("([a-z]+)/balance_([0-9]+)_([0-9]+).txt"));
////    regex_search("/home/prokiprok/CLionProjects/labs/lab-04-boost-filesystem/misc/ftp/bcs/balance_01234567_76543210.txt", m, regex("([a-z]+)/balance_([0-9]+)_([0-9]+).txt"));
//    cout << m[0] << endl;
//    cout << m[1] << endl;
//    cout << m[2] << endl;
//    cout << m[3] << endl;
}
#include "clip.hpp"
#include "searcher.hpp"

#include <fstream>
#include <iostream>

int main(int argc, char **argv)
{
  cmd_clip::clip c(std::string("test"));

  std::filebuf f;
  f.open("test", std::ios::in);

  std::istream i(&f);

  c.load(i);

  std::cout << "Command count: " << c.cmd_count() << std::endl;
 
  int j = 0;
  std::string s;

  while(c.get_clip(j++, s))
  {
    std::cout << "\tCommand " << j << " : '" << s << "'" << std::endl;
  }

  cmd_clip::searcher search;

  std::string test1("test1 value");
  std::string test2("test2 value");

  search.add("test1", &test1);
  search.add("test2", &test1);

  std::cout << "Find test1: " << *((std::string *)search.find("test1")) << std::endl;

  std::vector<void *> v;
  search.find_loose("test", v);

  std::cout << "Loose find test: " << v.size() << std::endl;

  v.clear();
  search.find_loose("tet", v);

  std::cout << "Loose find tet: " << v.size() << std::endl;

   v.clear();
  search.find_loose("test1", v);

  std::cout << "Loose find test1: " << v.size() << std::endl;

 return 0;
}
#include "clip.hpp"

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

  return 0;
}
#pragma once

#include <vector>
#include <istream>

namespace cmd_clip 
{
  class clip
  {
  public:

    clip(const std::string &path);

    int cmd_count() { return cmds.size(); }
    bool get_clip(int cmd_num, std::string &cmd);

    bool load(std::istream &in);

  protected:

    std::string path;
    std::vector<std::string> cmds;

  };
}
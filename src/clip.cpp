#include "clip.hpp"

cmd_clip::clip::clip(const std::string &path)
{
  this->path = path;
}

bool cmd_clip::clip::get_clip(int cmd_num, std::string &cmd)
{
  if(cmd_num >= cmd_count()) return false;

  cmd = cmds[cmd_num];
  return true;
}

// Shamelessly lifted from StackOverflow: http://stackoverflow.com/a/17976541
static std::string trim(const std::string &s)
{
   auto  wsfront=std::find_if(s.begin(),s.end(),[](int c){return !std::isspace(c);});
   return std::string(wsfront,std::find_if(s.rbegin(),std::string::const_reverse_iterator(wsfront),[](int c){return !std::isspace(c);}).base());
}

bool cmd_clip::clip::load(std::istream &in)
{
  std::string line;

  while(getline(in, line))
  {
    line = trim(line);

    if(line[0] == '#')
    {
      if(line[1] == '#')
      {
        // A '#' can be inserted by using '##'. Drop the first '#'.
        line.erase(line.begin());
      }
      else
      {
        // Comments are marked with a '#'.
        continue;
      }
    }

    // Ignore blank lines.
    if(line.size() == 0) continue;

    cmds.push_back(line); 
  }

  return true;
}
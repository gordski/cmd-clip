#include "searcher.hpp"

#include <map>

namespace cmd_clip
{
  class searcher_node
  {
  public:

    searcher_node()
    {
      value = NULL;
    }

    searcher_node(void * value)
    {
      this->value = value;
    }

    ~searcher_node()
    {
    }

    void add(const std::string::const_iterator &start,
             const std::string::const_iterator &end,
             void *value)
    {
      if(start != end)
      {
        children[*start].add(start + 1, end, value);
      }
      else
      {
        this->value = value;
      }
    }

    void *find(const std::string::const_iterator &start,
               const std::string::const_iterator &end)
    {
      if(start == end)
      { 
        return value;
      }
      else
      {
        std::map<char, searcher_node>::iterator child = children.find(*start);
        
        if(child == children.end())
        {
          return NULL;
        }
        else
        {
          return (*child).second.find(start + 1, end);
        }
      }
    }

    bool find_loose(const std::string::const_iterator &start,
                    const std::string::const_iterator &end,
                    std::vector<void *> &results)
    {
      if(start == end)
      { 
        // Reached the end of the search term.
        for(std::pair<char, searcher_node> p : children)
        {
          p.second.get_all(results);
        }

        if(value != NULL) results.push_back(value);

        return true;
      }
      else
      {

        bool complete = false;

        std::map<char, searcher_node>::iterator child = children.find(*start);
        
        for(std::pair<char, searcher_node> p : children)
        {
          if(p.first == *start)
          {
            // This node matches the current position in the search term.
            complete |= p.second.find_loose(start + 1, end, results);
          }
          else
          {
            // This node doesn't appear at this position in the search term.
            complete |= p.second.find_loose(start, end, results);
          }
        }

        return complete;
      }
    }

    void get_all(std::vector<void *> &results)
    {
      if(value != NULL) results.push_back(value);

      for(std::pair<char, searcher_node> p : children)
      {
        p.second.get_all(results);
      }
    }

  protected:

    std::map<char, searcher_node> children;

    void *value;

  };
}

cmd_clip::searcher::searcher()
{
  root = new searcher_node();
}

cmd_clip::searcher::~searcher()
{
  delete root;
}

void cmd_clip::searcher::add(const std::string &key, void *value)
{
  if(value == NULL || key.length() <= 0) return;

  root->add(key.begin(), key.end(), value);
}

void *cmd_clip::searcher::find(const std::string &key)
{
  return root->find(key.begin(), key.end());
}

void cmd_clip::searcher::find_loose(const std::string &search_term, std::vector<void*> &results)
{
  root->find_loose(search_term.begin(), search_term.end(), results);
}
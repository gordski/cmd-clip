#pragma once

#include <string>
#include <vector>

namespace cmd_clip
{
	class searcher_node;

	class searcher
	{
	public:

		searcher();
		virtual ~searcher();

		void add(const std::string &key, void *value);

		void remove(const std::string &key);

		void* find(const std::string &key);
		void  find_loose(const std::string &search_term, std::vector<void*> &results);

	protected:

		searcher_node *root;
	};
}
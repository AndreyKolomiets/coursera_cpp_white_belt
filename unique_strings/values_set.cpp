#include <set>
#include <map>
#include <string>

set<string> BuildMapValuesSet(const map<int, string>& m) {
	set<string> out;
	for (const auto& item: m) {
		out.insert(item.second);
	}
	return out;
}

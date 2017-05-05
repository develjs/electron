#include <vector>

namespace asar {
	void encodeBuffer(std::vector<char> *buf);
	void encodeBuffer(std::string *buf);
	void encodeBuffer(char *buf, int count);
}


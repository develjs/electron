// encode with simple XOR algorithm
// used ASAR_ENCODE_KEY for encode key

#include "atom/common/asar/asar_encode.h"
#include <string>

namespace asar {
	void encodeBuffer(std::vector<char> *buf) {
		#ifdef ASAR_ENCODE_KEY
		for (std::vector<char>::size_type i=0; i<buf->size(); i++) {
			buf->operator[](i) = buf->operator[](i) ^ ASAR_ENCODE_KEY;
		}
		#endif
	}
	
	void encodeBuffer(std::string *buf){
		#ifdef ASAR_ENCODE_KEY
		for (std::string::size_type i=0; i<buf->size(); i++) {
			buf->operator[](i) = buf->operator[](i) ^ ASAR_ENCODE_KEY;
		}
		#endif
	}
	
	void encodeBuffer(char *buf, int count){
		#ifdef ASAR_ENCODE_KEY
		for (int i=0; i<count; i++) {
			buf[i] = buf[i] ^ ASAR_ENCODE_KEY;
		}
		#endif
	}
	
}  // asar namespace


// AsarEncodeStream definition
// encode with simple XOR algorithm
// used ASAR_ENCODE_KEY for encode key

#include "atom/browser/net/asar/asar_encode_stream.h"
#include <algorithm>
#include <utility>
#include "base/bind.h"
#include "base/bit_cast.h"
#include "base/logging.h"
#include "base/memory/ref_counted.h"
#include "net/base/io_buffer.h"

namespace asar {
	AsarEncodeStream::~AsarEncodeStream() {}
	
	std::unique_ptr<AsarEncodeStream> AsarEncodeStream::Create(
		std::unique_ptr<SourceStream> upstream,
		SourceStream::SourceType type) {
		std::unique_ptr<AsarEncodeStream> source(
			new AsarEncodeStream(std::move(upstream), type));
		return source;
	}

	AsarEncodeStream::AsarEncodeStream(std::unique_ptr<SourceStream> upstream,
		SourceStream::SourceType type)
		: FilterSourceStream(type, std::move(upstream)) {}


	std::string AsarEncodeStream::GetTypeAsString() const {
		//switch (type()) 
		return "";
	}

	int AsarEncodeStream::FilterData(
		net::IOBuffer* output_buffer,
		int	      output_buffer_size,
		net::IOBuffer* input_buffer,
		int       input_buffer_size,
		int* consumed_bytes,
		bool upstream_end_reached) {
		*consumed_bytes = 0;

		int bytes_out = std::min(input_buffer_size, output_buffer_size);  // bytes to copy
		if (bytes_out > 0) {
#ifdef ASAR_ENCODE_KEY
			for (int i = 0; i < bytes_out; i++) {
				*(output_buffer->data() + i) = *(input_buffer->data() + i) ^ ASAR_ENCODE_KEY;
			}
#else
			memcpy(output_buffer->data(), input_buffer->data(), bytes_out);
#endif
		}
		else
			bytes_out = 0;

		*consumed_bytes = bytes_out;
		return bytes_out;
	}

}  // namespace asar
   

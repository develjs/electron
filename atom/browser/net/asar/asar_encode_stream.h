#ifndef NET_FILTER_ASAR_ENCODE_STREAM_
#define NET_FILTER_ASAR_ENCODE_STREAM_
#include <memory>
#include <string>
#include "base/macros.h"
#include "net/base/net_export.h"
#include "net/filter/filter_source_stream.h"

namespace net {
	class IOBuffer;
}
namespace asar {
	class AsarEncodeStream : public net::FilterSourceStream {

	public:
		~AsarEncodeStream() override;
		// Creates a AsarEncodeStream. Return nullptr if initialization fails.
		static std::unique_ptr<AsarEncodeStream> Create(
			std::unique_ptr<SourceStream> previous,
			SourceStream::SourceType type);
	private:

		AsarEncodeStream(std::unique_ptr<SourceStream> previous,
			SourceStream::SourceType type);
		

		// SourceStream implementation
		std::string GetTypeAsString() const override;
		int FilterData(net::IOBuffer* output_buffer,
			int output_buffer_size,
			net::IOBuffer* input_buffer,
			int input_buffer_size,
			int* consumed_bytes,
			bool upstream_end_reached) override;


		DISALLOW_COPY_AND_ASSIGN(AsarEncodeStream);
	};
}  // namespace net

#endif  // NET_FILTER_ASAR_ENCODE_STREAM_
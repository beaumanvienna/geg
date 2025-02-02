#include "core.hpp"

#include <cstddef>
#include <fstream>

#define GLM_ENABLE_EXPERMENTAL ;
#include "glm/gtx/hash.hpp"

namespace Geg {

	namespace Utils {

		template<typename T, typename... Rest>
		void hashCombine(std::size_t &seed, const T &v, const Rest &...rest) {
			seed ^= std::hash<T>{}(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
			(hashCombine(seed, rest), ...);
		};

		std::string readFileAsString(const std::string &filePath) {
			std::ifstream file{filePath, std::ios::ate};

			GEG_CORE_ASSERT(file.is_open(), "can't open file" + filePath);

			size_t fileSize = static_cast<size_t>(file.tellg());
			std::vector<char> buffer(fileSize);

			file.seekg(0);
			file.read(buffer.data(), fileSize);
			file.close();

			std::string stringBuffer(buffer.begin(), buffer.end());
			return stringBuffer;
		}

		std::vector<char> readFileAsBinary(const std::string &filePath) {
			std::ifstream file{filePath, std::ios::ate | std::ios::binary};

			GEG_CORE_ASSERT(file.is_open(), "can't open file" + filePath);

			size_t fileSize = static_cast<size_t>(file.tellg());
			std::vector<char> buffer(fileSize);

			file.seekg(0);
			file.read(buffer.data(), fileSize);
			file.close();

			return buffer;
		}

	}		 // namespace Utils

}		 // namespace Geg

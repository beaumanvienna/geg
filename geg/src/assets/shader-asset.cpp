﻿#include "shader-asset.hpp"

namespace Geg {

	ShaderAsset::ShaderAsset(const ShaderSource& src) {
		vertSpv = compile(src.vert, shaderc_vertex_shader);
		fragSpv = compile(src.frag, shaderc_fragment_shader);

		setup();
	}

	std::vector<uint32_t> ShaderAsset::compile(const std::string& src, shaderc_shader_kind shader) {
		const shaderc::Compiler compiler;
		const shaderc::CompileOptions options;
		GEG_CORE_INFO("compiling shaders");
		const shaderc::SpvCompilationResult result = compiler.CompileGlslToSpv(src, shader, "geg", options);
		if (result.GetCompilationStatus() != shaderc_compilation_status_success) {
			//handle errors
			GEG_CORE_ASSERT(false, "error compiling shader");
		}
		return {result.cbegin(), result.cend()};
	}

	void ShaderAsset::setup() {
		shader = Ref<Shader>(Shader::create(vertSpv, fragSpv));
	}
} // namespace Geg

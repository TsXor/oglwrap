/** @file buffer_selection.hpp
    @brief Implements OpenGL buffer selection related stuff.
*/

#ifndef OGLWRAP_CONTEXT_BUFFER_SELECTION_HPP_
#define OGLWRAP_CONTEXT_BUFFER_SELECTION_HPP_

#include "../config.hpp"
#include "../enums.hpp"
#include "../debug/error.hpp"
#include "../define_internal_macros.hpp"


namespace oglwrap {
namespace context {

class BufferSelection {
public:
	/// Sets the destination color buffer for draw operations.
	/** @see glDrawBuffer */
	static void DrawBuffer(ColorBuffer buffer) {
		gl(DrawBuffer(buffer));
	}

	#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_DRAW_BUFFER)
	/// Returns the destination color buffer for draw operations.
	/** @see glGetIntegerv, GL_DRAW_BUFFER */
	static ColorBuffer DrawBuffer() {
		GLint data;
		gl(GetIntegerv(GL_DRAW_BUFFER, &data));
		return static_cast<ColorBuffer>(data);
	}
	#endif

	#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glDrawBuffers)
	/// Sets the destination color buffer for draw operations.
	/** @see glDrawBuffers */
	static void DrawBuffers(std::vector<ColorBuffer> buffers) {
		gl(DrawBuffers(buffers.size(), reinterpret_cast<const GLenum*>(buffers.data())));
	}
	#endif

	#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_DRAW_BUFFER)
	/// Returns the destination color buffer of the specified index for draw operations.
	/** @see glGetIntegerv, GL_DRAW_BUFFER */
	static ColorBuffer DrawBuffers(int idx) {
		GLint data;
		gl(GetIntegerv(GL_DRAW_BUFFER+idx, &data));
		return static_cast<ColorBuffer>(data);
	}
	#endif

	/// Sets the source color buffer for read operations.
	/** @see glReadBuffer */
	static void ReadBuffer(ColorBuffer buffer) {
		gl(ReadBuffer(buffer));
	}

	#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_READ_BUFFER)
	/// Returns the source color buffer for draw operations.
	/** @see glGetIntegerv, GL_DRAW_BUFFER */
	static ColorBuffer ReadBuffer() {
		GLint data;
		gl(GetIntegerv(GL_READ_BUFFER, &data));
		return static_cast<ColorBuffer>(data);
	}
	#endif
};

}
}
#include "../undefine_internal_macros.hpp"
#endif

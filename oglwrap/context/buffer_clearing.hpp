/** @file buffer_clearing.hpp
    @brief Implements OpenGL buffer clearing related stuff.
*/

#ifndef OGLWRAP_CONTEXT_BUFFER_CLEARING_HPP_
#define OGLWRAP_CONTEXT_BUFFER_CLEARING_HPP_

#include "../glm/glm/glm.hpp"

#include "../config.hpp"
#include "../enums.hpp"
#include "../debug/error.hpp"
#include "../define_internal_macros.hpp"


namespace oglwrap {
namespace context {

class BufferClearing {
public:
	/// Specify clear values for the color buffers.
	/** @see glClearColor */
	static void ClearColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a) {
		gl(ClearColor(r, g, b, a));
	}

	#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_COLOR_CLEAR_VALUE)
	/// Returns the clear values for the color buffers.
	/** @see glGetFloatv, GL_COLOR_CLEAR_VALUE */
	static glm::vec4 GetClearColor() {
		GLfloat data[4];
		gl(GetFloatv(GL_COLOR_CLEAR_VALUE, data));
		return glm::vec4(data[0], data[1], data[2], data[3]);
	}
	#endif

	/// Specify the clear value for the depth buffers.
	/** @see glClearDepth */
	static void ClearDepth(GLdouble d) {
		gl(ClearDepth(d));
	}

	#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_DEPTH_CLEAR_VALUE)
	/// Returns the clear value for the depth buffers.
	/** @see glGetDoublev, GL_DEPTH_CLEAR_VALUE */
	static double GetClearDepth() {
		GLdouble data;
		gl(GetDoublev(GL_DEPTH_CLEAR_VALUE, &data));
		return data;
	}
	#endif

	/// Specify the clear value for the stencil buffers.
	/** @see glClearStencil */
	static void ClearStencil(GLuint mask) {
		gl(ClearStencil(mask));
	}

	#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_STENCIL_CLEAR_VALUE)
	/// Returns the clear value for the stencil buffers.
	/** @see GetIntegerv, GL_STENCIL_CLEAR_VALUE */
	static GLuint GetClearStencil() {
		GLuint data;
		gl(GetIntegerv(GL_STENCIL_CLEAR_VALUE, reinterpret_cast<GLint*>(&data)));
		return data;
	}
	#endif

	/// Clears buffers in its destructor, depending on which functions were called on it.
	/** @see glClear */
	class ClearBuffers {
		GLuint buffers = 0;
	public:
		ClearBuffers& Color() {
			buffers |= GL_COLOR_BUFFER_BIT;
			return *this;
		}
		ClearBuffers& Depth() {
			buffers |= GL_DEPTH_BUFFER_BIT;
			return *this;
		}
		ClearBuffers& Stencil() {
			buffers |= GL_STENCIL_BUFFER_BIT;
			return *this;
		}
		~ClearBuffers() {
			if(buffers != 0) {
				gl(Clear(buffers));
			}
		}
	};

	/// Clears buffers specified by calling functions of the returned object.
	/** @see glClear */
	static ClearBuffers Clear() {
		return ClearBuffers();
	}
};

}
}

#include "../undefine_internal_macros.hpp"
#endif

#ifndef OGLWRAP_ENUMS_FRAMEBUFFER_STATUS_HPP_
#define OGLWRAP_ENUMS_FRAMEBUFFER_STATUS_HPP_

#include "../config.hpp"

namespace oglwrap {

inline namespace enums {

enum class FramebufferStatus : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_COMPLETE)
  Complete = GL_FRAMEBUFFER_COMPLETE,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_UNDEFINED)
  Undefined = GL_FRAMEBUFFER_UNDEFINED,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT)
  Incomplete_Attachment = GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT)
  Incomplete_MissingAttachment = GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER)
  Incomplete_DrawBuffer = GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER)
  Incomplete_ReadBuffer = GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_UNSUPPORTED)
  Unsupported = GL_FRAMEBUFFER_UNSUPPORTED,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE)
  Incomplete_Multisample = GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS)
  Incomplete_LayerTargets = GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS,
#endif
};

} // enums

} // oglwrap

#endif

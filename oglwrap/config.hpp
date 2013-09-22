/** @file config.hpp
    @brief Contains macros to configure oglwrap.
*/

#pragma once

#define BIND_CHECKED

#ifdef GL_LINE
    #define OGLWRAP_OPENGL_INCLUDED 1
#else
    #define OGLWRAP_OPENGL_INCLUDED 0
#endif

/// If true, loads only the extensions, that are available.
/** By default, it's only turned on, if a GL header is included. */
#ifndef OGLWRAP_CHECK_DEPENDENCIES
    #if OGLWRAP_OPENGL_INCLUDED // If an OpenGL header is loaded.
        #define OGLWRAP_CHECK_DEPENDENCIES 1
    #else // else all #if defined(gl*) would evaluate as false, so better just disable dependency check
        #define OGLWRAP_CHECK_DEPENDENCIES 0
    #endif
#endif

/// If true, enables error checking, and DebugOutputs.
#ifndef OGLWRAP_DEBUG
    #define OGLWRAP_DEBUG 1
#endif

/// If true, warns you if you call a function that requires binding, through an object that isn't the currently bound one.
#if OGLWRAP_DEBUG
    #ifndef OGLWRAP_BINDCHECK
        #define OGLWRAP_BINDCHECK 1
    #endif
#endif

/// If set to true, disable the oglwrap debug output.
/** Setting OGLWRAP_DEBUG flag to true will override this flag, and will turn the debug output off */
#ifndef OGLWRAP_DISABLE_DEBUG_OUTPUT
    #define OGLWRAP_DISABLE_DEBUG_OUTPUT 0
#endif

/// If true, uses Magick++ API to load images.
#ifndef OGLWRAP_IMAGEMAGICK
    #define OGLWRAP_IMAGEMAGICK 1
#endif

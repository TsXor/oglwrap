/** @file capabilities.hpp
    @brief Implements OpenGL capabilities related stuff.
*/

#ifndef OGLWRAP_CONTEXT_CAPABILITIES_HPP_
#define OGLWRAP_CONTEXT_CAPABILITIES_HPP_

#include "../glm/glm/glm.hpp"

#include "../config.hpp"
#include "../enums.hpp"
#include "../debug/error.hpp"
#include "../define_internal_macros.hpp"


namespace oglwrap {
namespace context {

class Capabilities {
public:
	/// Enables a capability.
	/** @see glEnable */
	static void Enable(Capability capability) {
		gl(Enable(capability));
	}

	/// Enables a capability.
	/** @see glEnable */
	void operator()(Capability capability) const {
		Enable(capability);
	}

	#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glEnablei)
	/// Enables a capability for an index target.
	/** @see glEnablei */
	static void Enable(Capability capability, GLuint index) {
		gl(Enablei(capability, index));
	}

	/// Enables a capability for an index target.
	/** @see glEnablei */
	void operator()(Capability capability, GLuint index) const {
		Enable(capability, index);
	}
	#endif

	/// Disables a capability.
	/** @see glDisable */
	static void Disable(Capability capability) {
		gl(Disable(capability));
	}

	#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glDisablei)
	/// Disables a capability for an index target.
	/** @see glDisablei */
	static void Disable(Capability capability, GLuint index) {
		gl(Disablei(capability, index));
	}
	#endif

	/// Checks if a capability is enabled.
	/** @see glIsEnabled */
	static bool IsEnabled(Capability capability) {
		return gl(IsEnabled(capability));
	}

	#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glIsEnabledi)
	/// Checks if a capability is enabled for an index target.
	/** @see glIsEnabledi */
	static bool IsEnabled(Capability capability, GLuint index) {
		return gl(IsEnabledi(capability, index));
	}
	#endif

	/// Enables or disables a capability.
	/** @see glEnable, glDisable */
	static void SetCapability(Capability capability, bool value) {
		if(value) {
			Enable(capability);
		} else {
			Disable(capability);
		}
	}

	/// Enables or disables a capability.
	/** @see glEnable, glDisable */
	void operator()(Capability capability, bool value) const {
		SetCapability(capability, value);
	}

	/// Enables or disables a capability for an indexet target.
	/** @see glEnable, glDisable */
	static void SetCapability(Capability capability, GLuint index, bool value) {
		if(value) {
			Enable(capability, index);
		} else {
			Disable(capability, index);
		}
	}

	/// Enables or disables a capability for an indexet target.
	/** @see glEnable, glDisable */
	void operator()(Capability capability, GLuint index, bool value) const {
		SetCapability(capability, index, value);
	}

	/// Enables a capability, and creates a variable. When the variable goes
	/// out of the scope, sets the capability back to its old value.
	class TemporaryEnable {
		Capability cap_;
		bool was_enabled_;

	public:
		TemporaryEnable(Capability capability) : cap_(capability) {
			was_enabled_ = IsEnabled(cap_);
			if(!was_enabled_) {
				Enable(cap_);
			}
		}

		~TemporaryEnable() {
			if(!was_enabled_) {
				Disable(cap_);
			}
		}
	};

	/// Disables a capability, and creates a variable. When the variable goes
	/// out of the scope, sets the capability back to its old value.
	class TemporaryDisable {
		Capability cap_;
		bool was_enabled_;

	public:
		TemporaryDisable(Capability capability) : cap_(capability) {
			was_enabled_ = IsEnabled(cap_);
			if(was_enabled_) {
				Disable(cap_);
			}
		}

		~TemporaryDisable() {
			if(was_enabled_) {
				Enable(cap_);
			}
		}
	};

	/// Temporary sets a list of Capabilities to the specified value.
	/// When the created variable goes out of scope, these variables are set back
	/// to their old values.
	class TemporarySet {
		std::vector<std::pair<Capability, bool>> cap_;

	public:
		TemporarySet(std::vector<std::pair<Capability, bool>> capabilites) {
			for(auto i : capabilites) {
				bool current_state = IsEnabled(i.first);
				if(i.second != current_state) {
					cap_.push_back({i.first, i.second});
					if(current_state) {
						Disable(i.first);
					} else {
						Enable(i.first);
					}
				}
			}
		}

		~TemporarySet() {
			for(auto i : cap_) {
				if(i.second) {
					Disable(i.first);
				} else {
					Enable(i.first);
				}
			}
		}
	};
};

}
}

#include "../undefine_internal_macros.hpp"
#endif // OGLWRAP_CONTEXT_CAPABILITIES_HPP_

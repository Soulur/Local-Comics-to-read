// Platform detection using predefined macros
#ifdef _WIN32
		/* Windows x64/x86 */
		#ifdef _WIN64
			/* Windows x64  */
			#define PLATFORM_WINDOWS

		#endif
#endif
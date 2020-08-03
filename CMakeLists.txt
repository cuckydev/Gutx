cmake_minimum_required(VERSION 3.8)

###########
# Options #
###########
option(TARGET_WIN "Target Windows" OFF)

#########
# Setup #
#########

# Define project, source, and includes
project(Gutx LANGUAGES CXX)

add_executable(Gutx WIN32
	# Program
	"src/Input.cpp"
	"src/Input.h"
	"src/Main.cpp"
	"src/Window.cpp"
	"src/Window.h"
)

if(TARGET_WIN)
	# Just compile source
	target_include_directories(Gutx PRIVATE "src")
else()
	# Compile source
	target_include_directories(Gutx PRIVATE "src")
	
	# Include windows reimplementation
	target_sources(Gutx PRIVATE
		"winreimp/windows.h"
		"winreimp/windef.h"
		"winreimp/synchapi.cpp"
		"winreimp/synchapi.h"
		"winreimp/winuser.cpp"
		"winreimp/winuser.h"
		"winreimp/handleapi.cpp"
		"winreimp/handleapi.h"
		"winreimp/commctrl.cpp"
		"winreimp/commctrl.h"
		"winreimp/libloaderapi.cpp"
		"winreimp/libloaderapi.h"
		"winreimp/shlwapi.cpp"
		"winreimp/shlwapi.h"
		"winreimp/fileapi.cpp"
		"winreimp/fileapi.h"
		"winreimp/wingdi.cpp"
		"winreimp/wingdi.h"
	)
	target_include_directories(Gutx PRIVATE "winreimp")
endif()

set_target_properties(Gutx PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin"
	CXX_EXTENSIONS OFF
)

###########
# Targets #
###########
if(TARGET_WIN)
	# Target windows
	target_compile_definitions(Gutx PRIVATE TARGET_WIN)
else()
	# Link SDL2
	find_package(SDL2)
	target_link_libraries(Gutx PRIVATE SDL2::SDL2)
	
	# Set flags
	target_compile_definitions(Gutx PRIVATE REIMP_WINMAIN)
	target_compile_definitions(Gutx PRIVATE FORWARD_SLASH)
	target_compile_definitions(Gutx PRIVATE _WIN64)
	target_compile_definitions(Gutx PRIVATE SAFE_READ)
	target_sources(Gutx PRIVATE "src/SafeRead.cpp" "src/SafeRead.h")
endif()

##########
# Tweaks #
##########
# This is messy as hell, and has been replaced by CMAKE_MSVC_RUNTIME_LIBRARY,
# but that's a very recent CMake addition, so we're still doing it this way for now
if(MSVC AND MSVC_LINK_STATIC_RUNTIME)
	# Statically-link the CRT (vcpkg static libs do this)
	foreach(flag_var CMAKE_C_FLAGS CMAKE_C_FLAGS_DEBUG CMAKE_C_FLAGS_RELEASE CMAKE_C_FLAGS_MINSIZEREL CMAKE_C_FLAGS_RELWITHDEBINFO CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO)
		if(${flag_var} MATCHES "/MD")
			string(REGEX REPLACE "/MD" "/MT" ${flag_var} "${${flag_var}}")
		endif()
	endforeach()
endif()

# Do some other MSVC fixes
if(MSVC)
	# Disable warnings that normally fire up on MSVC when using "unsafe" functions instead of using MSVC's "safe" _s functions
	target_compile_definitions(Gutx PRIVATE _CRT_SECURE_NO_WARNINGS)
	
	# Make it so source files are recognized as UTF-8 by MSVC
	target_compile_options(Gutx PRIVATE "/utf-8")
endif()

# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = "C:/Program Files/CMake/bin/cmake.exe"

# The command to remove a file.
RM = "C:/Program Files/CMake/bin/cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:/code/ray_tracer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:/code/ray_tracer

# Include any dependencies generated for this target.
include CMakeFiles/RayTracer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/RayTracer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RayTracer.dir/flags.make

CMakeFiles/RayTracer.dir/main.cpp.obj: CMakeFiles/RayTracer.dir/flags.make
CMakeFiles/RayTracer.dir/main.cpp.obj: CMakeFiles/RayTracer.dir/includes_CXX.rsp
CMakeFiles/RayTracer.dir/main.cpp.obj: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:/code/ray_tracer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/RayTracer.dir/main.cpp.obj"
	C:/MinGW/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RayTracer.dir/main.cpp.obj -c D:/code/ray_tracer/main.cpp

CMakeFiles/RayTracer.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RayTracer.dir/main.cpp.i"
	C:/MinGW/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:/code/ray_tracer/main.cpp > CMakeFiles/RayTracer.dir/main.cpp.i

CMakeFiles/RayTracer.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RayTracer.dir/main.cpp.s"
	C:/MinGW/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:/code/ray_tracer/main.cpp -o CMakeFiles/RayTracer.dir/main.cpp.s

CMakeFiles/RayTracer.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/RayTracer.dir/main.cpp.obj.requires

CMakeFiles/RayTracer.dir/main.cpp.obj.provides: CMakeFiles/RayTracer.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles/RayTracer.dir/build.make CMakeFiles/RayTracer.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/RayTracer.dir/main.cpp.obj.provides

CMakeFiles/RayTracer.dir/main.cpp.obj.provides.build: CMakeFiles/RayTracer.dir/main.cpp.obj


# Object files for target RayTracer
RayTracer_OBJECTS = \
"CMakeFiles/RayTracer.dir/main.cpp.obj"

# External object files for target RayTracer
RayTracer_EXTERNAL_OBJECTS =

RayTracer.exe: CMakeFiles/RayTracer.dir/main.cpp.obj
RayTracer.exe: CMakeFiles/RayTracer.dir/build.make
RayTracer.exe: CMakeFiles/RayTracer.dir/linklibs.rsp
RayTracer.exe: CMakeFiles/RayTracer.dir/objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:/code/ray_tracer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable RayTracer.exe"
	"C:/Program Files/CMake/bin/cmake.exe" -E remove -f CMakeFiles/RayTracer.dir/objects.a
	C:/MinGW/bin/ar.exe cr CMakeFiles/RayTracer.dir/objects.a @CMakeFiles/RayTracer.dir/objects1.rsp
	C:/MinGW/bin/c++.exe    -Wl,--whole-archive CMakeFiles/RayTracer.dir/objects.a -Wl,--no-whole-archive  -o RayTracer.exe -Wl,--out-implib,libRayTracer.dll.a -Wl,--major-image-version,0,--minor-image-version,0 @CMakeFiles/RayTracer.dir/linklibs.rsp

# Rule to build all files generated by this target.
CMakeFiles/RayTracer.dir/build: RayTracer.exe

.PHONY : CMakeFiles/RayTracer.dir/build

CMakeFiles/RayTracer.dir/requires: CMakeFiles/RayTracer.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/RayTracer.dir/requires

CMakeFiles/RayTracer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/RayTracer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/RayTracer.dir/clean

CMakeFiles/RayTracer.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" D:/code/ray_tracer D:/code/ray_tracer D:/code/ray_tracer D:/code/ray_tracer D:/code/ray_tracer/CMakeFiles/RayTracer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/RayTracer.dir/depend

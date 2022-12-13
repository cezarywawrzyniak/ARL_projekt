# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /work/tello_ros_ws/src/tello_ros/tello_description

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /work/tello_ros_ws/src/build/tello_description

# Utility rule file for generate_urdf_1.

# Include the progress variables for this target.
include CMakeFiles/generate_urdf_1.dir/progress.make

CMakeFiles/generate_urdf_1: urdf/tello_1.urdf


urdf/tello_1.urdf: /work/tello_ros_ws/src/tello_ros/tello_description/urdf/tello.xml
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/work/tello_ros_ws/src/build/tello_description/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generate /work/tello_ros_ws/src/build/tello_description/urdf/tello_1.urdf"
	/usr/bin/python3 /work/tello_ros_ws/src/tello_ros/tello_description/src/replace.py /work/tello_ros_ws/src/tello_ros/tello_description/urdf/tello.xml suffix=_1 topic_ns=drone1 > /work/tello_ros_ws/src/build/tello_description/urdf/tello_1.urdf

generate_urdf_1: CMakeFiles/generate_urdf_1
generate_urdf_1: urdf/tello_1.urdf
generate_urdf_1: CMakeFiles/generate_urdf_1.dir/build.make

.PHONY : generate_urdf_1

# Rule to build all files generated by this target.
CMakeFiles/generate_urdf_1.dir/build: generate_urdf_1

.PHONY : CMakeFiles/generate_urdf_1.dir/build

CMakeFiles/generate_urdf_1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/generate_urdf_1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/generate_urdf_1.dir/clean

CMakeFiles/generate_urdf_1.dir/depend:
	cd /work/tello_ros_ws/src/build/tello_description && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /work/tello_ros_ws/src/tello_ros/tello_description /work/tello_ros_ws/src/tello_ros/tello_description /work/tello_ros_ws/src/build/tello_description /work/tello_ros_ws/src/build/tello_description /work/tello_ros_ws/src/build/tello_description/CMakeFiles/generate_urdf_1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/generate_urdf_1.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/issiki/gsoc/colab-gsoc2019-Jeevan_Kumar/DetectionSuit/DeepLearningSuite

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/issiki/gsoc/colab-gsoc2019-Jeevan_Kumar/DetectionSuit/DeepLearningSuite/build

# Include any dependencies generated for this target.
include Tools/Splitter/CMakeFiles/splitter.dir/depend.make

# Include the progress variables for this target.
include Tools/Splitter/CMakeFiles/splitter.dir/progress.make

# Include the compile flags for this target's objects.
include Tools/Splitter/CMakeFiles/splitter.dir/flags.make

Tools/Splitter/CMakeFiles/splitter.dir/splitter.cpp.o: Tools/Splitter/CMakeFiles/splitter.dir/flags.make
Tools/Splitter/CMakeFiles/splitter.dir/splitter.cpp.o: ../Tools/Splitter/splitter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/issiki/gsoc/colab-gsoc2019-Jeevan_Kumar/DetectionSuit/DeepLearningSuite/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Tools/Splitter/CMakeFiles/splitter.dir/splitter.cpp.o"
	cd /home/issiki/gsoc/colab-gsoc2019-Jeevan_Kumar/DetectionSuit/DeepLearningSuite/build/Tools/Splitter && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/splitter.dir/splitter.cpp.o -c /home/issiki/gsoc/colab-gsoc2019-Jeevan_Kumar/DetectionSuit/DeepLearningSuite/Tools/Splitter/splitter.cpp

Tools/Splitter/CMakeFiles/splitter.dir/splitter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/splitter.dir/splitter.cpp.i"
	cd /home/issiki/gsoc/colab-gsoc2019-Jeevan_Kumar/DetectionSuit/DeepLearningSuite/build/Tools/Splitter && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/issiki/gsoc/colab-gsoc2019-Jeevan_Kumar/DetectionSuit/DeepLearningSuite/Tools/Splitter/splitter.cpp > CMakeFiles/splitter.dir/splitter.cpp.i

Tools/Splitter/CMakeFiles/splitter.dir/splitter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/splitter.dir/splitter.cpp.s"
	cd /home/issiki/gsoc/colab-gsoc2019-Jeevan_Kumar/DetectionSuit/DeepLearningSuite/build/Tools/Splitter && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/issiki/gsoc/colab-gsoc2019-Jeevan_Kumar/DetectionSuit/DeepLearningSuite/Tools/Splitter/splitter.cpp -o CMakeFiles/splitter.dir/splitter.cpp.s

# Object files for target splitter
splitter_OBJECTS = \
"CMakeFiles/splitter.dir/splitter.cpp.o"

# External object files for target splitter
splitter_EXTERNAL_OBJECTS =

Tools/Splitter/splitter: Tools/Splitter/CMakeFiles/splitter.dir/splitter.cpp.o
Tools/Splitter/splitter: Tools/Splitter/CMakeFiles/splitter.dir/build.make
Tools/Splitter/splitter: DeepLearningSuiteLib/libDeepLearningSuite.so
Tools/Splitter/splitter: /usr/lib/x86_64-linux-gnu/libboost_program_options.so
Tools/Splitter/splitter: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
Tools/Splitter/splitter: /usr/lib/x86_64-linux-gnu/libboost_system.so
Tools/Splitter/splitter: /usr/lib/x86_64-linux-gnu/libQt5Svg.so.5.5.1
Tools/Splitter/splitter: /usr/lib/x86_64-linux-gnu/libQt5OpenGL.so.5.5.1
Tools/Splitter/splitter: /usr/lib/x86_64-linux-gnu/libglog.so
Tools/Splitter/splitter: /usr/lib/x86_64-linux-gnu/c++11/libIce.so
Tools/Splitter/splitter: /usr/lib/x86_64-linux-gnu/c++11/libIceBox.so
Tools/Splitter/splitter: /usr/lib/x86_64-linux-gnu/c++11/libIceGrid.so
Tools/Splitter/splitter: /usr/lib/x86_64-linux-gnu/c++11/libIcePatch2.so
Tools/Splitter/splitter: /usr/lib/x86_64-linux-gnu/c++11/libIceSSL.so
Tools/Splitter/splitter: /usr/lib/x86_64-linux-gnu/c++11/libIceStorm.so
Tools/Splitter/splitter: /usr/lib/x86_64-linux-gnu/c++11/libIceUtil.so
Tools/Splitter/splitter: /usr/lib/x86_64-linux-gnu/libpython2.7.so
Tools/Splitter/splitter: libs/depthLib/libdepthLib.a
Tools/Splitter/splitter: libs/interfaces/libJderobotInterfaces.so
Tools/Splitter/splitter: devel/lib/libcomm.so
Tools/Splitter/splitter: /usr/lib/x86_64-linux-gnu/c++11/libIce.so
Tools/Splitter/splitter: /usr/lib/x86_64-linux-gnu/c++11/libIceBox.so
Tools/Splitter/splitter: /usr/lib/x86_64-linux-gnu/c++11/libIceGrid.so
Tools/Splitter/splitter: /usr/lib/x86_64-linux-gnu/c++11/libIcePatch2.so
Tools/Splitter/splitter: /usr/lib/x86_64-linux-gnu/c++11/libIceSSL.so
Tools/Splitter/splitter: /usr/lib/x86_64-linux-gnu/c++11/libIceStorm.so
Tools/Splitter/splitter: /usr/lib/x86_64-linux-gnu/c++11/libIceUtil.so
Tools/Splitter/splitter: /opt/ros/kinetic/lib/libroscpp.so
Tools/Splitter/splitter: /usr/lib/x86_64-linux-gnu/libboost_signals.so
Tools/Splitter/splitter: /opt/ros/kinetic/lib/librosconsole.so
Tools/Splitter/splitter: /opt/ros/kinetic/lib/librosconsole_log4cxx.so
Tools/Splitter/splitter: /opt/ros/kinetic/lib/librosconsole_backend_interface.so
Tools/Splitter/splitter: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
Tools/Splitter/splitter: /usr/lib/x86_64-linux-gnu/libboost_regex.so
Tools/Splitter/splitter: /opt/ros/kinetic/lib/libroscpp_serialization.so
Tools/Splitter/splitter: /opt/ros/kinetic/lib/libxmlrpcpp.so
Tools/Splitter/splitter: /opt/ros/kinetic/lib/librostime.so
Tools/Splitter/splitter: /opt/ros/kinetic/lib/libcpp_common.so
Tools/Splitter/splitter: /usr/lib/x86_64-linux-gnu/libboost_thread.so
Tools/Splitter/splitter: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
Tools/Splitter/splitter: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
Tools/Splitter/splitter: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
Tools/Splitter/splitter: /usr/lib/x86_64-linux-gnu/libpthread.so
Tools/Splitter/splitter: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so
Tools/Splitter/splitter: /opt/ros/kinetic/lib/libcv_bridge.so
Tools/Splitter/splitter: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_core3.so.3.3.1
Tools/Splitter/splitter: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_imgproc3.so.3.3.1
Tools/Splitter/splitter: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_imgcodecs3.so.3.3.1
Tools/Splitter/splitter: /opt/ros/kinetic/lib/libimage_transport.so
Tools/Splitter/splitter: /opt/ros/kinetic/lib/libmessage_filters.so
Tools/Splitter/splitter: /usr/lib/x86_64-linux-gnu/libtinyxml2.so
Tools/Splitter/splitter: /opt/ros/kinetic/lib/libclass_loader.so
Tools/Splitter/splitter: /usr/lib/libPocoFoundation.so
Tools/Splitter/splitter: /usr/lib/x86_64-linux-gnu/libdl.so
Tools/Splitter/splitter: /opt/ros/kinetic/lib/libroslib.so
Tools/Splitter/splitter: /opt/ros/kinetic/lib/librospack.so
Tools/Splitter/splitter: /usr/lib/x86_64-linux-gnu/libtinyxml.so
Tools/Splitter/splitter: /opt/ros/kinetic/lib/libroscpp.so
Tools/Splitter/splitter: /usr/lib/x86_64-linux-gnu/libboost_signals.so
Tools/Splitter/splitter: /opt/ros/kinetic/lib/librosconsole.so
Tools/Splitter/splitter: /opt/ros/kinetic/lib/librosconsole_log4cxx.so
Tools/Splitter/splitter: /opt/ros/kinetic/lib/librosconsole_backend_interface.so
Tools/Splitter/splitter: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
Tools/Splitter/splitter: /usr/lib/x86_64-linux-gnu/libboost_regex.so
Tools/Splitter/splitter: /opt/ros/kinetic/lib/libroscpp_serialization.so
Tools/Splitter/splitter: /opt/ros/kinetic/lib/libxmlrpcpp.so
Tools/Splitter/splitter: /opt/ros/kinetic/lib/librostime.so
Tools/Splitter/splitter: /opt/ros/kinetic/lib/libcpp_common.so
Tools/Splitter/splitter: /usr/lib/x86_64-linux-gnu/libboost_thread.so
Tools/Splitter/splitter: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
Tools/Splitter/splitter: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
Tools/Splitter/splitter: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
Tools/Splitter/splitter: /usr/lib/x86_64-linux-gnu/libpthread.so
Tools/Splitter/splitter: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so
Tools/Splitter/splitter: /opt/ros/kinetic/lib/libcv_bridge.so
Tools/Splitter/splitter: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_core3.so.3.3.1
Tools/Splitter/splitter: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_imgproc3.so.3.3.1
Tools/Splitter/splitter: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_imgcodecs3.so.3.3.1
Tools/Splitter/splitter: /opt/ros/kinetic/lib/libimage_transport.so
Tools/Splitter/splitter: /opt/ros/kinetic/lib/libmessage_filters.so
Tools/Splitter/splitter: /usr/lib/x86_64-linux-gnu/libtinyxml2.so
Tools/Splitter/splitter: /opt/ros/kinetic/lib/libclass_loader.so
Tools/Splitter/splitter: /usr/lib/libPocoFoundation.so
Tools/Splitter/splitter: /usr/lib/x86_64-linux-gnu/libdl.so
Tools/Splitter/splitter: /opt/ros/kinetic/lib/libroslib.so
Tools/Splitter/splitter: /opt/ros/kinetic/lib/librospack.so
Tools/Splitter/splitter: /usr/lib/x86_64-linux-gnu/libtinyxml.so
Tools/Splitter/splitter: /usr/lib/x86_64-linux-gnu/libboost_program_options.so
Tools/Splitter/splitter: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
Tools/Splitter/splitter: /usr/lib/x86_64-linux-gnu/libpython2.7.so
Tools/Splitter/splitter: /usr/lib/x86_64-linux-gnu/libboost_system.so
Tools/Splitter/splitter: libs/utils/libDetectionSuiteUtils.so
Tools/Splitter/splitter: libs/utils/libcolorspacesmm.so
Tools/Splitter/splitter: libs/utils/libcolorspaces.a
Tools/Splitter/splitter: libs/utils/libcolorspacesshare.so
Tools/Splitter/splitter: /usr/local/lib/libopencv_dnn.so.3.4.6
Tools/Splitter/splitter: /usr/local/lib/libopencv_ml.so.3.4.6
Tools/Splitter/splitter: /usr/local/lib/libopencv_objdetect.so.3.4.6
Tools/Splitter/splitter: /usr/local/lib/libopencv_shape.so.3.4.6
Tools/Splitter/splitter: /usr/local/lib/libopencv_stitching.so.3.4.6
Tools/Splitter/splitter: /usr/local/lib/libopencv_superres.so.3.4.6
Tools/Splitter/splitter: /usr/local/lib/libopencv_videostab.so.3.4.6
Tools/Splitter/splitter: /usr/local/lib/libopencv_calib3d.so.3.4.6
Tools/Splitter/splitter: /usr/local/lib/libopencv_features2d.so.3.4.6
Tools/Splitter/splitter: /usr/local/lib/libopencv_flann.so.3.4.6
Tools/Splitter/splitter: /usr/local/lib/libopencv_highgui.so.3.4.6
Tools/Splitter/splitter: /usr/local/lib/libopencv_photo.so.3.4.6
Tools/Splitter/splitter: /usr/local/lib/libopencv_video.so.3.4.6
Tools/Splitter/splitter: /usr/local/lib/libopencv_videoio.so.3.4.6
Tools/Splitter/splitter: /usr/local/lib/libopencv_imgcodecs.so.3.4.6
Tools/Splitter/splitter: /usr/local/lib/libopencv_imgproc.so.3.4.6
Tools/Splitter/splitter: /usr/local/lib/libopencv_viz.so.3.4.6
Tools/Splitter/splitter: /usr/local/lib/libopencv_core.so.3.4.6
Tools/Splitter/splitter: libs/config/libconfig.so
Tools/Splitter/splitter: /usr/lib/x86_64-linux-gnu/libglog.so
Tools/Splitter/splitter: /usr/lib/x86_64-linux-gnu/libyaml-cpp.so.0.5.2
Tools/Splitter/splitter: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.5.1
Tools/Splitter/splitter: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.5.1
Tools/Splitter/splitter: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.5.1
Tools/Splitter/splitter: Tools/Splitter/CMakeFiles/splitter.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/issiki/gsoc/colab-gsoc2019-Jeevan_Kumar/DetectionSuit/DeepLearningSuite/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable splitter"
	cd /home/issiki/gsoc/colab-gsoc2019-Jeevan_Kumar/DetectionSuit/DeepLearningSuite/build/Tools/Splitter && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/splitter.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Tools/Splitter/CMakeFiles/splitter.dir/build: Tools/Splitter/splitter

.PHONY : Tools/Splitter/CMakeFiles/splitter.dir/build

Tools/Splitter/CMakeFiles/splitter.dir/clean:
	cd /home/issiki/gsoc/colab-gsoc2019-Jeevan_Kumar/DetectionSuit/DeepLearningSuite/build/Tools/Splitter && $(CMAKE_COMMAND) -P CMakeFiles/splitter.dir/cmake_clean.cmake
.PHONY : Tools/Splitter/CMakeFiles/splitter.dir/clean

Tools/Splitter/CMakeFiles/splitter.dir/depend:
	cd /home/issiki/gsoc/colab-gsoc2019-Jeevan_Kumar/DetectionSuit/DeepLearningSuite/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/issiki/gsoc/colab-gsoc2019-Jeevan_Kumar/DetectionSuit/DeepLearningSuite /home/issiki/gsoc/colab-gsoc2019-Jeevan_Kumar/DetectionSuit/DeepLearningSuite/Tools/Splitter /home/issiki/gsoc/colab-gsoc2019-Jeevan_Kumar/DetectionSuit/DeepLearningSuite/build /home/issiki/gsoc/colab-gsoc2019-Jeevan_Kumar/DetectionSuit/DeepLearningSuite/build/Tools/Splitter /home/issiki/gsoc/colab-gsoc2019-Jeevan_Kumar/DetectionSuit/DeepLearningSuite/build/Tools/Splitter/CMakeFiles/splitter.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Tools/Splitter/CMakeFiles/splitter.dir/depend


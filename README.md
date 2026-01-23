# vsgPlugin

vsgPlugin is a plugin extension for the VulkanSceneGraph (VSG) ecosystem. It provides modular functionality that can be integrated into VSG-based applications. VulkanSceneGraph (VSG) is a modern, cross-platform C++ scene graph built on Vulkan.

## Features

- Modular plugin structure for VSG applications
- Integration with the VulkanSceneGraph framework
- Example applications demonstrating plugin usage
- CMake-based build system

## Requirements

To build and use vsgPlugin, you need:

- A C++17-compatible compiler
- Vulkan SDK
- VulkanSceneGraph (VSG)
- CMake 3.14 or newer

## Building

Clone the repository:

    git clone https://github.com/rhabacker/vsgPlugin.git
    cd vsgPlugin

Create a build directory and compile:

    mkdir build
    cd build
    cmake .. -DVSG_DIR=/path/to/vsg/lib/cmake/vsg
    cmake --build .

Adjust VSG_DIR to point to your VulkanSceneGraph installation if it is not found automatically.

## Examples

Example applications are located in the examples/ directory. They demonstrate how to load and use the plugin in a VSG application.

## Usage

After building, link vsgPlugin to your VSG application using CMake:

    find_package(vsgPlugin REQUIRED)
    target_link_libraries(MyApp PRIVATE vsgPlugin)

Include and use the plugin in your source code:

    #include <vsg/plugin/YourPlugin.hpp>

## Project Structure

    .
    ├── CMakeLists.txt
    ├── include/
    │   └── vsg/
    │       └── plugin/
    ├── src/
    ├── examples/
    └── LICENSES/

## License

This project is licensed under the MIT License. See the LICENSES directory for details.

## Contributing

Contributions are welcome. Please use the standard GitHub workflow: fork the repository, create a feature branch, commit your changes, and open a pull request.

## Contact

For questions, bug reports, or feature requests, please open an issue on GitHub.

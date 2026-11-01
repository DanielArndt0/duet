# Duet

A lightweight, header-only pair implementation for C++11 and later.

Duet stores two values, possibly of different types, and provides accessors, setters, and copy and move operations.

## Requirements

- C++11 or later
- CMake 3.16 or later for CMake integration

## Usage

Download `include/Duet.h` and add its directory to your project's include path.

```cpp
#include "Duet.h"

int main()
{
    Duet<int, int> position(10, 20);

    position.setFirst(15);

    return position.getFirst() == 15 && position.getSecond() == 20 ? 0 : 1;
}
```

For more examples and API documentation, see [Usage Documentation](docs/usage.md).

## Manual Integration

Download [Duet.h](https://github.com/DanielArndt0/Duet/blob/main/include/Duet.h) from the repository and add it to your project's include directory.

Include the header using `#include "Duet.h"`. No additional dependencies or separate compilation are required.

## CMake Integration

Duet can be integrated directly from GitHub using CMake's `FetchContent` module.

Add the following to your project's `CMakeLists.txt`:

```cmake
include(FetchContent)

FetchContent_Declare(
    Duet
    GIT_REPOSITORY https://github.com/DanielArndt0/Duet.git
    GIT_TAG 1.0.0
)

FetchContent_MakeAvailable(Duet)

target_link_libraries(my_target PRIVATE Duet::Duet)
```

Replace `my_target` with your application's CMake target.

If you already have the Duet source directory inside your CMake project, you can add it instead:

```cmake
add_subdirectory(path/to/Duet)
target_link_libraries(my_target PRIVATE Duet::Duet)
```

Duet is header-only and does not require a separately compiled binary.

## Compatibility

Duet requires C++11 or later and uses standard C++ move utilities. No external libraries are required.

## Disclaimer

Duet is a lightweight C++ library developed for educational purposes, focusing on value storage and copy and move semantics.

It is intended for learning and experimentation and is not designed to replace `std::pair` or other standard C++ utilities.

# Duet Usage

`Duet<T1, T2>` stores two values. `T1` and `T2` may be different types.

Include `Duet.h` and compile with C++11 or later.

## Create a Duet

```cpp
#include "Duet.h"
#include <string>

Duet<int, std::string> item(10, "ten");

// Default construction initializes both values.
Duet<int, int> empty;
```

The default constructor requires both types to be default-constructible.

## Read Values

```cpp
int first = item.getFirst();
std::string second = item.getSecond();

// Read-only objects support the same accessors.
const Duet<int, std::string>& readOnly = item;
int value = readOnly.getFirst();
```

`getFirst()` and `getSecond()` return references to their values. Non-const objects allow modification through those references.

## Change Values

```cpp
item.setFirst(20);
item.setSecond("twenty");
item.setDuet(30, "thirty");

// Non-const accessors also allow direct changes.
item.getFirst() = 40;
```

## Create Through the Factory Method

```cpp
Duet<int, std::string> created =
    Duet<int, std::string>::CreateDuet(50, "fifty");
```

## Copy and Move

```cpp
#include <utility>

Duet<int, std::string> copied(item);
Duet<int, std::string> assigned;
assigned = item;

Duet<int, std::string> moved(std::move(copied));
Duet<int, std::string> moveAssigned;
moveAssigned = std::move(moved);
```

Copies require copyable value types. Moves use the move operations of the stored types; the moved-from object's state depends on those types.

## Move-Only Values

```cpp
#include <memory>
#include <utility>

Duet<int, std::unique_ptr<int>> owned(1, std::unique_ptr<int>(new int(42)));
Duet<int, std::unique_ptr<int>> transferred(std::move(owned));
```

`Duet` does not allocate storage of its own. Its behavior follows the construction, assignment, and destruction rules of the two stored types.

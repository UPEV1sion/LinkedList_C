# LinkedList implementation in C

A very performant, fairly lightweight `LinkedList` implementation in C.

> [!NOTE]
> This `LinkedList` implementation relies on a "Doubly Linked List" design.

This document provides an overview and detailed description of the functions available in this `LinkedList` implementation.

## Overview

This `LinkedList` implementation provides a flexible hash map with functions to create, manipulate, and destroy linked lists. It supports both stack and queue behavior.

## Typedefs
```c
typedef struct LinkedList *LinkedList;
```

## Function Overview
```c
LinkedList ll_create(size_t value_size);
int ll_destroy(LinkedList ll);
int ll_push(LinkedList ll, const void *data);
int ll_add(LinkedList ll, const void *data);
void *ll_pop(LinkedList ll);
void *ll_poll(LinkedList ll);
void* ll_poll_last(const LinkedList ll);
void *ll_remove(LinkedList ll, size_t index);
void *ll_peek(LinkedList ll);
void *ll_peek_last(LinkedList ll);
void *ll_get(LinkedList ll, size_t index);
int ll_length(LinkedList ll);
```

## Function Reference

```c 
LinkedList ll_create(size_t value_size);
```

**Description**: Creates a new `LinkedList`.

- **Parameters**:
  - `value_size`: The size of the value.
  
- **Returns**: A new `LinkedList`.

---

```c 
int ll_destroy(LinkedList ll);
```

**Description**: Destroys the `LinkedList`.

- **Parameters**:
  - `ll`: The `LinkedList` to be destroyed.
  
- **Returns**: A success code.

---

```c 
int ll_push(LinkedList ll, const void *data);
```

**Description**: Pushes the value on the `LinkedList` (treated as a `Stack`).

- **Parameters**:
  - `ll`: The `LinkedList`.
  - `data`: The value to be added.
  
- **Returns**: A success code.

---

```c 
int ll_add(LinkedList ll, const void *data);
```

**Description**: Adds the value to the `LinkedList` (treated as a `Queue`).

- **Parameters**:
  - `ll`: The `LinkedList`.
  - `data`: The value to be added.
  
- **Returns**: A success code.

---

```c 
void *ll_pop(LinkedList ll);
```

**Description**: Pops the first value from the `LinkedList` (treated as a `Stack`). Asserts that the `LinkedList` is not empty.

- **Parameters**:
  - `ll`: The `LinkedList`.
  
- **Returns**: The popped value.

---

```c 
void *ll_poll(LinkedList ll);
```

**Description**: Polls the first value from the `LinkedList` (treated as a `Queue`). Returns `NULL` if `LinkedList` is empty.

- **Parameters**:
  - `ll`: The `LinkedList`.
  
- **Returns**: The polled value.

---

```c 
void *ll_poll_last(LinkedList ll);
```

**Description**: Polls the last value from the `LinkedList`. Returns `NULL` if `LinkedList` is empty.

- **Parameters**:
  - `ll`: The `LinkedList`.
  
- **Returns**: The polled value.

---

```c 
void *ll_remove(LinkedList ll, size_t index);
```

**Description**: Removes the item from the `LinkedList` at the specified index.

- **Parameters**:
  - `ll`: The `LinkedList`.
  - `index`: The index of the item to remove.
  
- **Returns**: The removed value.

---

```c 
void *ll_peek(LinkedList ll);
```

**Description**: Returns the first item on the `LinkedList` (treated as a `Stack`).

- **Parameters**:
  - `ll`: The `LinkedList`.
  
- **Returns**: The first value.

---

```c 
void *ll_peek_last(LinkedList ll);
```

**Description**: Returns the last item on the `LinkedList` (treated as a `Stack`).

- **Parameters**:
  - `ll`: The `LinkedList`.
  
- **Returns**: The last value.


---

```c 
void *ll_get(LinkedList ll, size_t index);
```

**Description**: Gets the item specified at the index in the `LinkedList`.

- **Parameters**:
  - `ll`: The `LinkedList`.
  
- **Returns**: The specified value.

---

```c 
int ll_length(LinkedList ll);
```

**Description**: Returns the length of the `LinkedList`.

- **Parameters**:
  - `ll`: The `LinkedList`.
  
- **Returns**: The specified value.

---


## Error Codes

- `0`: Success.
- Non-zero values indicate errors.

---

## Example

Here is a basic example demonstrating how to use the `LinkedList` functions:

```c
#include "linkedlist.h"

int main()
{
	// Create a LinkedList
	LinkedList ll = ll_create(sizeof(int));
	
	// Push a item onto the LinkedList
	int value = 15;
	ll_push(ll, &value);
	
	// Retrieve the value
	int *retrieved_value = ll_pop(ll);

	// Destroy the LinkedList
	ll_destroy(ll);
	
	return 0;
}
```











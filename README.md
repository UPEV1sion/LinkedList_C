# LinkedList implementation in C

A very performant, fairly lightweight `LinkedList` implementation in C.

> [!NOTE]
> This `LinkedList` implementation relies on a "doubly linked list" design.

This document provides an overview and detailed description of the functions available in this `LinkedList` implementatio

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

**Description**: Pushes a new value on the `Stack`.

- **Parameters**:
  - `ll`: The `LinkedList`.
  - `data`: The value to be added.
  
- **Returns**: A success code.

---

```c 
int ll_add(LinkedList ll, const void *data);
```

**Description**: Adds a new value to the `LinkedList`.

- **Parameters**:
  - `ll`: The `LinkedList`.
  - `data`: The value to be added.
  
- **Returns**: A success code.

---

```c 
void *ll_pop(LinkedList ll);
```

**Description**: Pops the first value from the `Stack`. Asserts that the `Stack` is not empty.

- **Parameters**:
  - `ll`: The `LinkedList`.
  
- **Returns**: The popped value.

---

```c 
void *ll_poll(LinkedList ll);
```

**Description**: Poll the first value from the `Stack`. If the `Stack` is empty NULL is returned.

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
  
- **Returns**: The removed value.

---

```c 
void *ll_peek(LinkedList ll);
```

**Description**: Returns the first item on the `Stack`.

- **Parameters**:
  - `ll`: The `LinkedList`.
  
- **Returns**: The first value.

---

```c 
void *ll_peek_last(LinkedList ll);
```

**Description**: Returns the last item on the `Stack`.

- **Parameters**:
  - `ll`: The `LinkedList`.
  
- **Returns**: The last value.


---

```c 
void *ll_get(LinkedList ll, size_t index);
```

**Description**: Gets the item specified at the index.

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

```c 
int ll_destroy(LinkedList ll);
```

**Description**: Destroys the `LinkedList`.

- **Parameters**:
  - `ll`: The `LinkedList`.
  
- **Returns**: A success code.
  
---

## Error Codes

- `0`: Success.
- Non-zero values indicate errors.

---












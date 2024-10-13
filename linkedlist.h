//
// Created by Emanuel on 07.09.2024.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdbool.h>
#include <stddef.h>

typedef struct LinkedList *LinkedList;

/**
 * @brief Creates a new LinkedList.
 *
 * @param value_size The sizeof value of the value
 * @return LinkedList
 */
LinkedList ll_create(size_t value_size);

/**
 * @brief Pushes a new value on the Stack.
 *
 * @param ll The LinkedList
 * @param data The data to be pushed
 * @return Success code
 */
int ll_push(LinkedList ll, const void *data);

/**
 * @brief Adds a new value to the LinkedList.
 *
 * @param ll The LinkedList
 * @param data The data to be added
 * @return Success code
 */
int ll_add(LinkedList ll, const void *data);

/**
 * @brief Offers a new value to the LinkedList.
 *
 * @param ll The LinkedList
 * @param data The data to be added
 * @return Success code
 */
int ll_offer(LinkedList ll, const void *data);

/**
 * @brief Pops the first value from the Stack. Asserts that the Stack is not empty.
 *
 * @param ll The LinkedList
 * @return The popped value
 */
void *ll_pop(LinkedList ll);

/**
 * @brief Polls the first value from the Stack. If the Stack is empty NULL is returned.
 *
 * @param ll The LinkedList
 * @return The polled value
 */
void *ll_poll(LinkedList ll);

/**
 * @brief Removes the item from the LinkedList at the specified index.
 *
 * @param ll The LinkedList
 * @param index The index from which an item should be removed
 * @return Success code
 */
int ll_remove(LinkedList ll, size_t index);

/**
 * @brief Returns the first item on the Stack.
 *
 * @param ll The LinkedList
 * @return The first value
 */
void *ll_peek(LinkedList ll);

/**
 * @brief Returns the last item on the Stack.
 *
 * @param ll The LinkedList
 * @return The last value
 */
void *ll_peek_last(LinkedList ll);

/**
 * @brief Gets the item at the index.
 *
 * @param ll The LinkedList
 * @param index index of the value
 * @return The item
 */
void *ll_get(LinkedList ll, size_t index);

/**
 * @brief Returns the length of the LinkedList.
 *
 * @param ll The LinkedList
 * @return The length
 */
int ll_length(LinkedList ll);

/**
 * @brief Checks if the LinkedList is empty.
 *
 * @param ll The LinkedList
 * @return True or falsehood
 */
bool ll_is_empty(LinkedList ll);

/**
 * @brief Checks if the LinkedList contains the item.
 *
 * @param ll The LinkedList
 * @return True or falsehood
 */
bool ll_contains(LinkedList ll, const void *data);

/**
 * @brief Destroys the LinkedList.
 *
 * @param ll The LinkedList
 * @return Success code
 */
int ll_destroy(LinkedList ll);

#endif //LINKEDLIST_H

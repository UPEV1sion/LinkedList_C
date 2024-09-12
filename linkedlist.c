#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "linkedlist.h"

//
// Created by Emanuel on 07.09.2024.
//

typedef struct Node
{
    struct Node *next;
    struct Node *prev;
    char payload[];
} Node;

struct LinkedList
{
    size_t length;
    size_t node_size;
    size_t value_size;

    Node *head;
    Node *tail;

    Node *tombstone_head;
};

static inline void push_tomb_list(const LinkedList ll, Node *node)
{
    node->next = ll->tombstone_head;
    if (ll->tombstone_head != NULL)
        ll->tombstone_head->prev = node;
    ll->tombstone_head = node;
}

static Node* create_node(const LinkedList ll, const void *payload, Node *next, Node *prev)
{
    // Benchmarking needed
    Node *node = malloc(ll->node_size);
    assert(node != NULL);
    node->next = next;
    node->prev = prev;
    memcpy(node->payload, payload, ll->value_size);
    return node;
}

LinkedList ll_create(const size_t value_size)
{
    const LinkedList ll = malloc(sizeof(*ll));
    assert(ll != NULL);
    ll->length     = 0;
    ll->node_size  = sizeof(Node) + value_size;
    ll->value_size = value_size;
    ll->head       = NULL;
    ll->tail       = NULL;
    ll->tombstone_head = NULL;

    return ll;
}

int ll_push(const LinkedList ll, const void *data)
{
    Node *node = create_node(ll, data, ll->head, NULL);
    if (ll->head != NULL)
        ll->head->prev = node;
    else
        ll->tail = node;
    ll->head = node;
    ll->length++;

    return 0;
}

int ll_add(const LinkedList ll, const void *data)
{
    Node *node = create_node(ll, data, NULL, ll->tail);
    if (ll->tail != NULL)
        ll->tail->next = node;
    else
        ll->head = node;
    ll->tail = node;
    ll->length++;
    return 0;
}

int ll_offer(const LinkedList ll, const void *data)
{
    return ll_add(ll, data);
}


void* ll_pop(const LinkedList ll)
{
    assert(ll->head != NULL);
    Node *old_head = ll->head;
    ll->head = old_head->next;
    if (ll->head != NULL)
        ll->head->prev = NULL;
    else
        ll->tail = NULL;
    push_tomb_list(ll, old_head);
    ll->length--;

    return old_head->payload;
}

void* ll_poll(const LinkedList ll)
{
    if(ll->head == NULL) return NULL;
    Node *old_head = ll->head;
    ll->head = old_head->next;
    if (ll->head != NULL)
        ll->head->prev = NULL;
    else
        ll->tail = NULL;
    push_tomb_list(ll, old_head);
    ll->length--;

    return old_head->payload;
}

void* ll_poll_last(const LinkedList ll)
{
    if(ll->tail == NULL) return NULL;
    Node *old_tail = ll->tail;
    ll->tail = old_tail->prev;
    if (ll->tail != NULL)
        ll->tail->next = NULL;
    else
        ll->head = NULL;
    push_tomb_list(ll, old_tail);
    ll->length--;

    return old_tail->payload;
}

int ll_remove(const LinkedList ll, size_t index)
{
    if (index >= ll->length) return 1;
    Node *node = ll->head;
    while (node && index--)
        node = node->next;

    if (!node) return 1;

    if (node->prev)
        node->prev->next = node->next;
    else
        ll->head = node->next;

    if (node->next)
        node->next->prev = node->prev;
    else
        ll->tail = node->prev;

    ll->length--;
    return 0;
}

void* ll_peek(const LinkedList ll)
{
    return ll->head != NULL ? ll->head->payload : NULL;
}

void *ll_peek_last(const LinkedList ll)
{
    return ll->tail != NULL ? ll->tail->payload : NULL;
}

void* ll_get(const LinkedList ll, const size_t index)
{
    if (index >= ll->length) return NULL;
    size_t counter = 0;
    for(Node *temp = ll->head; temp != NULL; temp = temp->next)
    {
        if (counter++ == index) return temp->payload;
    }

    return NULL;
}
int ll_length(const LinkedList ll)
{
    return ll->length;
}

bool ll_is_empty(LinkedList ll)
{
    return ll->length == 0;
}

bool contains(LinkedList ll, const void *data)
{
    for (Node *node = ll->head; node != NULL; node = node->next)
    {
        if(memcmp(node->payload, data, ll->value_size) == 0) return true;
    }

    return false;
}


int ll_destroy(const LinkedList ll)
{
    if (ll == NULL) return 1;

    for (Node *current = ll->head; current != NULL; )
    {
        Node *next = current->next;
        free(current);
        current = next;
    }

    for (Node *current = ll->tombstone_head; current != NULL; )
    {
        Node *next = current->next;
        free(current);
        current = next;
    }

    free(ll);
    return 0;
}

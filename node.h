/* node.h
Author: Joshua Prendergast 

Simple linked list implementation */

#ifndef NODE_H
#define NODE_H

typedef struct {
	void *data;
	struct node *next;
} node;

/* Append a new note; return the new head */
node *node_append(node *head, void *data);

/* Destroy and deallocate a linked list */
void node_destroy(node *head);

#endif
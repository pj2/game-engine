/* node.c
Author: Joshua Prendergast */

#include <stdlib.h>
#include "node.h"

node *node_append(node *head, void *data) {
	node *new;

	if (new = malloc(sizeof(node))) {
		new->data = data;
		new->next = 0;

		if (head)
			head->next = new;
		else
			head = new; /* Empty list */
	}
	return head;
}

void node_destroy(node *head) {
	node *cur, *next;
	for (cur = head; cur; cur = next) {
		next = cur->next;
		free(cur->data);
		free(cur);
	}
}
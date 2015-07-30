#include "linkedlist.h"

static inline int check_head(head_t* head)
{
	int error = 1;
	if( !head )
	{
		error = 0;
	}
	return error;
}

node_t*
create_list(int id)
{
	head_t* head = (node_t*) malloc( sizeof (node_t) );
	head->id = id;
	head->next = 0;
	return head;
}

int
insert_node_at_start(int id, head_t **head)
{
	node_t* p_new_node = (node_t*) malloc( sizeof(node_t) );
	p_new_node->next = *head;
	p_new_node->id = id;
	*head = p_new_node;
	return 0;
}

int
insert_node_at_end(int id, head_t *head)
{
	node_t *temp = head;
	node_t *p_new_node = (node_t*) malloc( sizeof(node_t) );

	p_new_node->id = id;

	while( temp->next )
	{
		temp = temp->next;
	}
	temp->next = p_new_node;
	return 0;
}
int
insert_node_sorted(int id, head_t **head)
{
	if( !check_head(*head) )
		return 0;

	node_t *pnode, *cnode;
	cnode = *head;
	pnode = 0;
	node_t *new_node = (node_t*) malloc(sizeof(node_t));
	new_node->id = id;

	while( id >= cnode->id )
	{
		pnode = cnode;
		cnode = cnode->next;
		if(!cnode)
		{
			pnode->next = new_node;
			new_node->next = 0;
			return 1;
		}
	}
	new_node->next = cnode;
	if(pnode)
	{
		pnode->next = new_node;
	}
	else
	{
		*head = new_node;
	}

	return 1;
}

int
delete_node_at_end(head_t *head)
{
	node_t* temp = head;

	while( ((node_t*)temp->next)->next )
	{
		temp = temp->next;
	}
	if(temp->next)
	{
		free(temp->next);
		temp->next = 0;
	}
	else
	{
		free(temp);
	}
	print_list(head);
	return 0;
}

int
delete_node_at_start(head_t **head)
{
	node_t* temp;
	if((*head)->next)
	{
		temp = (*head)->next;
		free(*head);
		*head = temp;
	}
	else
	{
		free(*head);
		*head = 0;
	}

	print_list(*head);
	return 0;
}
int
delete_node_by_id(head_t** head, int id)
{
	if( !check_head(*head) )
		return 0;

	node_t *cnode = *head;
	node_t *pnode = 0;

	while(cnode)
	{
		if(cnode->id == id)
		{
			if(pnode)
			{
				pnode->next = cnode->next;
				free(cnode);
			}
			else
			{
				*head = cnode->next;
				free(cnode);
			}
		}
		pnode = cnode;
		cnode = cnode->next;
	}
	return 1;
}

int
print_list(head_t *head)
{
	node_t* temp = head;
	printf("[ ");
	if(temp)
	{
		while( temp->next )
		{
			printf("%d ", temp->id);
			temp = temp->next;
		}
		printf("%d ", temp->id);
	}
	printf("]\n");
	return 0;
}

int
destroy_list(head_t **head)
{
	node_t* temp = *head;

	while( (*head)->next )
	{
		while( ( (node_t*) temp->next ) -> next )
		{
			temp = temp->next;
		}
		free( temp->next );
		temp->next = 0;
		temp = *head;
		print_list(*head);
	}
	free(*head);
	*head = 0;
	print_list( *head );
	return 0;
}

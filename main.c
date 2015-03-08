#include <stdio.h>
#include "linkedlist.h"
#include "randarray.h"

int main(void)
{
	int i;
	int *data = get_rand_array();
	head_t * head = create_list( *data );

	print_list(head);
	 
	for (i = 1; i < 10; i++)
	{
		insert_node_sorted( *(data+i), &head);
		print_list(head);
	}

	delete_node_by_id( &head, *(data+0) );

	printf("Printing after deleteing %d\n", *(data+0) );
	print_list(head);

	printf("Destroying list...\n");
	destroy_list(&head);

	return 0;
}

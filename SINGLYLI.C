void create(Node** head, int data)
{
    Node* newNode = createNode(data);
    if (*head == NULL)
    {
	*head = newNode;
    }
    else
    {
	Node* temp = *head;
	while (temp->next != NULL) {
	    temp = temp->next;
	}
	temp->next = newNode;
    }
    printf("Node with data %d created.\n", data);
}

void display(Node* head)
{    Node* temp=head;
    if (head == NULL) {
	printf("The linked list is empty.\n");
	return;
    }
    printf("Linked List: ");

    while (temp != NULL) {
	printf("%d -> ", temp->data);
	temp = temp->next;
    }
    printf("NULL\n");
}

void search(Node* head, int value) {
    Node* temp = head;
    int position = 1;
    while (temp != NULL) {
	if (temp->data == value) {
	    printf("Value %d found at position %d.\n", value, position);
	    return;
	}
	temp = temp->next;
	position++;
    }
    printf("Value %d not found in the linked list.\n", value);
}

void delete(Node** head, int value) {
    Node* temp = *head;
    Node* prev = NULL;

    if (temp != NULL && temp->data == value) {
	*head = temp->next;
	free(temp);
	printf("Node with value %d deleted.\n", value);
	return;
    }

    while (temp != NULL && temp->data != value) {
	prev = temp;
	temp = temp->next;
    }

    if (temp == NULL) {
	printf("Value %d not found in the linked list.\n", value);
	return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Node with value %d deleted.\n", value);
}

void concatenate(Node** head1, Node** head2) {
    if (*head1 == NULL) {
	*head1 = *head2;
    } else {
	Node* temp = *head1;
	while (temp->next != NULL) {
	    temp = temp->next;
	}
	temp->next = *head2;
    }
    *head2 = NULL;
    printf("Lists concatenated successfully.\n");
}

int main() {
    Node* list1 = NULL;
    Node* list2 = NULL;
    int choice, value;
    clrscr();

while(1)     {
        printf("\n--- Menu ---\n");
        printf("1. Create\n");
        printf("2. Display\n");
        printf("3. Search\n");
        printf("4. Concatenate\n");
        printf("5. Delete\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                create(&list1, value);
                break;

            case 2:
                display(list1);
                break;

            case 3:
                printf("Enter the value to search: ");
                scanf("%d", &value);
                search(list1, value);
                break;

            case 4:
                printf("Enter values for the second list (terminate with -1):\n");
                while (1) {
                    scanf("%d", &value);
                    if (value == -1) break;
                    create(&list2, value);
                }
                concatenate(&list1, &list2);
                break;

            case 5:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                delete(&list1, value);
                break;

            case 6:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

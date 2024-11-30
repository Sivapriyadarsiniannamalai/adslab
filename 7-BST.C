#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the binary search tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function for inserting a node in the binary search tree
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to find the minimum value node in the right subtree
struct Node* findMin(struct Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a node in the binary search tree
struct Node* delete(struct Node* root, int data) {
  struct Node* temp = findMin(root->right);
       if (root == NULL) {
	printf("Node not found.\n");
	return root;
    }

    if (data < root->data) {
	root->left = delete(root->left, data);
    } else if (data > root->data) {
	root->right = delete(root->right, data);
    } else {
	// Node with one or no child
	if (root->left == NULL) {
	    struct Node* temp = root->right;
	    free(root);
	    return temp;
	} else if (root->right == NULL) {
	    struct Node* temp = root->left;
	    free(root);
	    return temp;
	}

	// Node with two children
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    return root;
}

// Function to search a node in the binary search tree
int search(struct Node* root, int key) {
    if (root == NULL) {
        return 0;
    }
    if (root->data == key) {
        return 1;
    } else if (key < root->data) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

// Function to print the tree structure (in-order traversal)
void display(struct Node* root, int space) {
    int i;
    if (root == NULL) {
	return;
    }
    space += 10;
    display(root->right, space);
    printf("\n");
    for (i = 10; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);
    display(root->left, space);
}

// Main function to interact with the user and perform operations
int main() {
    struct Node* root = NULL;
    int choice, data;

    do {
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display Tree\n");
        printf("4. Search\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                printf("Node inserted successfully.\n");
                break;

            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                root = delete(root, data);
                printf("Node deleted successfully.\n");
                break;

            case 3:
                printf("Displaying the tree:\n");
                display(root, 0);
                break;

            case 4:
                printf("Enter data to search: ");
                scanf("%d", &data);
                if (search(root, data)) {
                    printf("Node found in the tree.\n");
                } else {
                    printf("Node not found in the tree.\n");
                }
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

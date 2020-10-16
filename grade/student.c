/* student.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <search.h>

/* structure declaration */
typedef struct student {
	char name[10];
	int mid;
	int final;
} Student;

typedef struct NODE {
	struct student stu;
	struct NODE* left;
	struct NODE* right;
} Node;

Node* pr;

/* function declaration */
Node* init_tree();
void input_data(Node** root, struct student stu);
void indorder_traverse(Node* root);
void print_tree(Node* root);


/* main */

int main() {
	int stu_num, i;
	struct student* stu_ptr;

	printf("input student number : ");
	scanf("%d", &stu_num);

	/* memory allocation */
	stu_ptr = (struct student*) malloc(stu_num * sizeof(struct student));
	
	/* failed memory allocation */
	if (stu_ptr == NULL) {
		printf("failed memory allocation\n");
		exit(-1);
	}

	Node* root = NULL;
	Node* tmp;

	for (i = 0; i < stu_num; i++) {
		printf("%d | student's name : ", i + 1);
		scanf("%s", stu_ptr[i].name);	getchar();
		printf("%d | student's mid & final grad : ", i + 1);
		scanf("%d %d", &stu_ptr[i].mid, &stu_ptr[i].final);	getchar();

		printf("## main func. %s %d %d\n", stu_ptr[i].name, stu_ptr[i].mid, stu_ptr[i].final);
		input_data(&root, stu_ptr[i]);
	}

	print_tree(root);
	free(stu_ptr);
	free(pr);
	free(root);
	free(tmp);
}

/* functions */

Node* init_tree() {
	Node* tr = (Node*)malloc(sizeof(Node));

	tr->left = NULL;
	tr->right = NULL;

	return tr;
}

void input_data(Node** root, struct student stu) {
	Node* rtmp;
	Node* tmp = init_tree();
	Node* cur = *root;

	tmp->stu = stu;

	if (*root == NULL)	*root = tmp;
	else {
		printf("## input data func. root: %s| cur: %s| stu: %s\n", (*root)->stu.name, cur->stu.name, stu.name);
		if (strcmp((*root)->stu.name, stu.name) > 0) {
			if ((*root)->left == NULL)	(*root)->left = tmp;
			else {
				rtmp = (*root)->left;
				input_data(&rtmp, stu);
			}
		}
		else if (strcmp(cur->stu.name, stu.name) < 0) {
			if (cur->right == NULL)	cur->right = tmp;
			else {
				rtmp = cur->right;
				input_data(&rtmp, stu);
			}
		}
		else	printf("The data is already in Tree.\n");
	}
}

void inorder_traverse(Node* root) {
	if (root) {
		inorder_traverse(root->left);

		printf("name : %s | mid : %d |  final : %d\n", root->stu.name, root->stu.mid, root->stu.final);

		inorder_traverse(root->right);
	}
}

void print_tree(Node* root) {
	printf("=== print tree ===\n");
	inorder_traverse(root);
	printf("\n=== printf complete ===\n");
}

#include "stdio.h"
#include "malloc.h"
#include "seqstack.h"

/*根据前序遍历创建一颗给定的二叉树*/
bintree createbintree() {
	char ch;
	bintree t;
	if ((ch = getchar()) == '#') {
		t = NULL;
	}
	else {
		t = (bintnode*)malloc(sizeof(bintnode));
		if (t) {
			t->data = ch;
			t->lchild = createbintree();
			t->rchild = createbintree();
		}
	}
	return t;
}

void preorder1(bintree t) {    /*二叉树前序遍历的非递归实现*/
	seqstack s;
	s.top = 0;
	while ((t) || (s.top != 0)) {   /*处理的子树不能为空或者栈不为空栈*/
		if (t) {
			printf("%c ", t->data);
			push(&s, t);
			t = t->lchild;
		}
		else {
			t = pop(&s);
			t = t->rchild;
		}
	}
}

void inorder(bintree t) {    /*二叉树中序遍历的非递归实现*/
	seqstack s;
	s.top = 0;
	while ((t != NULL) || (s.top != 0)) {
		if (t) {
			push(&s, t);
			t = t->lchild;
		}
		else {
			t = pop(&s);
			printf("%c ", t->data);
			t = t->rchild;
		}
	}
}

void postorder(bintree t) {      /*二叉树后序遍历的非递归实现*/
	seqstack s;
	s.top = 0;
	while ((t) || (s.top != 0)) {
		if (t) {
			s.data[s.top] = t;
			s.tag[s.top] = 0;
			s.top++;
			t = t->lchild;
		}
		else {
			if (s.tag[s.top - 1] == 1) {
				s.top--;
				t = s.data[s.top];
				printf("%c ", t->data);
				t = NULL;
			}
			else {
				t = s.data[s.top - 1];
				s.tag[s.top - 1] = 1;
				t = t->rchild;
			}
		}
	}
}

int main() {
	bintree t;
	t = createbintree();
	preorder1(t);
	printf("\n");
	inorder(t);
	printf("\n");
	postorder(t);
}
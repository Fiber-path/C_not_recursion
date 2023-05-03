#pragma once
#include "bilink2.h"
typedef struct stack {
	bintree data[100];
	int tag[100];
	int top;
} seqstack;

void push(seqstack* s, bintree t) {
	s->data[s->top] = t;
	s->top++;
}

bintree pop(seqstack* s) {
	if (s->top != 0) {
		s->top--;
		return (s->data[s->top]);
	}
}
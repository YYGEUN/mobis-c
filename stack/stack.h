#ifndef stack_t_H_
#define stack_t_H_

typedef enum _bool { FALSE, TRUE } bool_t;

typedef struct _stack {
	int *stack;		/* ������ ������� ������ */
	int size;			/* ���� ũ�� */
	int top;			/* ������ ����� �������� */
} stack_t;

bool_t createStack(stack_t *sp, int size);	/* ���� �޸��Ҵ� �� ��� �ʱ�ȭ �Լ� */
bool_t isStackFull(stack_t *sp);			/* ������ �� �� �ִ��� �˻� */
bool_t isStackEmpty(stack_t *sp);			/* ������ ������ ����ִ��� �˻� */
bool_t push(stack_t *sp, int pushData);		/* ���ÿ� ������ �����ϴ� �Լ� */
bool_t pop(stack_t *sp, int *popData);		/* ���ÿ��� �����͸� ������ �Լ� */
/* ���� ���� ��� ������ ��� �Լ� */
void printStack(const stack_t* sp);
void destroyStack(stack_t *sp);				/* ���� �޸� ���� �Լ� */


#endif /* STACK_H_ */

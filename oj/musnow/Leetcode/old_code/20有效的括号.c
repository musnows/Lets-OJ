ar STDataType;
typedef struct Stack
{
	STDataType* a;
	int top; // 栈顶
	int capacity; // 容量
}Stack;

// 初始化
void StackInit(Stack* ps)
{
	STDataType* new = (STDataType*)malloc(sizeof(STDataType) * 4);
	if (new == NULL)
	{
		exit(-1);
	}
	else
	{
		ps->a = new;
		ps->top = 0;
		ps->capacity = 4;
	}
}

// 销毁栈
void StackDestroy(Stack* ps)
{
	assert(ps);

	free(ps->a);
	ps->a = NULL;

	ps->capacity = 0;
	ps->top = 0;
}

// 入栈
void StackPush(Stack* ps, STDataType data)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		STDataType* new = (STDataType*)realloc(ps->a, sizeof(STDataType) * (ps->capacity) * 2);
		if (new == NULL)
		{
			exit(-1);
		}
		else
		{
			ps->a = new;
			ps->capacity *= 2;
		}
	}
	ps->a[ps->top] = data;
	ps->top++;
}
// 出栈
void StackPop(Stack* ps)
{
	assert(ps);
	if (ps->top > 0)
		(ps->top)--;
}
// 获取栈顶元素
STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(ps->top > 0);
	return ps->a[ps->top - 1];

}
// 检测栈是否为空，如果为空返回true，如果不为空返回false
bool StackEmpty(Stack* ps)
{
	assert(ps);
	if (ps->top == 0)
		return true;
	else
		return false;
}

bool isValid(char * s){
    Stack st;
    StackInit(&st);

    while(*s)
    {
        if(*s=='{'||*s=='['||*s=='(')
        {
            StackPush(&st,*s);
            s++;
        }
        else
        {
            if(StackEmpty(&st))
            {
                return false;
            }

            char top=StackTop(&st);//取栈顶元素
            StackPop(&st);//把栈顶删除
            //如( { 这两个，取了栈顶{，就立马pop掉它

            if((*s=='}'&&top=='{')
            ||(*s==')'&&top=='(')
            ||(*s==']'&&top=='['))
            {
                s++;
            }
            else
            {
                StackDestroy(&st);

                return false;
            }

        }
    }
    bool ret=StackEmpty(&st);
    //如果为空，说明匹配完毕；非空说明还有剩下的左括号

    StackDestroy(&st);
    
    return ret;
}

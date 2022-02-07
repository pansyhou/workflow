typedef struct tskTaskControlBlock
{
	volatile StackType_t *pxTopOfStack; //任务堆栈栈顶
#if (portUSING_MPU_WRAPPERS == 1)
	xMPU_SETTINGSxMPUSettings; // MPU 相关设置
#endif
	ListItem_t xStateListItem;				  //状态列表项
	ListItem_t xEventListItem;				  //事件列表项
	UBaseType_t uxPriority;					  //任务优先级
	StackType_t *pxStack;					  //任务堆栈起始地址
	char pcTaskName[configMAX_TASK_NAME_LEN]; //任务名字
#if (portSTACK_GROWTH > 0)
	StackType_t *pxEndOfStack; //任务堆栈栈底
#endif
#if (portCRITICAL_NESTING_IN_TCB == 1)
	UBaseType_t uxCriticalNesting; //临界区嵌套深度
#endif
#if (configUSE_TRACE_FACILITY == 1) // trace 或到 debug 的时候用到
	UBaseType_t uxTCBNumber;
	UBaseType_t uxTaskNumber;
#endif
#if (configUSE_MUTEXES == 1)
	UBaseType_t uxBasePriority; //任务基础优先级,优先级反转的时候用到
	UBaseType_t uxMutexesHeld;	//任务获取到的互斥信号量个数
#endif
#if (configUSE_APPLICATION_TASK_TAG == 1)
	TaskHookFunction_t pxTaskTag;
#endif
#if (configNUM_THREAD_LOCAL_STORAGE_POINTERS > 0) //与本地存储有关
	void
		*pvThreadLocalStoragePointers[configNUM_THREAD_LOCAL_STORAGE_POINTERS];
#endif
#if (configGENERATE_RUN_TIME_STATS == 1)
	uint32_t ulRunTimeCounter; //用来记录任务运行总时间
#endif
#if (configUSE_NEWLIB_REENTRANT == 1)
	struct _reent xNewLib_reent; //定义一个 newlib 结构体变量
#endif
#if (configUSE_TASK_NOTIFICATIONS == 1) //任务通知相关变量
	volatile uint32_t ulNotifiedValue;	//任务通知值
	volatile uint8_t ucNotifyState;		//任务通知状态
#endif
#if (tskSTATIC_AND_DYNAMIC_ALLOCATION_POSSIBLE != 0)
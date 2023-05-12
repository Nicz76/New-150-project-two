#include <assert.h>
#include <signal.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include "private.h"
#include "uthread.h"
#include "queue.h"

struct uthread_tcb {
	int state;
	void *arg;
	//There are 4 states
	/* TODO Phase 2 */
	
};

struct uthread_tcb *uthread_current(void)
{
	/* TODO Phase 2/3 */
}

void uthread_yield(void)
{
	/* TODO Phase 2 */
}

void uthread_exit(void)
{
	/* TODO Phase 2 */
}

int uthread_create(uthread_func_t func, void *arg)
{
	/* TODO Phase 2 */
}

int uthread_run(bool preempt, uthread_func_t func, void *arg)
{
	func(*arg);
	/* TODO Phase 2 */
}

void uthread_block(void)
{
	lock();
	/* TODO Phase 3 */
}

void uthread_unblock(struct uthread_tcb *uthread)
{
	unlock();
	/* TODO Phase 3 */
}


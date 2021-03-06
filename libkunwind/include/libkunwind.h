#ifndef LIBKUNWIND_H
#define LIBKUNWIND_H

#include "kunwind.h"
#include "proc_info.h"

struct unwind_handle;

int init_unwind(struct unwind_handle **handlep);

int init_unwind_proc_info(struct unwind_handle **handlep,
			  struct proc_info *proc_info);

int unwind(struct unwind_handle *handle,
	   struct kunwind_backtrace* backtrace);

void release_handle(struct unwind_handle *handle);

#endif // LIBKUNWIND_H

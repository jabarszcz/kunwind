#ifndef _MODULES_H_
#define _MODULES_H_

#include <proc_info.h>
#include <kunwind.h>

#include "unwind/unwind.h"

struct kunwind_proc_modules {
	struct list_head stp_modules;
	int compat :1;
};

struct kunwind_stp_module {
	struct _stp_module stp_mod;
	struct list_head list;
	void *base;
	struct vm_area_struct *vma;
	unsigned long vma_start;
	unsigned long vma_end;
	struct page **pages;
	int npages;
};

int fill_eh_frame_info(struct kunwind_stp_module *mod,
		       struct kunwind_proc_modules *proc);

int fill_mod_path(struct kunwind_stp_module *mod);

int init_proc_unwind_info(struct kunwind_proc_modules *mods,
			  int compat);

int release_unwind_info(struct kunwind_proc_modules *mods);

int init_modules_from_task(struct task_struct *task,
			   struct kunwind_proc_modules *mods);

int init_modules_from_proc_info(struct proc_info *info,
				struct task_struct *task,
				struct kunwind_proc_modules *mods);

int do_current_unwind(struct kunwind_backtrace *bt,
		      struct kunwind_proc_modules *mods);

#endif // _MODULES_H_

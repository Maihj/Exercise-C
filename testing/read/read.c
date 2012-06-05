#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <asm/uaccess.h>
#include <linux/mm.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL");

/* the parameter */
static char *filename;
module_param(filename, charp, 0000);

void readfile(char *filename){
  struct file *filp;
  struct inode *inode;
  mm_segment_t fs;
  off_t fsize;
  char *buf;

  /* open the file */
  filp = filp_open(filename, O_RDONLY, 0);
  inode = filp -> f_dentry -> d_inode;

  printk("<1>Maximum size: %li\n", inode -> i_sb -> s_blocksize);
  fsize = inode -> i_size;
  printk("<1>File size:%i \n", (int)fsize);
  buf = (char *)kmalloc(fsize+1, GFP_ATOMIC);

  /* read file */
  fs = get_fs();
  set_fs(KERNEL_DS);
  filp -> f_op -> read(filp, buf, fsize, &(filp -> f_pos));
  set_fs(fs);

  buf[fsize] = '\0';
  printk("<1>File content:\n");
  printk("<1>%s", buf);

  /* close the file */
  filp_close(filp, NULL);
}

int init_module(){
    printk("<1>Start reading...\n");
    readfile(filename);
    printk("<1>Read finish.\n");
    return 0;
}

void cleanup_module(){
    printk("<1>Goodbye!\n");
}

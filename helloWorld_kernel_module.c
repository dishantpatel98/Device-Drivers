#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
MODULE_LICENSE("Dual BSD/GPL");//Special macro which is also function internally is used to tell the  kernel that this modulebears free licence
MODULE_AUTHOR("Dishant Patel");



static int load(void){
printk(KERN_ALERT"Hello,Your driver module is loaded in the kernel\n");//printk() function is defined in the linux  kernel and made available to modules,it behaves similarly
                                                                    //to the printf()..Kernel needs it own printing function because it cannot acess c library  
return 0;
}

static void remove(void){
printk(KERN_ALERT"Your driver is removed the kernel\n ");//The string KERN_ALERT is priority of the message.We have specified a high priority ,because a message with default
                                                         //priority might not  show up

}
module_init(load);  //The module_init() macro defines which function is to be called at module insertion time (if the file is compiled as a module), or at boot time:
module_exit(remove);//This macro defines the function to be called at module removal time (or never, in the case of the file compiled into the kernel). It will only be called if the module usage count has reached zero
//Both are basically functions only

#include<unistd.h>
#include<sys/types.h>
#include<linux/fcntl.h>
#include<pthread.h>





int f,b1,b2,ret1,ret2,ret3;
char buf1[32];
char buf2[32];
char buf3[32];

void *device1(int arr[]){


write(arr[0], "4", 1);
        write(arr[1], "5",1 );   //We need binary sys file to pass binary data.
        write(arr[2], "6", 1);


lseek(arr[0],0,SEEK_SET); //active files offset will be reset to zero
lseek(arr[1],0,SEEK_SET);
lseek(arr[2],0,SEEK_SET);





        ret1 = read(arr[0],buf1,sizeof(buf1));
   if(ret1<0) { perror("error in read"); exit(6); }
 //  printf(" Value of ret1 is %d\n",ret1);

   printf("The value of dev_param1 is %s\n", buf1);

  ret2 = read(arr[1],buf2,sizeof(buf2));
   if(ret1<0) { perror("error in read"); exit(6); }
   //printf(" Value of ret1 is %d\n",ret2);
   printf("The value of dev_param2 is %s\n", buf2);
ret3 = read(arr[2],buf3,sizeof(buf3));
   if(ret1<0) { perror("error in read"); exit(6); }


//printf(" Value of ret1 is %d\n",ret3);

   printf("The value of dev_param3 is %s\n", buf3);

return NULL;

}



int dev1[3];
int main()
{

  f= open("/sys/kernel/kset_devices_typeA/device0/dev_param1", O_RDWR);
   
   	//pdfd0  = open("/sys/bus/platform/devices/custom_leds/leds/led1", O_RDWR); 
   	//pdfd0  = open("/dev/pseudo0", O_RDWR|O_NONBLOCK); //device file accessed in non-blocking mode
   	if(f<0) { 
		perror("error in opening dev_param1"); 
		exit(1);
	}
   	dev1[0] = f;

	
	
	b1  = open("/sys/kernel/kset_devices_typeA/device0/dev_param2", O_RDWR); 
   
   	if(b1<0) { 
		perror("error in opening param2"); 
		exit(1);
	}
dev1[1] = b1;

   	b2  = open("/sys/kernel/kset_devices_typeA/device0/dev_param3", O_RDWR); 
   	
   	if(b2<0) { 
		perror("error in opening param3"); 
		exit(1);
       }		
	dev1[2] = b2;

	pthread_t thread_pid1;

	pthread_create(&thread_pid1,NULL,device1,dev1);

       
pthread_join(thread_pid1,NULL);

}

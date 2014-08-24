#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/joystick.h>

//#include <unistd.h>
//#include <sys/types.h>
//#include <sys/stat.h>

#define JOYSTICK_DEVNAME "/dev/input/js0"

static int joystick_fd = -1;
int stick1_x, stick1_y, stick2_x, stick2_y, buttons[12];

int open_joystick()
{
    joystick_fd = open(JOYSTICK_DEVNAME, O_RDONLY | O_NONBLOCK); /* read write for force feedback? */
    if (joystick_fd < 0)
	return joystick_fd;
    
    /* maybe ioctls to interrogate features here? */
    
    return joystick_fd;
}

int read_joystick_event(struct js_event *jse)
{
    int bytes;
    
    bytes = read(joystick_fd, jse, sizeof(*jse)); 
    
    if (bytes == -1)
	return 0;
    
    if (bytes == sizeof(*jse))
	return 1;
    
    printf("Unexpected bytes from joystick:%d\n", bytes);
    
    return -1;
}

void close_joystick()
{
    close(joystick_fd);
}

int get_joystick_status(void)
{
    int rc;
    struct js_event jse;
    if (joystick_fd < 0)
	return -1;
    
    while ((rc = read_joystick_event(&jse) == 1)) {
	jse.type &= ~JS_EVENT_INIT; /* ignore synthetic events */
	if (jse.type == JS_EVENT_AXIS) {
	    switch (jse.number) {
	    case 0: stick1_x = jse.value;
		break;
	    case 1: stick1_y = jse.value;
		break;
	    case 2: stick2_x = jse.value;
		break;
	    case 3: stick2_y = jse.value;
		break;
	    default:
		break;
	    }
	} else if (jse.type == JS_EVENT_BUTTON) {
	    if (jse.number < 10) {
		switch (jse.value) {
		case 0:
		case 1: buttons[jse.number] = jse.value;
		    break;
		default:
		    break;
		}
	    }
	}
    }
    // printf("%d\n", wjse->stick1_y);
    return 0;
}

#if 1
int main(int argc, char *argv[])
{
    int fd, rc;
    int done = 0;
    
    struct js_event jse;
    
    fd = open_joystick();
    if (fd < 0) {
	printf("open failed.\n");
	exit(1);
    }
    
    while (!done) {
	rc = read_joystick_event(&jse);
	usleep(1000);
	if (rc == 1) {
	    printf("Event: time %8u, value %8hd, type: %3u, axis/button: %u\n", 
		   jse.time, jse.value, jse.type, jse.number);
	}
    }
}
#endif
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/joystick.h>

//#include <unistd.h>
//#include <sys/types.h>
//#include <sys/stat.h>

static int joystick_fd = -1;

#define JOYSTICK_DEVNAME "/dev/input/js0"


int open_joystick()
{
    joystick_fd = open(JOYSTICK_DEVNAME, O_RDONLY | O_NONBLOCK);
 /* read write for force feedback? */
    if (joystick_fd < 0)
	return joystick_fd;
    
    /* maybe ioctls to interrogate features here? */
    
    return joystick_fd;
}

void close_joystick()
{
    close(joystick_fd);
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

/* Xbox360 wireless controller definitions
 * left hand axes 0, 1, 2
 * right hand axes 3, 4, 5
 * buttons A, B, X, Y --> 0, 1, 2, 3
 * left-right triggers --> 4, 5
 * back-start-onoff buttons --> 6, 7, 8
 * left-right stick buttons --> 9, 10
 * left-right-up-down gamepad --> 11, 12, 13, 14.
 */
typedef struct {
    int axis[6];
    int button[16];
} XBOX_STATE;

XBOX_STATE xbox_now, xbox_old;
int stick1_x, stick1_y, stick1_z, stick2_x, stick2_y, stick2_z, buttons[15];

int get_joystick_status(struct js_event *jse)
{
    int rc;
    /* struct js_event jse; */
    if (joystick_fd < 0)
	return -1;
    
    if ((rc = read_joystick_event(jse) == 1)) {
	jse->type &= ~JS_EVENT_INIT; /* ignore synthetic events */

	if (jse->type == JS_EVENT_AXIS) {
	    if (jse->number < 6) {
		xbox_now.axis[jse->number] = jse->value;
		return 1;
	    }
	} else if (jse->type == JS_EVENT_BUTTON) {
	    if (jse->number < 15) {
		xbox_now.button[jse->number] = jse->value;
		return 1;
	    }
	}

	if (jse->type == JS_EVENT_AXIS) {
	    
	    switch (jse->number) {
	    case 0: stick1_x = jse->value;
		break;
	    case 1: stick1_y = jse->value;
		break;
	    case 2: stick1_z = jse->value;
		break;
	    case 3: stick2_x = jse->value;
		break;
	    case 4: stick2_y = jse->value;
		break;
	    case 5: stick2_z = jse->value;
		break;
	    default:
		break;
	    }
	} else if (jse->type == JS_EVENT_BUTTON) {
	    
	    if (jse->number < 15) {
		switch (jse->value) {
		case 0:
		case 1: buttons[jse->number] = jse->value;
		    break;
		default:
		    break;
		}
	    }
	}
    }

    return 0;
}

#ifdef TESTING
int main(int argc, char *argv[])
{
    int fd, rc;
    int done = 0;
    int i;
    
    struct js_event jse;
    
    fd = open_joystick();
    if (fd < 0) {
	printf("open failed.\n");
	exit(1);
    }
    
    while (!done) {


#if 0
	rc = read_joystick_event(&jse);
	if (rc == 1) {
	    printf("Event: time %8u, type: %3u, axis/button: %u, value %8hd\n", 
		   jse.time, jse.type, jse.number, jse.value);
	}

#endif

	get_joystick_status(&jse);
	printf("Lx:%8hd, Ly: %8hd, Rx: %8hd, Ry: %8hd ",
	       xbox_now.axis[0], xbox_now.axis[1],
	       xbox_now.axis[3], xbox_now.axis[4]);
	for (i = 0; i < 15; i++)
	    printf("%d", xbox_now.button[i] ? 1 : 0);
	printf("\n");

	
	usleep(10000);
    }
}
#endif

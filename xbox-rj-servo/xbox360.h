#ifndef __xbox360_h__
#define __xbox360__h__

#include <linux/joystick.h>

typedef struct {
    int axis[6];
    int button[16];
} XBOX_STATE;

extern XBOX_STATE xbox_now, xbox_old;
extern int stick1_x, stick1_y, stick1_z, stick2_x, stick2_y, stick2_z, buttons[15];

int open_joystick(void);
void close_joystick(void);
int read_joystick_event(struct js_event *jse);
int get_joystick_status(struct js_event *jse);

#endif /* __xbox360_h__ */b

#ifndef _GENERIC_SENSORS_H
#define _GENERIC_SENSORS_H

#include "libsensorhub.h"
#include "message.h"

#define USAGE_SENSOR_PROPERTY_POWER_STATE_D0_FULL_POWER_ENUM            0x02
#define USAGE_SENSOR_PROPERTY_POWER_STATE_D1_LOW_POWER_ENUM             0x03

#define USAGE_SENSOR_PROPERTY_REPORTING_STATE_NO_EVENTS_ENUM            0x01
#define USAGE_SENSOR_PROPERTY_REPORTING_STATE_ALL_EVENTS_ENUM           0x02
#define USAGE_SENSOR_PROPERTY_REPORTING_STATE_ALL_EVENTS_WAKE_ENUM      0x05

#define USAGE_SENSOR_DATA_MOTION_STATE                                  0x200451
#define USAGE_SENSOR_DATA_MOTION_ACCELERATION_X_AXIS                    0x200453
#define USAGE_SENSOR_DATA_MOTION_ACCELERATION_Y_AXIS                    0x200454
#define USAGE_SENSOR_DATA_MOTION_ACCELERATION_Z_AXIS                    0x200455

#define USAGE_SENSOR_DATA_MOTION_GYROMETER_X_AXIS                       0x200457
#define USAGE_SENSOR_DATA_MOTION_GYROMETER_Y_AXIS                       0x200458
#define USAGE_SENSOR_DATA_MOTION_GYROMETER_Z_AXIS                       0x200459

#define USAGE_SENSOR_DATA_ORIENTATION_COMPENSATED_MAGNETIC_NORTH        0x200475

#define USAGE_SENSOR_DATA_ORIENTATION_TILT_X                            0x20047F
#define USAGE_SENSOR_DATA_ORIENTATION_TILT_Y                            0x200480
#define USAGE_SENSOR_DATA_ORIENTATION_TILT_Z                            0x200481

#define USAGE_SENSOR_DATA_ORIENTATION_QUATERNION                        0x200483

#define USAGE_SENSOR_DATA_ORIENTATION_MAGNETIC_FLUX_X_AXIS              0x200485
#define USAGE_SENSOR_DATA_ORIENTATION_MAGNETIC_FLUX_Y_AXIS              0x200486
#define USAGE_SENSOR_DATA_ORIENTATION_MAGNETIC_FLUX_Z_AXIS              0x200487
#define USAGE_SENSOR_DATE_ORIENTATION_MAGNETIC_ACCURACY                 0x200488

#define USAGE_SENSOR_DATA_ENVIRONMENT_ATMOSPHERIC_PRESSURE              0x200431

#define USAGE_SENSOR_DATA_BIOMETRIC_HUMANCE_PRESENCE                    0x2004B1

#define USAGE_SENSOR_DATA_LIGHT_ILLUMINANCE                             0x2004D1

#define USAGE_SENSOR_DATA_CUSTOM_VALUE_1                                0x200544
#define USAGE_SENSOR_DATA_CUSTOM_VALUE_2                                0x200545
#define USAGE_SENSOR_DATA_CUSTOM_VALUE_3                                0x200546
#define USAGE_SENSOR_DATA_CUSTOM_VALUE_4                                0x200547
#define USAGE_SENSOR_DATA_CUSTOM_VALUE_5                                0x200548
#define USAGE_SENSOR_DATA_CUSTOM_VALUE_6                                0x200549
#define USAGE_SENSOR_DATA_CUSTOM_VALUE_7                                0x20054A
#define USAGE_SENSOR_DATA_CUSTOM_VALUE_8                                0x20054B
#define USAGE_SENSOR_DATA_CUSTOM_VALUE_9                                0x20054C
#define USAGE_SENSOR_DATA_CUSTOM_VALUE_10                               0x20054D
#define USAGE_SENSOR_DATA_CUSTOM_VALUE_11                               0x20054E
#define USAGE_SENSOR_DATA_CUSTOM_VALUE_12                               0x20054F
#define USAGE_SENSOR_DATA_CUSTOM_VALUE_13                               0x200550
#define USAGE_SENSOR_DATA_CUSTOM_VALUE_14                               0x200551
#define USAGE_SENSOR_DATA_CUSTOM_VALUE_27                               0x20055E
#define USAGE_SENSOR_DATA_CUSTOM_VALUE_28                               0x20055F

typedef struct {
        unsigned int usage_id;                     // This data field's hid usage_id
        unsigned int index;                        // This data field's index in sensor sample data
        unsigned int length;                       // This data field's value length
        unsigned int offset;                       // this data field's offset in sensor sample data
        unsigned int exposed;                      // If this data field can be exposed to sensor client
        unsigned int exposed_offset;               // This data field's offset in exposed sensor data struct
} datafield_map_t;

#define FRI_NAME_MAX_LEN           50
#define MAX_DATA_FIELD             15
#define PRIVATE_PROPERTY_MAX_COUNT 16
#define PRIVATE_PROPERTY_BITMASK   0xFFFF
#define PRIVATE_PROPERTY_MINIMUM   0xF000
typedef struct {
        char friend_name[FRI_NAME_MAX_LEN + 1];           // Sensor's name or usage id
        unsigned int serial_num[2];                       // Sensor's serial number
        unsigned int connect_type;                        // Sensor's connection tpye
        datafield_map_t data_field[MAX_DATA_FIELD];       // Sensor's data field information
        unsigned char installed;                          // Flag if sensor is installed to sensorhubd
        unsigned int private_property_usage_ids[PRIVATE_PROPERTY_MAX_COUNT]; // 0 for the end
} generic_sensor_info_t;

#define INSTALL_WAKEUP            (1 << 0)
#define INSTALL_NON_WAKEUP        (1 << 1)

int init_generic_sensors(void *p_sensor_list, unsigned int *index);
int generic_sensor_send_cmd(struct cmd_send *cmd);
int add_generic_sensor_fds(int maxfd, void *read_fds, int *hw_fds, int *hw_fds_num);
int process_generic_sensor_fd(int fd);

#endif
